/************************************************************************************************************************
	Filename:			Animation.h
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
	Purpose:			Header file for the Animation class. Outlines all the methods and variables of an Animation.
************************************************************************************************************************/
#pragma once
#include<iostream>
#include "Frame.h"

class Animation{
	
	char* animationName;
	Frame* frames;

	public:
		Animation();
		~Animation();
		void InsertFrame();
		void EditFrame();
		void DeleteFrame();
		void ReportAnimation();
};