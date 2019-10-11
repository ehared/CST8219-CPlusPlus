/************************************************************************************************************************
	Filename:			Frame.cpp
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
	Purpose:			To construct and initialize all variables of a Frame.
************************************************************************************************************************/
#include <iostream>
#include "Frame.h"
#include <crtdbg.h>

using namespace std;
/************************************************************************************************************************
	Function Name:				Frame()
	Purpose:					To construct a Frame and initialize all its variables.
	FunctionIn Parameters:		n/a
	Function Out Parameters:	Frame
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
Frame::Frame() {
	/* initialize variables to null */
	frameName = NULL;
	pNext = NULL;
}
/************************************************************************************************************************
	Function Name:				~Frame()
	Purpose:					To deallocate all memeory allocated by a Frame
	Function In Parameters:		N/A
	Function Out Parameters:	N/A
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
Frame::~Frame() {
	/* deallocate memory of frameName */
	delete this->frameName;
	/* set pointer to NULL to avoid dangling pointer */
	this->pNext = NULL;
}