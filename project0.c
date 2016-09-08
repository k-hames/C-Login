/*
 ============================================================================
 Name        : project0.c
 Author      : Kevin Hames
 Version     :
 Copyright   : Copyright 2016
 Description : Basic Login program in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// 1: Variables
	char input_username[20];
	char input_password[20];
	char username[20];
	char password[20];
	int found = 0;
	FILE *file;
	// 2: User entered username and password
	printf("Enter Username: ");
	scanf("%s", input_username);
	printf("Enter Password: ");
	scanf("%s", input_password);
	// printf(input_username);
	// printf(input_password);
	// 3: reading the text file and checking for a matching username and password
	file = fopen("passwd.txt", "r");
	if (file)
		{
		// printf("the file was read \n");
		while(fscanf(file, "%s %s", username, password) != EOF && found == 0)
			{
			if(strcmp(input_username,username) == 0 && strcmp(input_password,password) == 0)
				{
				printf("The information entered was correct. \n");
				found = 1; // if found exit loop
				}
			// printf("%s \n", username);
			// printf("%s \n", password);
			}
		}
	if (found==0)
		printf("The username and password does not match. \n");
	return EXIT_SUCCESS;
}
