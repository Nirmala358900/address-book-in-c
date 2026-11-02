#include <stdio.h>
#include <string.h>
#include "contact.h"

//Function definition for validatephone
int validatephone(AddressBook *addressBook , char *phone)
{
    //Checking the number is 10 digit or not
    int len = strlen(phone);
    if(len != 10)
    {
     return 0;
    } 
    
    //Checking all the characters are numeric or not
    for(int i=0 ; phone[i] != '\0' ; i++)
    {
       if(phone[i] < '0' || phone[i] > '9')
       return 0;  
    }  

    //Checking for duplicate contacts are found or not
    for(int i=0 ; i < addressBook -> contactCount ; i++)
    {
        if(strcmp(addressBook -> contacts[i].phone , phone) == 0)
         return 0; //duplicate found
        
    }
    return 1; // for all valid cases returns 1
}

//Function definition for validate email
int validate_email(AddressBook *addressBook , char *email)
{
    int atcount=0 , dotcount = 0 ;
    int atpos = -1 , dotpos = -1;
    int len = strlen(email);

    //validation for uppercase
    for(int i=0 ; i < len ; i++)
    {
        if(email[i] >= 'A' && email[i] <= 'Z')
         return 0;

        if(email[i] == '@')
        {
            atcount ++;
            atpos = i;
        }
        if(email[i] == '.')
        {
            dotcount ++;
            dotpos = i;
        }
    }
    
    //validation for @ and . only once in the email
    if(atcount <= 0 || atcount > 1)
        return 0;
    if(dotcount <=0 || dotcount > 1)
        return 0;
    
    //validation for @ and after . some char should present
    if(atpos == 0 || dotpos == len-1)
       return 0;
    
    //validation for @ should be before .
    if(atpos > dotpos)
       return 0;

    //validation between @ and . some characters should be present
    if(dotpos - atpos <= 1)
       return 0;

    //validation for duplicate
    for(int i= 0 ; i < addressBook -> contactCount ; i++) 
    {
        if(strcmp(addressBook -> contacts[i].email , email) == 0)
        return 0;
    }

    return 1; //for all valid cases
}
