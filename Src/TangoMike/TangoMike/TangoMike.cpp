// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "stdafx.h"
#include "TangoMike.h"
#include "Relationship.h"
#include "EasyServer.h"
#include "XMLBackup.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <shellapi.h>

/******************************************************************
*                                                                 *
*  WinMain                                                        *
*                                                                 *
*  Application entrypoint                                         *
*                                                                 *
******************************************************************/

void DevConsoleCreate();
int WINAPI WinMain( 
	HINSTANCE /* hInstance */,
	HINSTANCE /* hPrevInstance */,
	LPSTR /* lpCmdLine */,
	int /* nCmdShow */
	)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	EasyServer::GetInstance();
	//DevConsoleCreate();
	//ShellExecute(NULL, L"open", L"C:\\Users\\Administrator\\Documents\\TangoMike\\Src\\TangoMike\\Release\\TangoMike.exe", NULL, NULL, SW_SHOWNORMAL);

	std::srand(unsigned(std::time(0)));
	// Ignoring the return value because we want to continue running even in the
	// unlikely event that HeapSetInformation fails.
	//HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	if (SUCCEEDED(CoInitialize(NULL)))
	{
		{

			XMLBackup::GetInstance()->LoadData();
			Application app;
			Relationship::GetInstance()->LoadDataFromXMLBackup();
			if (SUCCEEDED(app.Initialize()))
			{
				app.RunMessageLoop();
			}
		}
		CoUninitialize();
	}
	Relationship::FreeInstance();
	XMLBackup::FreeInstance();
	EasyServer::FreeInstance();
	return 0;
}
void DevConsoleCreate(){

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	int consoleHandleR, consoleHandleW;
	long stdioHandle;
	FILE *fptr;

	AllocConsole();
	std::wstring strW = L"Dev Console";
	SetConsoleTitle(strW.c_str());

	EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED);
	DrawMenuBar(GetConsoleWindow());

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
	
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);


}