#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv) {
	
	if (argc != 2) {
		wprintf(L"usage: %S <errorcode>", argv[0]);
		return 1;
	}

	DWORD errorCode = (DWORD)atoi(argv[1]);

	if (errorCode == 0) {
		wprintf(L"Bad Errorcode: %S", argv[1]);
		return 1;
	}

	LPWSTR message = NULL;
	DWORD charsWritten = FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorCode, NULL, (LPWSTR)&message, NULL, NULL
	);
	
	if (charsWritten = NULL) {
		wprintf(L"Lookup for Error Code: \"%d\" failed.", errorCode);
		return 1;
	}
	
	wprintf(message);
	return 0;
}

