/************************************************************************************************************************
	Filename:			ass1.cpp
	Version:			1.0
	Student Name:		Eltire 'Mahad' Hared
	Student #:			040911519
	Course:				CST8219 C++ Programming Section: 310
	Lab Section:		313
	Assignment:			1
	Assignment Name:	Animation Project in C++
	Due Date:			October 12, 2019
	Submission Date:	October 12, 2019
	Professor:			Mohamed Abouseif
	Lab Instructor:		Muhammad Arshad
	Purpose:			Create a simple C++ Language console application that holds the data of an animation application
						using a linked list in dynamic memory.
************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC//need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
// in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <iostream>
using namespace std;
#include "Frame.h"

#include "Animation.h"
/************************************************************************************************************************
	Function name: main
	Purpose: main function
				- Calls various functions based on user input to construct an Animation(Linked List)
	Function InParameters: none
	Funcstion OutParameters: int - 0 for successful execution
	Version: 1.0
	Author: Eltire Hared
*************************************************************************************************************************/
int main(void) {
	char response;
	bool RUNNING = true;
	Animation A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (RUNNING) {
		cout << "MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit" << endl;
		cin >> response;
		switch (response) {
		case '1':A.InsertFrame(); break;
		case '2':A.DeleteFrame(); break;
		case '3':A.EditFrame(); break;
		case '4':A.ReportAnimation(); break;
		case '5':RUNNING = false; break;
		default:cout << "Please enter a valid option" << endl;
		}
	}
	return 0;
}