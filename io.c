/**
 * @file io.c
 * @author Maharaj Teertha Deb , 40227747
 * @brief The code Responsible for Reading files.
 * @date 2023-10-19
 */

#ifndef IO_DOT_C
#define IO_DOT_C

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "io.h"

#define LastNameLength     16
#define FirstNameLength    15
#define CountryNameLength  36
#define EmailSuffixLength  20

bool ReadFirstName();
bool ReadLastName();
bool ReadCountryName();
bool ReadEmail();

/**
 * @brief The function ReadFirstName reads a file called "first_names.txt" and stores the first names into an
 * array called firstNameFromFile.
 * 
 * @return a boolean value. It returns true if the first_names.txt file was successfully opened and the
 * first names were read and stored into the variable 'firstNameFromFile'. It returns false if there
 * was an error in opening the file.
 */
bool ReadFirstName()
{
	extern char firstNameFromFile[1001][FirstNameLength];
	extern int haveFirstNames;
	FILE *fp; // this pointer will be used to point files.
	// This code will be fetching firstname and store them into the variable 'firstNameFromFile'
    fp = fopen("first_names.txt", "r");

	/* The code  is checking if the file pointer `fp` is `NULL`, which means that the file failed
	to open. If the file failed to open, it prints an error message "Error opening the file." and then
	closes the file using `fclose(fp)`. Finally, it returns `false` to indicate that there was an error
	in opening the file. */
	if (fp == NULL) {
        printf("Error opening the first_names.txt file.\n");
        fclose(fp);
        return false;
    }

	int i = 0; // this variable will be used to iterate throughout the files.
    while (fscanf(fp, "%s", firstNameFromFile[i++]) == 1){
		//nothing to do here.
	} //Extracting the first names
	haveFirstNames = i -1;
    fclose(fp); // close when done.
	return true;
}

/**
 * @brief : The function ReadLastName reads last names from a file and stores them in an array.
 * 
 * @return a boolean value, either true or false.
 */
bool ReadLastName()
{
	extern char lastNameFromFile[1001][LastNameLength];
	extern int haveLastNames;
    FILE *fp;   // Pointer for file operations.
    fp = fopen("last_names.txt", "r");   // Open the last_names.txt file for reading.

    // Check if the file pointer is NULL (indicating an error in opening the file).
    if (fp == NULL)
    {
        printf("\nError in Opening the last_names.txt File\n");
        return false;
    }

    int i = 0;
    // Read last names from the file line by line.
    while (fgets(lastNameFromFile[i], LastNameLength - 1, fp) != NULL)
    {
        // Remove the newline character from the last name.
        lastNameFromFile[i][strcspn(lastNameFromFile[i], "\n")] = '\0';
        i++;
    }

    fclose(fp); // Close the file.

    // Update the count of available last names.
    haveLastNames = i;

    return true; // Return true to indicate successful operation.
}

/**
 * The function `ReadCountryName` reads country names from a file and stores them in an array.
 * 
 * @return a boolean value. It returns `true` if the file "countries.txt" was successfully opened and
 * read, and `false` if there was an error in opening the file.
 */
bool ReadCountryName()
{
	extern char countryNamesFromFile[200][CountryNameLength];
	extern int haveCountryNames;
	FILE *fp; // this pointer will be used to point files.
	fp=fopen ("countries.txt","r");

	/* The code  is checking if the file pointer `fp` is `NULL`, which means that the file failed
	to open. If the file failed to open, it prints an error message "Error opening the file." and then
	closes the file using `fclose(fp)`. Finally, it returns `false` to indicate that there was an error
	in opening the file. */
	if (!fp){
		printf("File countries.txt Not Found!\n");
		fclose(fp);
		return false;
	}
	int i=0;
	while (fgets(countryNamesFromFile[i], CountryNameLength - 1 , fp) != NULL) {
		countryNamesFromFile[i][strcspn(countryNamesFromFile[i], "\n")] = '\0'; // Replace newline with null terminator
		i++;
	}
	haveCountryNames = i;
	fclose(fp); // Close when Done.
	return true;
}

/**
 * @brief The function `ReadEmail` reads email suffixes from a file and stores them in an array.
 * 
 * @return a boolean value. It returns `true` if the email suffixes are successfully read from the file
 * and stored in the `email_suffix` array. It returns `false` if there was an error in opening the
 * file.
 */
bool ReadEmail()
{
	extern char email_suffix[101][EmailSuffixLength];
	extern int haveEmailAddress;
	FILE *fp;

	fp =  fopen("email_suffixes.txt" , "r");

	/* The code  is checking if the file pointer `fp` is `NULL`, which means that the file failed
	to open. If the file failed to open, it prints an error message "Error opening the file." and then
	closes the file using `fclose(fp)`. Finally, it returns `false` to indicate that there was an error
	in opening the file. */
	if(!fp){
		printf("Could not open the email_suffixes.txt file.");
		fclose(fp);
		return false;
	}

	int i = 0;

	/* The code snippet is reading email suffixes from a file and storing them in the `email_suffix`
	array. */
	while(fscanf(fp, "%s", email_suffix[i]) == 1){
		i++;
		//printf("email = %s\n" ,email_suffix[i-1]);
	}

	haveEmailAddress = i;

	fclose(fp); // close when done.

	return true;
}

#endif