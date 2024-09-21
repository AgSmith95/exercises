/*	see - https://gist.github.com/ianfun/89f269c11bf516597a69809fcb77c295
	This is a "BAD" approach: (see https://stackoverflow.com/a/755074/5202246)
		... you can pass a completion routine which is called when completion occurs. 
		This is known as 'alertable I/O' and requires that the thread that issued the WSARecv() call is in an 'alertable' state for the completion routine to be called.
		Threads can put themselves in an alertable state in several ways (calling SleepEx() or the various EX versions of the Wait functions, etc). 
		The Richter book that I have open in front of me says "I have worked with alertable I/O quite a bit, and I'll be the first to tell you that alertable I/O is horrible and should be avoided". Enough said IMHO.
		...
*/

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "Windows.h"

#include <stdio.h>
#include <string.h>

#include <thread>
#include <sstream>

// HELPERS | START
void printCurrentThread(const char* const tag = "") {
	std::ostringstream oss;
	if (tag[0]) oss << tag << ": ";
	oss << "current_thread ID = " << std::this_thread::get_id();
	printf("%s\n", oss.str().c_str());
}
// HELPERS | END


#define BUFSIZE 4096

static unsigned long long cnt = 0;


VOID WINAPI ReadRoutineCompleted(
	DWORD dwErrorCode,
	DWORD dwNumberOfBytesTransfered,
	LPOVERLAPPED lpOverlapped
) {
	printCurrentThread("ReadRoutineCompleted");
	printf("Async ReadFile finished with errCode=%lu(0x%x), bytesRead=%lu\n", dwErrorCode, dwErrorCode, dwNumberOfBytesTransfered);
	printf("current cnt=%llu\n", cnt);
	cnt = 0;
}


int main() {
	printCurrentThread("main");

	HANDLE hFile = CreateFileA(
		"../../file.txt",
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
		NULL
	);
	if (hFile == INVALID_HANDLE_VALUE) {
		DWORD errCode = GetLastError();
		printf("ERROR: CreateFileA errCode=%lu(0x%x)", errCode, errCode);
		return 1;
	}

	char buff[BUFSIZE] = {0};
	OVERLAPPED overlapped{};
	memset(&overlapped, 0, sizeof(overlapped));
	BOOL readRes = ReadFileEx(
		hFile,
		(LPVOID)buff,
		20*sizeof(TCHAR), // read first 20 bytes
		(LPOVERLAPPED) &overlapped,
		ReadRoutineCompleted
	);
	if (readRes == 0) {
		DWORD errCode = GetLastError();
		printf("ERROR: ReadFileEx errCode=%lu(0x%x)", errCode, errCode);
		CloseHandle(hFile);
		return 1;
	}

	cnt = 123456789;
	SleepEx(INFINITE, TRUE); // need alertable wait to call async procedure, such as WSAaccept and SleepEx

	printCurrentThread("main");
	printf("readRes=%d cnt=%llu\n", readRes, cnt);
	printf("text='%s'\n", buff);

	CloseHandle(hFile);
	return 0;
}
