/************************************************************************************************************************
	Filename:			Animation.cpp
	Version:			1.0
	Student Name:		Eltire 'Mahad' Hared
	Student #:			040911519
	Course:				CST8219 C++ Programming Section: 310
	Lab Section:		313
	Assignment:			2
	Assignment Name:	Animation in C++ using Container Classes and Overloaded Operators
	Due Date:			November 9, 2019
	Submission Date:	November 9, 2019
	Professor:			Mohamed Abouseif
	Lab Instructor:		Mariusz Makos
	Purpose:			To construct an Animations and define all its functions.
************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
#include<iostream>
#include<string>
#include<crtdbg.h>
#include <iomanip>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"

using namespace std;
/*******************************************************************************************************************
	Function Name:		EditFrame()
	Purpose:			This function edits a frame, chosen by the user, in the Animation.
	In Parameters:		N/A
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
void Animation::EditFrame() {
	
	forward_list<Frame>::iterator it = frames.begin(); /* iterator to move along frame list */
	Frame* new_Frame;
	Frame* edit_Frame;
	int count = 0; /* count for number of frames in the list */
	int index;
	char newName[100];
	int newDuration = 0;
			
	if (frames.empty()) { /* check for empty frame list */
		cout << "There are no Frames in the Animation" << endl;
		return;
	}
	cout << "Edit a Frame in the Animation" << endl;
	
	it = frames.begin(); /* set iterator to the beginning of the frames list */
	while (it != frames.end()) { /* count the number of frames in the list */
		count++;
		it++;
	}
	cout << "There are " << count << " Frame(s) in the list. Please specify the index (<=" << count - 1 << ") to edit at:";
	cin >> index;
		
	if (index < 0 || index >(count - 1)) { /* check to see the index is within range of frame list */
		cout << "Sorry the index is out of range (<=" << count - 1 << ")" << endl;
		return;
	}
	it = frames.begin(); /* reset iterator */
	for (count = 0; count < index; count++) { /* iterate to chosen index */
		++it;
	}
	
	edit_Frame = &(*it); /* retrieve the frame we want to edit */
	cout << "The name and duration of this Frame are " << *it << ". What do you with to replace them with?" << endl;
	cin >> newName;
	cin >> newDuration;
	new_Frame = new Frame(newName, newDuration); /* temp frame with new attributes given by user */
	*edit_Frame = *new_Frame;					/* deep copy of the new frame with the new attributes */
	delete new_Frame;							/* de-allocate the memory of the temp frame */
	
	cout << "Frame #" << index << " edit completed" << endl;
}
/*******************************************************************************************************************
	Function Name:		DeleteFrame()
	Purpose:			This function deletes a frame from the front of the list.
	In Parameters:		N/A
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
void Animation::DeleteFrame() {

	if (frames.empty()) { /* check for empty list */
		cout << "There are no Frames in the Animation" << endl;
		return;
	}

	frames.pop_front(); /* deletes frame at the front of the list */
	cout << "First Frame deleted." << endl;
}
/*******************************************************************************************************************
	Function Name:		ostream& operator<<()
	Purpose:			This function outputs the list of frames in the animation.
	In Parameters:		ostream&, Animation&
	Out Parameters:		ostream&
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
std::ostream& operator<<(std::ostream& os, Animation& a) {
	
	os << setw(8) << " "; /* indents the following output */
	os << "Animation name is " << a.animationName << endl;
	os << setw(8) << " ";
	os << "Report the Animation" << endl;

	if (a.frames.empty()) {
		os << setw(8) << " ";
		os << "No frames in the Animation" << endl;
		return os;
	}

	forward_list<Frame>::iterator it = a.frames.begin(); /* intialized iterator used to iterate through the frames list */
	Frame* current;
	int count = 0;

	while (it != a.frames.end()) { /* iterate through the frames list, and print attributes */
		current = &(*it);
		os << setw(8) << " ";
		os << "Frame " << count++ <<": " << *current << endl;
		++it;
	}
	return os;
}
/*******************************************************************************************************************
	Function Name:		istream& operator>>()
	Purpose:			This function inserts a frame into the Animation.
	In Parameters:		istream&, Animation&
	Out Parameters:		istream& is
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
std::istream& operator>>(std::istream& is, Animation& a) {

	Frame* newFrame;
	char name[100]; /* name to assign to the frame */
	int d = 0; /* duration of the frame */

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame frameName:"; /* take user input for the frameName and duration of the frame */
	is >> name;
	cout << "Please enter the Frame duration:";
	is >> d;

	newFrame = new Frame(name, d); /* constructs the frame we want to add the Animation */
	a.frames.push_front(*newFrame);

	cout << "Frame " << name << " added at the front of frames" << endl;
	delete newFrame; /* deallocate the memory of temp frame */

	return is;
}