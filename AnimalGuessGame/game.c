/* CS261- game.c*/
/* Name: Baljot Singh
* Date: 5/09/2015
* Solution description: This program is animal guess game. The program
						implements the binary tree for decision.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"animalTree.h"

int main()
{
	char newAnimal[80];  //Variable for name of new animal
	char newQuestion[256];  //variable for new question
	char yesOrNo[10];  //Variable for user's decision

	struct aTree* tree = iniTree();  //Initialize tree

	/*Instructions*/
	printf("This is animal guess game.\n");
	printf("You will think about a animal and computer will try to guess that.\n");
	printf("You have to answer some questions with 'yes' or 'no'. \n");

	//Start do-while loop till user wants play again
	do
	{
		resetTree(tree); //Reset tree at start of new game

		displayData(tree, ""); //Display the root

		//Start do-while loop till end of tree
		do
		{
			printf("Answer 'yes' or 'no':");
			fgets(yesOrNo, 10, stdin);

			if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
			{
				displayData(tree, "yes");
			}

			else if (yesOrNo[0] == 'n' || yesOrNo[0] == 'N')
			{
				displayData(tree, "no");
			}

			else
			{
				printf("Answer 'yes' or 'no' only.\n");
			}
		} while (hasNext(tree));

		/*After end of tree asking user if guess was correct*/
		printf("Did I guess it correctly.\n");
		printf("Answer 'yes' or 'no':");

		//Do-while loop till user enter yes or no
		do
		{
			fgets(yesOrNo, 10, stdin);

			//If guess was correct do nothing
			if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
			{
				printf("I know that I am awsome.\n");
			}

			//Else add the new animal in tree
			else if (yesOrNo[0] == 'n' || yesOrNo[0] == 'N')
			{
				printf("No luck this time.\n");
				printf("Anyways which animal was in your mind?.Please give the name of animal:");
				fgets(newAnimal, 80, stdin);

				printf("Which question will distiguish %sfrom ", newAnimal);
				displayData(tree, "yes");
				fgets(newQuestion, 256, stdin);

				printf("What is the answer to the question for %s", newAnimal);
				printf("Answer 'yes' or 'no':");

				//Do-while loop till user enter yes or no
				do
				{
					fgets(yesOrNo, 10, stdin);

					if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
					{
						addNewAnimal(tree, newQuestion, newAnimal, "yes");
						printf("I will remember this.\n");
					}

					else if (yesOrNo[0] == 'n' || yesOrNo[0] == 'N')
					{
						addNewAnimal(tree, newQuestion, newAnimal, "no");
						printf("I will remember this.\n");
					}

					else
					{
						printf("Answer 'yes' or 'no' only:");
					}
				} while (yesOrNo[0] != 'n' && yesOrNo[0] != 'y' && yesOrNo[0] != 'N' && yesOrNo[0] != 'Y');
			}

			else
			{
				printf("Answer 'yes' or 'no' only:");
			}

		} while (yesOrNo[0] != 'n' && yesOrNo[0] != 'y' && yesOrNo[0] != 'N' && yesOrNo[0] != 'Y');

		/*Asking user if wants to play again*/
		printf("Do you want to play again?");
		printf("Answer 'yes' or 'no':");

		do
		{
			fgets(yesOrNo, 10, stdin);
			if (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y')
			{
				printf("Lets play again then\n");
			}

			else if (yesOrNo[0] == 'n' || yesOrNo[0] == 'N')
			{
				printf("You choose to exit. Thanks for playing\n");
			}

			else
			{
				printf("Answer 'yes' or 'no' only:");
			}
		} while (yesOrNo[0] != 'n' && yesOrNo[0] != 'y' && yesOrNo[0] != 'N' && yesOrNo[0] != 'Y');

	} while (yesOrNo[0] == 'y' || yesOrNo[0] == 'Y');
	
	copyTree(tree);  //Copy tree to file
	
	deleteTree(tree); //Deallocate memory

	return 0;
}
