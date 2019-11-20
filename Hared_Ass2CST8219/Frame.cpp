/************************************************************************************************************************
	Filename:			Frame.cpp
	Version:			1.0
	Student Name:		Eltire 'Mahad' Hared
	Student #:			040911519
	Course:				CST8219 C++ Programming Section: 310
	Lab Section:		313
	Assignment:			2
	Assignment Name:	Animation in C++ using Container Classes and Overloaded Operators
	Due Date:			November 9. 2019
	Submission Date:	November 9, 2019
	Professor:			Mohamed Abouseif
	Lab Instructor:		Mariusz Makos
	Purpose:			To construct and initialize a Frame.
************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC//need this to get the line identification
#include <crtdbg.h>
#include <iostream>
#include "Frame.h"
using namespace std;
/*******************************************************************************************************************
	Function Name:		Frame
	Purpose:			To construct a frame and set its attributes
	In Parameters:		char* fName, double setDuration
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
Frame::Frame(char* fName, double setDuration) {

	frameName = new char[strlen(fName) + 1]; /* allocate memory for frameName */
	strcpy(frameName, fName); /* assign frameName */
	duration = setDuration; /* assign duration of frame */
}
/*******************************************************************************************************************
	Function Name:		Frame
	Purpose:			Copy Constructor
	In Parameters:		const Frame& frame
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
Frame::Frame(const Frame& frame) {
	
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(frameName, frame.frameName);
	this->duration = frame.duration;
}
/*******************************************************************************************************************
	Function Name:		~Frame
	Purpose:			Destructor, deallocates memory allocated by the frameName
	In Parameters:		Frame& frame
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
Frame::~Frame() {
	delete this->frameName; /* deallocate the memory used for frameName */
}
/*******************************************************************************************************************
	Function Name:		~Frame
	Purpose:			This method copies the attributes of a frame and returns a reference to the frame.
	In Parameters:		const Frame& f
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
Frame& Frame:: operator=(const Frame& f) {

	if (this == &f) { /* if we are copying the same frame value */
		return *this;
	}
	delete this->frameName; /* deallocate the previous frameName memory */
	this->frameName = new char[strlen(f.frameName) + 1]; 
	strcpy(frameName, f.frameName); 
	this->duration = f.duration;

	return *this;
}
/*******************************************************************************************************************
	Function Name:		ostream& operator<<
	Purpose:			Prints the attributes of a Frame
	In Parameters:		ostream& os Frame& f
	Out	Parameters:		ostream& os
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
std::ostream& operator<<(std::ostream& os, Frame& f) {
	os << "frameName = " << f.frameName << "; duration = " << f.duration;
	return os;
}