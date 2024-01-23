/**
 * @file sort.h
 * @author Maharaj Teertha Deb , 40227747
 * @brief The header file provides functionality for sorting User Structure.
 * @date 2023-10-19
 */



#ifndef SORT_DOT_H
#define SORT_DOT_H

#define LastNameLength     16
#define FirstNameLength    15
#define CountryNameLength  36
#define EmailSuffixLength  20
#define PhoneNumberLength  10
#define PasswordLength     16

/**
 * The above code defines a struct called User that contains various fields for storing user
 * information.
 * @property {char} FirstName - A character array to store the first name of the user. The length of
 * the array is defined by the constant FirstNameLength.
 * @property {char} LastName - The LastName property is a character array that represents the last name
 * of a user.
 * @property {char} CountryName - The CountryName property is a character array that represents the
 * name of the country where the user is located.
 * @property {char} PhoneNumber - The PhoneNumber property is a character array that stores the phone
 * number of a user.
 * @property {long int} SIN - SIN stands for Social Insurance Number. It is a unique identification
 * number assigned to individuals in Canada for various government programs and services.
 * @property {char} Password - The "Password" property is a character array that stores the password
 * for a user.
 */
struct User
{
	char FirstName[FirstNameLength];
	char LastName[LastNameLength];
	char CountryName[CountryNameLength];
	char PhoneNumber[PhoneNumberLength];
	long int SIN;
	char Password[PasswordLength];
};
void sortUsers(long int , struct User* , int);

#endif