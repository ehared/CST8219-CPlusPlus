/************************************************************************************************************************
	Filename:			Animation.cpp
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
	Purpose:			To construct an Animations and define all its functions.
************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC//need this to get the line identification
#include <crtdbg.h>
#include <iostream>
#include "Animation.h"

using namespace std;
/************************************************************************************************************************
	Function Name:				Animation()
	Purpose:					To contruct an Animation and initialize all its variables given by user input
	Function In Parameters:		N/A
	Function Out Parameters:	Animation
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
Animation::Animation() {
	
	char tempName[100];

	/* take user input for Animation name */
	cout << "Please enter the Animation name: ";
	cin >> tempName;
	/* allocate memory for the animationName */
	animationName = new char[strlen(tempName) + 1];

	if (!animationName) {
		cout << "Memory allocation failed." << endl;
		return;
	}
	/* copy user input to animationName */
	strcpy(animationName, tempName);
	/* set frames to point to null */
	frames = NULL;
}
/************************************************************************************************************************
	Function Name:				~Animation()
	Purpose:					This function is the destructor of the Animation class.
								Purpose of this function is to deallocate all memory allocated by Animation.
	Function In Parameters:		N/A
	Function Out Parameters:	N/A
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
Animation::~Animation() {
	
	Frame* current = frames;
	Frame* temp;

	/* if there are frames, delete each frame from the linked list, otherwise go straight into deallocating animation */
	if (frames != NULL) {
		/* iterate through the Frames Linked List and delete each node from memory */
		while (current != NULL) {
			temp = current;
			current = current->GetpNext();
			/* call destructor for the frame */
			delete temp;
		}
	}
	/* deallocate memory of the Animation name */
	delete this->animationName;
	/* set the frames pointer to NULL */
	this->frames = NULL;
}
/************************************************************************************************************************
	Function Name:				InsertFrame()
	Purpose:					This function creates a Frame to be inserted into the Animation
	Function In Parameters:		N/A
	Function Out Parameters:	void
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
void Animation::InsertFrame() {
	
	Frame* temp;
	char fName[100];
	int length = 0;

	/* construct frame */
	temp = new Frame();

	/* Take user input for frame name */
	cout << "Insert a Frame in the Animation." << endl;
	cout << "Please enter the Frame frameName: ";
	cin >> fName;

	/* allocate memory for frameName */
	length = strlen(fName) + 1;
	temp->GetFrameName() = new char[length];

	/* check allocation for frameName was successful */
	if (!temp->GetFrameName()) {
		cout << "Memory allocation failed.\n";
		return;
	}
	/* assign frameName */
	strcpy(temp->GetFrameName(), fName);

	/* Insert frame to beginning of the list */
	/* empty list */
	if (frames == nullptr) {
		frames = temp;
		return;
	}
	/* list is not empty, place frame at the front of the list */
	else {
		temp->GetpNext() = frames;
		frames = temp;
	}
}
/************************************************************************************************************************
	Function Name:				DeleteFrame()
	Purpose:					This function deletes a Frame from the Animation. Frame is selected by user input
	Function In Parameters:		N/A
	Function Out Parameters:	N/A
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
void Animation::DeleteFrame() {
	
	Frame* current = frames;
	Frame* temp;

	/* check to see if a Frame head does exist */
	if (current == NULL) {
		cout << "Sorry, there are no Frames to be deleted." << endl;
		return;
	}
	/* if there is only one frame in the list */
	if (current->GetpNext() == NULL) {
		delete current;
		this->frames = NULL;
		return;
	}
	/* delete the last frame in the list */

	while (current != NULL) {
		/* check if the next frame has a frame next to it, if no, that is the last node */
		if (current->GetpNext()->GetpNext() == NULL) {
			temp = current->GetpNext();
			/*  deallocate deleted frame from memory */
			delete temp;
			current->GetpNext() = NULL;
			break;
		}
		current = current->GetpNext();
	}
}
/************************************************************************************************************************
	Function Name:				EditFrame()
	Purpose:					THis function edits a Frame, chosen by user, in the Animation
	Function In Parameters:		N/A
	Function Out Parameters:	N/A
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
void Animation::EditFrame() {
	
	Frame* current = frames;
	int count = 0; /* count for number of frames in the list */
	int index;
	char newName[100];

	/* check if the frame list is null */
	if (current == NULL) {
		cout << "There are no frames to edit." << endl;
		return;
	}

	cout << "Edit a Frame in the Animation" << endl;

	/* iterate through linked list to get the total number of frames */
	while (current != NULL) {
		++count;
		current = current->GetpNext();
	}
	
	cout << "There are " << count << " Frame(s) in the list. Please specify the index (<=" << count -1 << ") to edit at:";
	cin >> index;

	/* check to see the index is within range of frame list */
	if ( index < 0 || index > (count - 1) ) {
		cout << "Sorry the index is out of range (<=" << count-1 << ")" << endl;
		return;
	}
	/* reset frame pointer */
	current = frames;

	/* iterate through Frames list until we have reached the selected Frame */
	int x = 0;
	while (x < index) {
		current = current->GetpNext();
		x++;
	}
	cout << "The name of this Frame is " << current->GetFrameName() << ". What do you wish to replace it with?" << endl;
	cin >> newName;
	/* delete the previous frame name */
	delete current->GetFrameName();

	/* allocate new size of memory for the new name entered by user */
	current->GetFrameName() = new char[strlen(newName) + 1];

	/* copy new name into Frame name */
	strcpy(current->GetFrameName(), newName);
}
/************************************************************************************************************************
	Function Name:				ReportAnimation()
	Purpose:					This function displays all the Frames in the Animation
	Function In Parameters:		N/A
	Function Out Parameters:	N/A
	Version:					1.0
	Author:						Eltire Hared
*************************************************************************************************************************/
void Animation::ReportAnimation() {

	int count = 0;
	Frame* current = frames;

	if (frames == NULL) { /* check to see if an Animation exists*/
		cout << "No Frames exist for this Animation." << endl;
		return;
	}
	cout << "Animation name is " << animationName << endl;
	cout << "Report the Animation." << endl;

	/* iterate through frame list and print frames*/
	while (current != NULL) {
		cout << "Frame #" << count++ << " file name = " << current->GetFrameName() << endl;
		/* toggle to the next frame in the list*/
		current = current->GetpNext();
	}
}