#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "hello.h"

/* Function signature of the function exported from the DLL. */
typedef int (__cdecl *AddFunc)(int a, int b);

int main(int argc, char** argv)
{
	HMODULE hAddLib;
	AddFunc Add;

	// printf("Sub(1,2) = %d \n", Sub(1,2));

	/* Attempt to load the DLL into the process's address space. */
	if (! (hAddLib = LoadLibrary(TEXT("libhello.dll"))))
	{
		fprintf(stderr, "Error loading \"libhello.dll\".\n");
		return EXIT_FAILURE;
	}

	/* Print the address that the DLL was loaded at. */
	printf("Library is loaded at address %p.\n", hAddLib);

	/* Attempt to get the memory address of the "Add()" function. */
	if (! (Add = (AddFunc) GetProcAddress(hAddLib, "Add")))
	{
		fprintf(stderr, "Error locating \"Add\" function.\n");
		return EXIT_FAILURE;
	}

	/* Print the address of the "Add()" function. */
	printf("Add function is located at address %p.\n", Add);

	/* Call the function and display the results. */
	printf("7 + 41 = %d\n", Add(7, 41));

	/* Unload the DLL. */
	FreeLibrary(hAddLib);

	return EXIT_SUCCESS;
}