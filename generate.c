/**
 * @file generate.c
 * @author Maharaj Teertha Deb , 40227747
 * @brief The code is responsible for Generating Tables.
 * @date 2023-10-19
 */



#ifndef GENERATE_DOT_C
#define GENERATE_DOT_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#include "sort.h"
#include "io.h"
#include "generate.h"

extern unsigned int size;
extern int command_list_int[10];


const int valid_phone_index[] = {398, 270, 925, 867, 209, 429, 908, 997, 444, 219}; //from assignment details

/*
	As I already know there are no more than 1000 firstNames, lastNames ;
	no more than 200 coutries and no more than 100 email suffix in file,
	so I hardcoded the arrays rather than reading them 2 times.
*/
char firstNameFromFile[1001][FirstNameLength] = {0};
char lastNameFromFile[1001][LastNameLength] = {0};
char countryNamesFromFile[200][CountryNameLength] ={0};
char email_suffix[101][EmailSuffixLength] = {0};
char finalPhoneNumbers[10000][PhoneNumberLength] = {0}; // phone numbers can be generated at this most;
int haveFirstNames = 0, haveLastNames = 0, haveEmailAddress = 0, haveCountryNames = 0 , havePhoneNumbers = 0;
static char CurrentPassword[17] = {0};
static bool SIN_Needed = false;
static bool Password_Needed = false;
static bool ID_Needed = false;
static bool First_Name_Was_First_Column = false , 
			Last_Name_Was_First_Column = false , Country_Was_First_Column = false , SIN_Was_First_Column = false , 
			Phone_number_Was_First_Column = false , Password_Was_First_Column = false;

// Functions:
bool WriteUsers(long int , char[]);
bool MakeUser(long int, char[]);
bool CreatePhoneNumber();
void generatePassword();
long int generateSIN();
// static bool numberExists(int [], int , unsigned int );


bool CreatePhoneNumber() {
	havePhoneNumbers = 10000;
    /* The above code is generating random phone numbers and storing them in the array
	`finalPhoneNumbers`. It uses the `valid_phone_index` array to select a random digit and appends
	it to the generated number. It then appends a hyphen and a random 4-digit number to complete the
	phone number. This process is repeated 10,000 times. */
	for (int i = 0; i < 10000; i++) {
        char generatedNumber[13]; // Assuming the length of valid_phone_index elements is 12

        snprintf(generatedNumber, 13, "%d", valid_phone_index[rand() % 10]);
        strcat(generatedNumber, "-");

        char t[6];
        snprintf(t, 6, "%d", ((rand() % (9999 - 1000 + 1)) + 1000));

        strcat(generatedNumber, t);
        strcpy(finalPhoneNumbers[i], generatedNumber);
    }
    return true;
}

void generatePassword() {

    int minLength = 6;
    int maxLength = 16;
    int length = rand() % (maxLength - minLength + 1) + minLength; // Generate a random length between minLength and maxLength
    char* password = (char*)malloc((length + 1) * sizeof(char)); // Allocate memory for password (including null terminator)

    for (int i = 0; i < length; i++) {
        int randomChar;
		randomChar = rand() % 91 + 35;
		if(randomChar == 44){ // if it is a ',' replace it
			randomChar += 1;
		}
        password[i] = (char)randomChar;
    }

    password[length] = '\0'; // Null-terminate the string

    strcpy(CurrentPassword, password);
    free(password);
}

/**
 * The function generates a random Social Insurance Number (SIN) within a specified range.
 * 
 * @return a randomly generated Social Insurance Number (SIN) as a long integer.
 */
long int generateSIN() {
    long int minSIN = 100000000;
    long int maxSIN = 999999999;
    long int SIN = ((rand() * (rand() + 9821)) % (maxSIN - minSIN + 1) + minSIN) % maxSIN;
	/* The code is a while loop that multiplies the value of the variable SIN by 10 until it is
	greater than or equal to the value of the variable minSIN. */
	while(SIN < minSIN){
		SIN *= 10;
	}
	/* The is a while loop that divides the value of SIN by 10 repeatedly until SIN is no
	longer greater than maxSIN. */
	while(SIN > maxSIN){
		SIN /= 10;
	}

    return SIN < 0 ? SIN * -1 : SIN; // still if the SIN is negative, multiply it by -1 and return.
}



/**
 * The function "WriteUsers" creates a specified number of user objects with randomly generated
 * attributes such as first name, last name, country, phone number, email, SIN, and password.
 *
 * @param numberOfUser [int] : The number of users to create.
 */
bool WriteUsers(long int numberOfUser , char FileName[])
{
	
	FILE *fptr;

	/* The code is attempting to open a file named "FileName" in write mode. If the file cannot be
	opened, it will print an error message and return false. */
	fptr = fopen(FileName , "w");
	if(fptr == NULL){
		printf("File could not open to write into the csv file.");
		fclose(fptr);
		return false;
	}

	struct User* users= (struct User*)malloc(numberOfUser * sizeof(struct User)); // Dynamically Allocating Memory for users so that even 1M users creation is possible
	/* The code is checking if the variable "users" is null. If it is null, it prints an error
	message indicating that memory allocation for the users array has failed. It then attempts to
	allocate memory again using the malloc function. If the second allocation attempt also fails, it
	prints another error message and returns from the function. */
	if(users == NULL){
		printf("Failed to allocate memory for %ld users. Maybe you are passing the parameters without following the syntax." ,numberOfUser);
		printf("Trying to allocate memory again.");
		//reallocate memory for array of pointers
		struct User* users= (struct User*)malloc(numberOfUser * sizeof(struct User)); //trying again.
		/* The above code is checking if the variable "users" is false or null. If it is, it will print
		"Failed Again. Run this program again..." and return. */
		if (!users) {
			printf("Failed Again. Run this program again...");
			return false;
		}
	}

	

	if(command_list_int[0] == 1){												//The first Column Should be First Name
		First_Name_Was_First_Column = true;
		for (long i = 0; i < numberOfUser; i++){
			strcpy(users[i].FirstName , firstNameFromFile[rand() % haveFirstNames]);
		}
		sortUsers(numberOfUser , users , 0);
	}
	
	else if (command_list_int[0] == 2){											//The first Column Should be Last Name
		Last_Name_Was_First_Column = true;
		for (long i = 0; i < numberOfUser; i++){
			strcpy(users[i].LastName , lastNameFromFile[rand() % haveLastNames]);
		}
		sortUsers(numberOfUser , users , 1);
	}
	
	else if (command_list_int[0] == 3){											//The first Column Should be Country Name
		Country_Was_First_Column = true;
		for (long i = 0; i < numberOfUser; i++){
			strcpy(users[i].CountryName , countryNamesFromFile[rand() % haveCountryNames]);
		}
		sortUsers(numberOfUser , users , 2);
	}

	else if (command_list_int[0] == 4){											//The first Column should be Phone Number
		Phone_number_Was_First_Column = true;
		for (long i = 0 ; i < numberOfUser ; i++){
			strcpy(users[i].PhoneNumber , finalPhoneNumbers[rand() % havePhoneNumbers]);
		}
		sortUsers(numberOfUser , users , 3);
	}

	else if (command_list_int[0] == 6){											//The first Column shoule be SIN
		SIN_Was_First_Column = true;
		for (long i = 0 ; i < numberOfUser ; i++){
			users[i].SIN = generateSIN();
		}
		sortUsers(numberOfUser , users , 4);
	}

	else if (command_list_int[0] == 7){											//The first Column shoule be Password.
		Password_Was_First_Column = true;
		for (long i = 0 ; i < numberOfUser ; i++){
			generatePassword();
			strcpy(users[i].Password , CurrentPassword);
		}
		sortUsers(numberOfUser , users , 5);
	}
	
	// //Comment this code after:
	// for (long int i = 0; i < numberOfUser; i++)
	// {
	// 	printf("\n\n\nUser[%d]:\n" , i);
	// 	printf("\tFirstName : %s\n\tLastName : %s\n\tCountry : %s\n\tPhone Number : %s\n\tEmail: %s\n\tSIN : %d\n\tPassword: %s"
	// 			,users[i].FirstName ,users[i].LastName ,users[i].CountryName ,users[i].PhoneNumber ,users[i].SIN ,users[i].Password);
	// 	getchar();
	// }
	
	
	
	/* The code is iterating through an array called `command_list_int` and based on the value at
		each index, it is writing a corresponding string to a file using `fprintf`. The values in
		`command_list_int` are being compared to different integers and based on the comparison, a specific
		string is written to the file. 
	*/
	for (int i = 0 ; i < size ; i++){
		if(command_list_int[i] == 0){
			fprintf(fptr, "ID,");
		}
		else if (command_list_int[i] == 1){
			fprintf(fptr, "First Name,");
		}
		else if (command_list_int[i] == 2){
			fprintf(fptr, "Last Name,");
		}
		else if (command_list_int[i] == 3){
			fprintf(fptr, "Country,");
		}
		else if (command_list_int[i] == 4){
			fprintf(fptr, "Phone Number,");
		}
		else if (command_list_int[i] == 5){
			fprintf(fptr, "Email ID,");
		}
		else if (command_list_int[i] == 6){
			fprintf(fptr, "SIN,");
		}
		else if (command_list_int[i] == 7){
			fprintf(fptr, "Password,");
		}
	}
	fprintf(fptr, "\n");

	char FirstName[FirstNameLength] = {0};
	char LastName[LastNameLength] = {0};
	/* The code is generating user data and writing it to a file. It iterates over a number of users
	specified by the variable "numberOfUser". For each user, it writes their index, first name (if
	available), last name (if available), country name (if available), phone number (if available),
	email address (if available), SIN (Social Insurance Number) if needed, and password (if needed) to
	the file. The generated email address is created by combining the first character of the first
	name, the last name, and a randomly selected email suffix. The generated SIN and password */
	for (long int i = 0; i < numberOfUser; i++){
		for (int j = 0 ; j < size ; j++){
			
			if(command_list_int[j] == 0){					// Write ID Number
				fprintf(fptr , "%ld," , i+1);
			}

			else if(command_list_int[j] == 1){				// Write First Name
				if(First_Name_Was_First_Column){
					strcpy(FirstName , users[i].FirstName);
				}
				else{
					strcpy(FirstName , firstNameFromFile[rand() % haveFirstNames]);
				}
				fprintf(fptr , "%s," , FirstName);
			}

			else if(command_list_int[j] == 2){				// Write Last Name
				if(Last_Name_Was_First_Column){
					strcpy(LastName , users[i].LastName);	
				}
				else{
					strcpy(LastName , lastNameFromFile[rand() % haveLastNames]);
				}
				fprintf(fptr , "%s," , LastName);
			}

			else if(command_list_int[j] == 3){				// Write Country Name
				if(Country_Was_First_Column){
					fprintf(fptr , "%s," , users[i].CountryName);
				}
				else{
					fprintf(fptr , "%s," , countryNamesFromFile[rand() % haveCountryNames]);
				}
			}

			else if(command_list_int[j] == 4){				// Write PhoneNumbers
				if(Phone_number_Was_First_Column){
					fprintf(fptr , "%s," , users[i].PhoneNumber);
				}
				else{
					fprintf(fptr , "%s," , finalPhoneNumbers[rand() % havePhoneNumbers]);
				}
			}

			else if(command_list_int[j] == 5){				// Write Email ID
				char EmailId[1 + LastNameLength + EmailSuffixLength] = {0} , temp[1 + LastNameLength + EmailSuffixLength] = {0}; // 1 for '@'
				temp[0] = FirstName[0];
				strcat(temp , LastName);
				strcat(temp , "@");
				strcat(temp , email_suffix[rand() % haveEmailAddress]);
				/* The code is converting each character in the string "temp" to lowercase and storing it in
				the "EmailId" array of the "users" structure. The loop iterates over each character in the "temp"
				string using the strlen() function to determine the length of the string. The tolower() function
				is used to convert each character to lowercase before storing it in the "EmailId" array. */
				for(unsigned int j = 0; j < strlen(temp) ; j++){
					EmailId[j] = tolower(temp[j]);
				}

				/* setting the last character of the string `EmailId` to the null character ('\0'). */
				EmailId[strlen(temp)] = '\0';
				fprintf(fptr, "%s,", EmailId);
			}

			else if(command_list_int[j] == 6){					// Write SIN
				if(SIN_Was_First_Column){
					fprintf(fptr , "%ld,"  , users[i].SIN);
				}
				else{
					fprintf(fptr , "%ld,"  , generateSIN());
				}
			}

			else if(command_list_int[j] == 7){					// Write Password
				if(Password_Was_First_Column){
					fprintf(fptr , "%s," , users[i].Password);
				}
				else{
					generatePassword();
					fprintf(fptr , "%s," , CurrentPassword);
				}
			}
		}
		fprintf(fptr , "\n");
	}

	/**
	 * @brief Set everything to false for next use.
	 * 
	 */
	{
		ID_Needed = SIN_Needed = Password_Needed = false;
		haveFirstNames = haveLastNames = haveCountryNames = havePhoneNumbers = haveEmailAddress = 0;
		First_Name_Was_First_Column = Last_Name_Was_First_Column = Country_Was_First_Column = SIN_Was_First_Column = Password_Was_First_Column = false;
	}

	/* The above code is closing a file pointer using the `fclose` function and freeing the memory
	allocated on the heap using the `free` function. */
	{	
		fclose(fptr); // Close file pointer
		free(users); // free the heap
	}

	return true;
}


bool MakeUser(long int NumberOfUsersToBeCreated , char fileName[])
{
	srand((unsigned int)time(NULL));

	/* The code is a for loop that iterates through a command list. Each element in the command list
	is a command represented by an integer. */
	for (int i = 0 ; i < size ; i++){
		switch (command_list_int[i]) {
			case 0 : {
				ID_Needed = true;
				break;
			}
			case 1 : {
				if(!ReadFirstName()){
					printf("\nFirst Name could not read. Files will be written without FirstName.");
					haveFirstNames = 0;
				}
				break;
			}
			case 2 : {
				if(!ReadLastName()){
					printf("\nLast name could not read, Files will be written without LastName.");
					haveLastNames = 0;
				}
				break;
			}
			case 3 : {
				if(!ReadCountryName()){
					printf("\nCountry name could not read. Files will be written without Country Name.");
					haveCountryNames = 0;
				}
				break;
			}
			case 4 : {
				if(!CreatePhoneNumber()){
					printf("\nPhone number could not be created. Files will be written without Phone Number.");
					havePhoneNumbers = 0;
				}
				break;
			}
			case 5 : {
				if(!ReadEmail()){
					printf("\nEmails could not be created. Files will be written without Email IDs.");
					haveEmailAddress = 0;
				}
				break;
			}
			case 6 : {
				SIN_Needed = true;
				break;
			}
			case 7 :{
				Password_Needed = true;
				break;
			}
			default :{
				printf("You entered an invalid choice. Table may look like corrupted. Enter Correct value next time.");
				break;
			}
		}
	}
	
	return WriteUsers(NumberOfUsersToBeCreated , fileName);
}

#endif