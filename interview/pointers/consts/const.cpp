static char str[] = "hello";

int main() {
	char* const s1  = str;			// s1 - constant pointer (line 8), but not content (line 7)
	const char* s2  = "hello2";		// s2 - constant content (line 9), but not pointer (line 10)
	const char* s21 = "hello21";	//
	const char* const s3 = "hello3";// s3 - constant content & pointer (lines 11-12)

	s1[0] = 'H';
	// s1 = s2;     // error: assignment of read-only variable 's1'
	// s2[0] = 'H'; // error: assignment of read-only location '* s2'
	s2 = s21;
	// s3[0] = 'H'; //  error: assignment of read-only location '*(const char*)s3'
	// s3 = s2;     // error: assignment of read-only variable 's3'

	return 0;
}
