#include "stdio.h"
#include "string.h"
#include "Windows.h"

int main() {
	SetConsoleTitle(L"Process ID finder by Sleepybios"); // remove this i dont fucking care

	printf("**************************** \n");
	printf("     Proccess ID finder      \n");
	printf("     by      Sleepybios      \n");
	printf("**************************** \n \n");

	LPCSTR procName;
	char input[100]; // this dogshit didn't work so i needed chatgpt to give me this chat shit, in your program just use the getwindowthread and handletowindow.

	printf("Please insert WINDOW title: ");
	scanf_s("%99[^\n]", input, sizeof(input));

	procName = input;
	HWND handle_to_window = FindWindowA(NULL, procName); // NULL bc we don't know window type lmao
	if (handle_to_window != 0) {
		DWORD dw_process_id;
		GetWindowThreadProcessId(handle_to_window, &dw_process_id);

		printf("The process ID is: %u", dw_process_id);
	}
	else {
		printf("\nAre you sure that you properly inputted the ProcessID?");
	}

	printf("\nPress anything to exit...");
	getchar();
	return 0;
}
