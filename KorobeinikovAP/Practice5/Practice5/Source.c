#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // для int64_t
#include <inttypes.h> // для правильного вывода int64_t в printf

#ifdef _WIN32

// без этих двух строк не скомпилируется
// при использовании функции GetFileSizeEx()
#define WINVER 0x0501
#define _WIN32_WINNT WINVER

#include <windows.h>
#include <sys\stat.h>
#endif

int64_t getFileSize(const char* file_name) {
	int64_t _file_size = 0;
	HANDLE hFile;
	hFile = CreateFile(TEXT(file_name), GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		_file_size = -1;
	}
	else {
		LARGE_INTEGER u_winFsz;
		GetFileSizeEx(hFile, &u_winFsz);
		CloseHandle(hFile);
		_file_size = u_winFsz.QuadPart;
	}
	return _file_size;
}

#define FILE_PATH "some_file.txt"

int main() {
	int64_t file_size = getFileSize(FILE_PATH);
	printf("File size: %" PRId64 "\n", file_size);

	return 0;
}