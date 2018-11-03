#include <iostream>
#include <Windows.h>
#include <winuser.h>

#include <conio.h>
DWORD pID;
DWORD adress = 0x0083Af50;
DWORD time = 0x03186DBC;
DWORD wfrAdd = 0x00705CA8;
DWORD cBAdd = 0x00705CAC;
float ngl_org;
int wframe = 0;
int cBoxes = 0;
int main()
{
	HWND hwnd = FindWindowA (0, ("Bionicle"));
	if (!hwnd) std::cerr << "TLoMN not found" << std::endl;
	GetWindowThreadProcessId(hwnd, &pID);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
	if (!pHandle) std::cerr << "ERROR" << std::endl;
	while(true) {
		ReadProcessMemory(pHandle, (LPVOID)wfrAdd, &wframe, (DWORD)sizeof(wframe), 0);
		ReadProcessMemory(pHandle, (LPVOID)cBAdd, &cBoxes, (DWORD)sizeof(cBoxes), 0);
		if(GetAsyncKeyState('G')) {
			switch(wframe) {
				case 0: {
					wframe = 1;
					std::cout << "Wireframe: ON\n";
					WriteProcessMemory(pHandle, (LPVOID)wfrAdd, &wframe, (DWORD)sizeof(wframe), 0);
					break;
				}
				case 1: {
					wframe = 0;
					std::cout << "Wireframe: OFF\n";
					WriteProcessMemory(pHandle, (LPVOID)wfrAdd, &wframe, (DWORD)sizeof(wframe), 0);
					break;
				}
			}
		}
		if(GetAsyncKeyState('B')) {
			switch(cBoxes) {
				case 0: {
					cBoxes = 1;
					std::cout << "Collision Boxes: ON\n";
					WriteProcessMemory(pHandle, (LPVOID)cBAdd, &cBoxes, (DWORD)sizeof(cBoxes), 0);
					break;
				}
				case 1: {
					cBoxes = 0;
					std::cout << "Collision Boxes: OFF\n";
					WriteProcessMemory(pHandle, (LPVOID)cBAdd, &cBoxes, (DWORD)sizeof(cBoxes), 0);
					break;
				}
			}
		}
		
	}

    return 1;
}
