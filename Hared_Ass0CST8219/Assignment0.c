/***********************************************************************************************************************************************************
	Filename:			Assignment0.c
	Version:			1.0
	Student Name:		Eltire 'Mahad' Hared
	Student #:			040911519
	Course:				CST8219 C++ Programming Section: 310
	Lab Section:		313
	Assignment:			0
	Assignment Name:	Animation Project in C
	Due Date:			September 21, 2019
	Submission Date:	September 21, 2019
	Professor:			Mohamed Abouseif
	Lab Instructor:		Muhammad Arshad
	Purpose:			Create a simple C Language console application that holds the data of an animation application using a linked list in dynamic memory.
	
*************************************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC // need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
typedef enum { FALSE = 0, TRUE } BOOL;
struct Frame {
	char* frameName;
	struct Frame* pNext;
};
typedef struct {
	char* animationName;
	struct Frame* frames;
}Animation;
// Forward declarations
void InitAnimation(Animation*);
void InsertFrame(Animation*);
void DeleteFrame(Animation*);
void EditFrame(Animation*);
void ReportAnimation(Animation*);
void CleanUp(Animation*);
void DeleteMiddle(Animation*);
/*******************************************************************************************************************************************
	Function name: main
	Purpose: main function
				- Calls various functions based on user input to construct an Animation(Linked List)
	Function InParameters: none
	Funcstion OutParameters: int - 0 for successful execution
	Version: 1.0
	Author: @Eltire Hared

********************************************************************************************************************************************/
int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);
	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n 6. Delete middle frame\n");
	 	scanf("%c", &response);
		while ((getchar()) != '\n'); // clear buffer ** ask prof if allowed to add this line to solve multiple menu prints
		switch (response)
		{
		case '1':InsertFrame(&RG); break;
		case '2':DeleteFrame(&RG); break;
		case '3':EditFrame(&RG); break;
		case '4':ReportAnimation(&RG); break;
		case '5':RUNNING = FALSE; CleanUp(&RG); break;
		case '6':DeleteMiddle(&RG);
		default:printf("Please enter a valid option\n");
		}		
	}
	return 0;
}
/*******************************************************************************************************************************************
	Name: InitAnimation
	Purpose: This function sets the name of the Animation
	In Parameters: aHead - pointer to Animation RG
	Out Parameters: none
	Version: 1.0
	Author: Eltire Hared
*******************************************************************************************************************************************/
void InitAnimation(Animation* aHead) {
	
	char aName [50] ; // name variable to assign to user input
	int length; // keep track of the name length
	
	printf("Please enter the Animation name: "); // take user input for the name to be assigned to the Animation
	scanf("%s", &aName);
	
	length = strlen(aName) + 1; // calculate the length of aName and add extra space for null termination 
	aHead->animationName = (char*)malloc(length); /* allocate memory for animation name */
	strcpy(aHead->animationName, aName); // Assign name to animationName
	while ((getchar()) != '\n'); // clear scanf buffer
	
	aHead->frames = NULL; // set Animation's frame pointer to NULL
}
/*******************************************************************************************************************************************
	Name: InsertFrame
	Purpose: This function creates a Frame to be inserted into the Animation
	In Parameters:	aHead - pointer to Animation which the frame will be inserted into.
	Out Parameters: none
	Version: 1.0
	Author: Eltire Hared
*******************************************************************************************************************************************/
void InsertFrame(Animation* a) {
	
	char fName[50];
	int length;
	struct Frame* temp; 

	temp = (struct Frame*)malloc(sizeof(struct Frame)); // memory allocation for Frame

	// check if the memory allocation for the frame was successful
	if (temp == NULL) { 
		printf("\nSorry no memory could be allocated for Frame.\n");
		return;
	}
	printf("Insert a Frame in the Animation\n");
	printf("Please enter the Frame frameName: "); // Assign frame name to Frame 
	scanf("%s", &fName);
	while ((getchar()) != '\n'); // clear buffer

	length = strlen(fName) + 1; // get size of frame name for memory allocation 
	temp->frameName = (char*)malloc(length); // allocate memory for the frameName
	strcpy(temp->frameName, fName); // assign the frameName
	temp->pNext = NULL; // set the Frame's pointer to NULL
	
	// Case 1: Check to see if a head node exists in Frames
	if (a->frames == NULL) { 
		a->frames = temp; // assigns temp Frame to the Head of Frames List
	}
	else { // Case 2: Animation has existing frames. Now place the new frame at the front by making it the Head 
		temp->pNext = a->frames;
		a->frames = temp;
	}
}
/******************************************************************************************************************************************
	Name: DeleteFrame
	Purpose: This function will delete the last frame that was inserted into the Animation
	In Parameters: aHead - pointer to the Animation whhich will be accessed to delete frame (if one exists)
	Out Paramters: none
	Version: 1.0
	Author: Eltire Hared
******************************************************************************************************************************************/
void DeleteFrame(Animation* aHead) {
	
	struct Frame* current = aHead->frames;
	struct Frame* temp;

	//check to see if a Frame head does exist
	if (current == NULL) {
		printf("Sorry, there are no Frames to be deleted.\n");
		return;
	}
	temp = current->pNext; // set temp to the next Frame 
	aHead->frames = temp; //set new Head of the Frame List 
	free(current->frameName);
	free(current); // free allocated memory of the deleted Frame 
}
/******************************************************************************************************************************************
	Name: EditFrame
	Purpose: This function modifies the name of a Frame selected by the User
	In Parameters: aHead - pointer to Animation to access the Frame to be modified(if frame does exist)
	Out Parameters: none
	Version: 1.0
	Author: Eltire Hared
******************************************************************************************************************************************/
void EditFrame(Animation* aHead) {

	int count = 0;
	int choice;
	int x; 
	char newName[50];
	struct Frame* current = aHead ->frames; // set current Frame to the head of the Frames List

	// check to see if an Animation does exist
	if (aHead == NULL) {
		printf("No Animation was created to edit.\n");
		return;
	}
	printf("Edit a Frame in the Animation\n");
	// check to see if the Frames list has a head(ie. if there are nodes)
	if (current == NULL) {
		printf("Animation does not have any Frames.\n");
		return;
	}
	// iterate through the list of Frames to count the # of Frames
	while (current != NULL) { 
		count++;
		current = current->pNext; // sets pointer to the next Frame in the List
	}
	printf("There are %d Frame(s) in the list. Please specify the index (<= %d) to edit at : ", count, (count - 1));
	scanf("%d", &choice); // retrieve which Frame the user wishes to edit 

	// Check to see if the index is within Frame List 
	if (choice > (count - 1)) { 
		printf("Sorry, Frame index does not exist (index <= %d)\n", (count - 1));
		return;
	}  
	current = aHead->frames; // reassign pointer to the head of the list
	if (choice == 0) { // first frame of the list
		printf("The name of this Frame is %s. What do you wish to replace it with? ", current->frameName);
	}
	else {
		// iterate through the list to find the selected Frame
		for (x = 0; x < choice; x++) { 
			current = current->pNext;
		}
		printf("The name of this Frame is %s. What do you wish to replace it with? ", current->frameName);
	}
	scanf("%s", &newName);// Assign new name to the Frame selected
	while ((getchar()) != '\n'); // clear buffer
	free(current->frameName); // free previous memory of name

	int length = strlen(newName) + 1;

	current->frameName = (char*)malloc(length);

	strcpy(current->frameName, newName); // Assign selected Frame's new name 
}
/******************************************************************************************************************************************
	Name: ReportAnimation
	Purpose: This function prints out the details of the Animation and its frames
	In Parameters: aHead - pointer to Animation being printed
	Out Parameters: none
	Version: 1.0
	Author: Eltire Hared
******************************************************************************************************************************************/
void ReportAnimation(Animation* aHead) {
	
	int count = 0;
	struct Frame* current = aHead->frames;

	if (aHead == NULL) { /* check to see if an Animation exists*/
		printf("No Animations exist to report.\n");
		return;
	}
	printf("Animation name is %s\n", aHead->animationName);
	printf("Report the Animation\n");
	if (aHead->frames == NULL) { /* check to see if the animation has any frames*/
		printf("\nNo Frames exist for this Animation.\n");
		return;
	}
	while (current != NULL) { /* iterate through frame list and print them out*/
		printf("Image #%d, file name = %s\n", count,current->frameName);
		count++; /* counter for image #*/
		current = current->pNext; /* toggle to the next frame in the list*/
	}
}
/******************************************************************************************************************************************
	Name: CleanUp
	Purpose: This function frees all memory allocated to the Animation and its Frames.
	In Parameters: aHead - pointer to Animation being free'd from memory
	Out Parameters: none
	Version: 1.0
	Author: Eltire Hared
******************************************************************************************************************************************/
void CleanUp(Animation* aHead) {
	
	struct Frame* fHead = aHead->frames;
	struct Frame* temp;
	
	// check to see if an Animation does exist
	if (aHead == NULL) { 
		return;
	}
	else { // an Animation does exist
		// iterate through the Frames list and free the memory of each Frame
		while (fHead != NULL) {
			temp = fHead;
			fHead = fHead->pNext; 
			temp->pNext = NULL;
			free(temp->frameName); // free's the memory allocated for frameName of each Frame
			free(temp); // frees the frame
		}
		aHead->frames = NULL; // set the Frames head to NULL
		free(aHead->animationName); // free the allocated memory for the animationName
	}
	
}
void DeleteMiddle(Animation* aHead) {
	struct Frame* current = aHead->frames;
	struct Frame* temp = NULL;
	int count = 0;
	int index = 0;

	if (current == NULL) {
		printf("There are no frames to delete.\n");
	}
	else {
		// Case 1: There is only 1 frame in the list
		if (current->pNext == NULL) {
			temp = current->pNext;
			aHead->frames= temp;
			free(current->frameName);
			free(current);
		}
		else {
			// Case 2: more than one frame
			while (current != NULL) {
				current = current->pNext;
				count++; // Get the number of frames
			}
			current = aHead->frames;
			index = count / 2; // middle index
			count = 0; // reassign to 0

			while (current != NULL) {
				count++;
				// Case 2: more than 1 Frame
				if (count == index) {
					temp = current->pNext;
					if (current->pNext == NULL) {
						current->pNext = NULL;
					}
					else {
						current->pNext = current->pNext->pNext;
					}
					free(temp->frameName);
					free(temp);
				}
				current = current->pNext;
			}

		}
	
	}

}