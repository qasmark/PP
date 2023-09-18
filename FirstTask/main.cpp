#include <windows.h>
#include <string>
#include <iostream>

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{

	std::cout << std::to_string((int) lpParam) + "\n";
	//std::cout << std::to_string((int)lpParam) + "\n";

	ExitThread(0); 
}

int main()
{
	int N;
	std::cin >> N;

	HANDLE* handles = new HANDLE[N];

	for (int i = 0; i < N; i++)
	{
		//int* threadIndex = new int(i);
		//handles[i] = CreateThread(NULL, 0, &ThreadProc, LPVOID(threadIndex), CREATE_SUSPENDED, NULL);

		handles[i] = CreateThread(NULL, 0, &ThreadProc, LPVOID(i), CREATE_SUSPENDED, NULL);
	}

	for (int j = 0; j < N; j++)
	{
		ResumeThread(handles[j]);
	}

	WaitForMultipleObjects(N, handles, true, INFINITE);


	return 0;
}