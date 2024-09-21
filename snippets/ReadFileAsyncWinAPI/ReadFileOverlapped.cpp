/*
	Win32 Overlapped I/O - Completion routines or WaitForMultipleObjects
		https://stackoverflow.com/questions/754068/win32-overlapped-i-o-completion-routines-or-waitformultipleobjects
	IOCP and ReadFileEx usage (IOCP = Input/output completion port)
		https://stackoverflow.com/questions/9683441/iocp-and-readfileex-usage

	WinAPI MSDN Docs:
	ReadFile		https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile
	OVERLAPPED 		https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-overlapped
	APC				https://learn.microsoft.com/en-us/windows/win32/sync/asynchronous-procedure-calls
	CreateIoCompletionPort		https://learn.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-createiocompletionport
	GetQueuedCompletionStatus	https://learn.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus
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
void printErrMsg(const char* const tag, DWORD errCode = NO_ERROR) {
	if (errCode == NO_ERROR) {
		errCode = GetLastError();
	}
	printf("ERROR(%s): errCode=%lu(0x%x)", tag, errCode, errCode);
	LPTSTR errText = NULL;
	FormatMessage( // https://stackoverflow.com/questions/455434/how-should-i-use-formatmessage-properly-in-c
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&errText,
		0,
		NULL
	);
	if (errText != NULL) {
		printf("\n\terrText=%s", errText);
		LocalFree(errText);
	}
	else {
		printf("\n");
	}
}
// HELPERS | END


#define BUFSIZE 4096

static unsigned long long cnt = 0;


int main() {
	printCurrentThread("main");

	HANDLE main_io; // created to associate this thread with possibly multiple file handles
	main_io = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (main_io == NULL) {
		printErrMsg("CreateIoCompletionPort main_io");
		return 0;
	}

	HANDLE hFile = CreateFileA(
		"../../file1.txt",
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
		NULL
	);
	if (hFile == INVALID_HANDLE_VALUE) {
		printErrMsg("CreateFileA");
		return 1;
	}

	HANDLE file_i;
	ULONG_PTR data = NULL;
	file_i = CreateIoCompletionPort(hFile, main_io, data, 0); // associate this thread with a created file handle
	if (file_i == NULL) {
		printErrMsg("CreateIoCompletionPort file_i");
		CloseHandle(hFile);
		return 0;
	}

	char buff[BUFSIZE] = {0};
	OVERLAPPED overlapped{};
	memset(&overlapped, 0, sizeof(overlapped));
	DWORD numBytesActuallyRead = 0;
	LPOVERLAPPED pOverlapped = &overlapped;
	BOOL readRes = ReadFile(
		hFile,
		(LPVOID)buff,
		BUFSIZE*sizeof(TCHAR),
		&numBytesActuallyRead,
		pOverlapped
	);
	if (readRes == 0) {
		DWORD errCode = GetLastError();
		if (errCode != ERROR_IO_PENDING) {
			printErrMsg("ReadFile", errCode);
			CloseHandle(hFile);
			return 2;
		}
		else {
			printf("read operation is pending completion asynchronously\n");
		}
	}

	BOOL isCompleted = FALSE;
	while (!isCompleted) {
		cnt++;
		isCompleted = GetQueuedCompletionStatus(
			file_i,
			&numBytesActuallyRead,
			&data,
			&pOverlapped,
			0 // exit immediately if no completed items in queue
		);
		if (!isCompleted) {
			printErrMsg("GetQueuedCompletionStatus !isCompleted");
		}
	}

	printCurrentThread("main");
	printf("readRes=%d cnt=%llu\n", readRes, cnt);
	printf("text='%s'\n", buff);

	CloseHandle(hFile);
	return 0;
}
