/**
 * @file sort.h
 * @author Maharaj Teertha Deb , 40227747
 * @brief The C program provides functionality for generating and sorting a table of user
 * @date 2023-10-19
 * @return 0 : successfull exit , 9 error exit.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "generate.h"

int welcome_message();
void exit_code();
void main_menu();

unsigned int size = 0;
int command_list_int[10] = {-1};

int main()
{
	/* welcome_message() returns the user provided value and 
		we are assigning its return value to the variable `welcome_message_choice`.
	*/
	int welcome_message_choice = welcome_message();


	if(welcome_message_choice == 2){
		/*
		The code is checking if the user's choice from the main menu is equal to 2.
		If it is, it calls the `exit()` function, which terminates the program.
		This means that if the user selects option 2 from the main menu, the program will exit.
		*/
		exit_code();
	}

	else if(welcome_message_choice == 1){
		/**
		 * @brief main menu entrence
		 * if user enters 1 as their input, 
		 * code is redirected to the main menu
		 */
		char choice = 'c';
        do
		{
			/**
			 * @brief Construct a new main menu object
			 * keep going to the main_menu untill user enters 'c' or 'C'
			 */
			
			main_menu();

			printf("Press \'c\' or \'C\' to continue ");
			while ((choice = getchar()) != '\n' && choice != EOF) { }; // clear the buffer.
			choice = getchar(); // getuser input
		} while (choice == 'c' || choice == 'C');
	}
    /* The function is called when the user chooses to
	exit the program. It simply prints a goodbye message and then calls the `exit()` function from
	the `stdlib.h` library to terminate the program with a successful exit status. */
	exit_code();

	//9 was assigned to check if the program was closed from exit function.
	return 9;
}

/**
 * @brief : The function is displaying a menu for the user to select an option.
 * 			It clears the console screen then prints the menu options.
 * 			It prompts the user to enter their selection and
 * 			returns the input to the calling function.


 * @return n (int) : the number provided by the user.
 */
int welcome_message()
{
	system("clear");
	printf("TableGen Menu\n");
	printf("----------------\n");
	printf("1. Generate new table\n");
	printf("2. Exit\n\n");
	int n;
	printf("Selection: ");
	scanf("%d" ,&n);
	return n;
}


/**
 * @brief : The function is a user-defined function that is called when the user chooses to exit the program.
 * 			It simply prints a goodbye message and then calls the `exit()`
 * 			function from the `stdlib.h` library to terminate the program with a successful exit status.
 */
void exit_code()
{
	system("clear");
	printf("Goodbye and thanks for using TableGen.\n\n\n\n");
	exit(EXIT_SUCCESS);
}


/**
 * @brief : he main_menu function displays a menu to the user, prompts for input, and then calls the MakeUser
 * function to create a table based on the user's input.
 * 
 */
void main_menu()
{
	system("clear");
	//The code is declaring the main menu options.
	char Main_Menu_Options[][14] = {"User ID" , "First Name" , "Last name" , "Country" , "Phone Number" , "Email address" , "SIN" , "Password"};

	printf("Column Options\n");
	printf("-----------------");
	//The code is using a for loop to iterate through the elements of
	//the `Main_Menu_Options` command_listay and print them on the console screen.
	for(int i = 0; i < 4 ; i++){
		printf("\n%d. %s \t\t %d. %s" ,i+1 ,Main_Menu_Options[i] ,i+4+1 , Main_Menu_Options[i+4]);
	}

	printf("\n\nEnter command list (comma-separated, no spaces): ");

	//This command_listay is used to store the user's input for the command list.
	char command_list[50]; // assuming user would not ask more than 9 commands
	scanf("%59s", command_list);
	//The for loop iterates through each character in the `command_list` command_listay and extract the number
	size = 0;
	for(int i = 0 , j = 0; i < strlen(command_list) ; i++){
		//The code is checking if the character at index `i` in the `command_list` command_listay is a digit.
		//If it is a digit, it converts the character to an integer and assigns the integer value
		//to the `command_list_int` command_listay at index `j`.
		//After assigning the value, it increments `j` by 1 to move to the next index in the `command_list_int` command_listay.
		//This process is repeated for each character in the `command_list` command_listay.
		if( isdigit(command_list[i]) ){
			command_list_int[j] = atoi(&(command_list[i])) - 1;
			j++ , size++;
		}
	}

	//The code is prompting the user to enter a value for the row count.
	// It displays the message "Enter row count (1 < n < 1M): "
	printf("Enter row count (1 < n < 1M): ");
	long int row_count;
	scanf("%ld" ,&row_count);

	//The code is prompting the user to enter the name of the output file.
	printf("Enter output file name (no suffix): ");
	char output_file_name[205];
	scanf("%s" ,output_file_name);

	//The code displays a summary of the properties entered by the user.
	printf("Summary of properties:");
	printf("\n\tColumns : %s" ,command_list);
	printf("\n\tRow Count : %ld " ,row_count);
	printf("\n\tFile Name : %s \n" ,output_file_name);
	strcat(output_file_name , ".csv");
	

	/* The line is calculating the size of the `command_list_int` array. */
	fflush(stdin);
	// Try to MakeUser
	if(MakeUser(row_count , output_file_name)){
		printf("\nTable Written Successfully to %s\n\n" , output_file_name);
	}
	
	else{
		printf("\a\nFile was not created for some reason. Sorry. :-(\n\n");
	}

}