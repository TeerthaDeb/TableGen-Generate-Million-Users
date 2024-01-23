/**
 * @file sort.c
 * @author Maharaj Teertha Deb , 40227747
 * @brief The header file provides functionality for sorting User Structure.
 * @date 2023-10-19
 */

#ifndef SORT_DOT_C
#define SORT_DOT_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sort.h"




void sortUsers(long int , struct User* , int);
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





/**
 * The function "comparator_First_Name" compares the first names of two User structs.
 * 
 * @param p0 The parameter p0 is a pointer to the first element being compared. In this case, it is a
 * pointer to a struct User object.
 * @param p1 The parameter p1 is a pointer to a void type. It is expected to be cast to a pointer to a
 * struct User type in order to access the FirstName member of the struct.
 * 
 * @return the result of the `strcmp` function, which is an integer value representing the comparison
 * result of the two first names.
 */
int comparator_First_Name(const void* p0, const void* p1){
	return strcmp(((struct User*) p0) -> FirstName , ((struct User *) p1) -> FirstName);
}

/**
 * The function "comparator_Last_Name" compares the last names of two User structs.
 * 
 * @param p0 A pointer to the first user object to be compared.
 * @param p1 The parameter p1 is a pointer to a void type. It is expected to be casted to a pointer to
 * a struct User type in order to access the LastName member of the struct.
 * 
 * @return the result of the `strcmp` function, which is an integer value representing the comparison
 * result of the last names of two `User` structs.
 */
int comparator_Last_Name(const void* p0, const void* p1){
	return strcmp(((struct User*) p0) -> LastName , ((struct User *) p1) -> LastName);
}

/**
 * The function "comparator_Country_Name" compares the country names of two user structures.
 * 
 * @param p0 The parameter p0 is a pointer to the first element being compared. In this case, it is a
 * pointer to a struct User object.
 * @param p1 p1 is a pointer to the first element to be compared. In this case, it is a pointer to a
 * struct User object.
 * 
 * @return the result of the comparison between the CountryName of the two User structures.
 */
int comparator_Country_Name(const void* p0, const void* p1){
	return strcmp(((struct User*) p0) -> CountryName , ((struct User *) p1) -> CountryName);
}

/**
 * The function `comparator_PhoneNumber` compares the phone numbers of two `User` structs.
 * 
 * @param p0 A pointer to the first element to be compared.
 * @param p1 The parameter p1 is a pointer to a void type. It is expected to be casted to a pointer to
 * a struct User type in order to access the PhoneNumber field of the struct.
 * 
 * @return the result of the strcmp() function, which is an integer value indicating the comparison
 * result.
 */
int comparator_PhoneNumber(const void* p0, const void* p1){
	return strcmp(((struct User*) p0) -> PhoneNumber , ((struct User *) p1) -> PhoneNumber);
}


/**
 * The function compares two users based on their SIN (Social Insurance Number).
 * 
 * @param p0 A pointer to the first user object to compare.
 * @param p1 A pointer to the first user object to be compared.
 * 
 * @return a boolean value.
 */
int comparator_SIN(const void* p0, const void* p1) {
    const struct User* user0 = (const struct User*)p0;
    const struct User* user1 = (const struct User*)p1;
    return user0 -> SIN - user1 -> SIN;
}

/**
 * The function `comparator_Password` compares the passwords of two `User` structs.
 * 
 * @param p0 The parameter `p0` is a pointer to the first element being compared. In this case, it is a
 * pointer to a `struct User` object.
 * @param p1 p1 is a pointer to the first element to be compared. In this case, it is a pointer to a
 * struct User object.
 * 
 * @return the result of the `strcmp` function, which is an integer value.
 */
int comparator_Password(const void* p0, const void* p1){
	return strcmp(((struct User*) p0) -> Password , ((struct User *) p1) -> Password);
}



/**
 * The function `sortUsers` sorts an array of `User` structures based on different criteria specified
 * by the `value` parameter.
 * 
 * @param NumberOfUsersToBeSorted The number of users that need to be sorted.
 * @param users An array of struct User, which contains information about each user.
 * @param value The "value" parameter is an integer that determines the sorting criteria.
 */
void sortUsers(long int NumberOfUsersToBeSorted , struct User* users , int value){
	if(value == 0){ 												// sort accoirding to the first name.
		qsort((void *)users,NumberOfUsersToBeSorted,(size_t)(sizeof(*users)),comparator_First_Name);
	}
	
	if(value == 1){ 												// sort according to the last name.
		qsort((void *)users,NumberOfUsersToBeSorted,(size_t)(sizeof(*users)),comparator_Last_Name);
	}

	if(value == 2){													// sort according to the Country Name.
		qsort((void *)users,NumberOfUsersToBeSorted,(size_t)(sizeof(*users)),comparator_Country_Name);
	}

	if(value == 3){													// sort according to the Phone Number.
		qsort((void *)users,NumberOfUsersToBeSorted,(size_t)(sizeof(*users)),comparator_PhoneNumber);
	}

	if(value == 4){													// sort according to the SIN.
		qsort((void *)users,NumberOfUsersToBeSorted,(size_t)(sizeof(*users)), comparator_SIN);
	}

	if(value == 5){													// sort according to the Password.
		qsort((void *)users,NumberOfUsersToBeSorted,(size_t)(sizeof(*users)), comparator_Password);
	}
}

#endif