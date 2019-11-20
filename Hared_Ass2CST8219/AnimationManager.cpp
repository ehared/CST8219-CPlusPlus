/************************************************************************************************************************
	Filename:			AnimationManager.cpp
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
	Purpose:			To construct and manipulate Animation(s)
************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC//need this to get the line identification
#include <crtdbg.h>
#include <iostream>	
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

using namespace std;
/*******************************************************************************************************************
	Function Name:		EditAnimation()
	Purpose:			This function edits an Animation, chosen by the user.
	In Parameters:		N/A
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
void AnimationManager::EditAnimation() {

	if (animations.empty()) { /* check for empty list */
		cout << "There are no Animations in the Animation Manager" << endl;
		return;
	}
	char response;
	bool RUNNING = true;
	unsigned int aSize = animations.size();
	int index = 0;
	Animation* current;

	cout << "Which Animation do you wish to edit? Please give the index (from 0 to " << aSize - 1 << "):";
	cin >> index;

	if (index < 0 || index >= aSize) { /* validate index */
		cout << "Sorry the index is out of range (<=" << aSize - 1 << ")" << endl;
		return;
	}
	vector<Animation>::iterator it = animations.begin();

	for (int x = 0; x < index; x++) {
		it++; /* bringing iterator to the specified index */
	}
	current = &(*it);
	cout << "Editing Animation #" << index << endl;
	while (RUNNING) { /* Frame Menu */
		cout << "MENU\n 1. Insert a Frame\n 2. Delete a Frame\n 3. Edit a Frame\n 4. Quit" << endl;
		cin >> response;
		switch (response)
		{
		case '1': cin >> *current; break; 
		case '2': current->DeleteFrame(); break;
		case '3': current->EditFrame(); break;
		case '4': cout << "Animation #" << index << " edit complete" << endl; RUNNING = false; break;
		default:cout << "Please enter a valid option" << endl;
		}
	}
}
/*******************************************************************************************************************
	Function Name:		deleteAnimation()
	Purpose:			This function deletes an animation from animations.
	In Parameters:		N/A
	Out Parameters:		N/A
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
void AnimationManager::DeleteAnimation() {

	if (animations.empty()) { /* check for empty list */
		cout << "There are no Animations in the Animation Manager" << endl;
		return;
	} 
	int index = 0;
	unsigned int aSize = (unsigned int)animations.size(); /* the size of the list */
	
	cout << "Delete an Animation from the Animation Manager." << endl;
	cout << "Which Animation do you wish to delete? Please give the index in the range of 0 to " << aSize - 1 << ":";
	cin >> index;

	if (index < 0 || index >= aSize) {
		cout << "Sorry the index is out of range (<=" << aSize - 1 << ")" << endl;
		return;
	}
	// index is valid, proceed to deleting Animation
	vector<Animation>::iterator it = animations.begin();

	for (int x = 0; x < index; x++) {
		it++; /* bringing iterator to the specified index */
	}
	animations.erase(it); /* remove element at iterator */
	cout << "Animation #" << index << " deleted" << endl; /* notify user of deletion */
}
/*******************************************************************************************************************
	Function Name:		istream& operator>>()
	Purpose:			This function inserts an Animation to the manager.
	In Parameters:		std::istream& is, AnimationManager& a
	Out Parameters:		istream& is
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
std::istream& operator>>(std::istream& is, AnimationManager& a) {
	Animation* newAnimation;
	string name;

	cout << "Add an Animation to the Animation Manager." << endl;
	cout << "Please enter the Animation name: ";
	is >> name;
	
	newAnimation = new Animation(name); /* create temp animtion with user attributes */
	a.animations.push_back(*newAnimation); /* add animation to the end of the list */
	cout << "Animation " << name << " added at the back of animations." << endl;
	delete newAnimation; /* deallocate the memory of the temp animation */
	return is;
}
/*******************************************************************************************************************
	Function Name:		ostream& operator<<()
	Purpose:			This function prints out the Animations of the manager.
	In Parameters:		std::ostream& os, AnimationManager& a
	Out Parameters:		ostream& os
	Version:			1.0
	Author:				Eltire Hared
********************************************************************************************************************/
std::ostream& operator<<(std::ostream& os, AnimationManager& a) {
	
	if (a.animations.empty()) { /* check for an empty animation list*/
		os << "There are no Animations in the Animation Manager" << endl;
		return os;
	}
	int count = 0;
	Animation* current;
	os << "Animation Manager: " << a.managerName << endl;
	std::vector<Animation> ::iterator it = a.animations.begin();

	while (it != a.animations.end()) { /* iterate through animations display their frames, if they exist */
		current = &(*it);
		os << "Animation: " << count++ << endl;
		os << *current;
		++it;
	}
	return os;
}