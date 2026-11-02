#include <stdio.h>
#include<stdlib.h>
#include "file.h"

//Function Definition for savecontacts to the AddressBook
void saveContactsToFile(AddressBook *addressBook) {

    //Open the file in write mode
    FILE *fptr = fopen("contacts.csv" , "w");

    //Validation
    if(fptr == NULL)
     return ;

    //print the contactcount to the AddressBook
    fprintf(fptr,"%d\n",addressBook -> contactCount);

    //Loop for printing the contacts
    for(int i=0; i < addressBook -> contactCount ; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
    }

    //close the file
    fclose(fptr);
  
}

//Function Definition for loading the contacts to the AddressBook
void loadContactsFromFile(AddressBook *addressBook) {

    //Open the file in read mode
    FILE *fptr = fopen("contacts.csv" , "r");

    //Validation
    if(fptr == NULL)
    {
        return;
    }

    //read the contactcount from the csv file
    fscanf(fptr,"%d\n",&(addressBook -> contactCount));
    
    //Loop for raeding the contacts
    for(int i=0; i < addressBook -> contactCount ; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
    }

    //close the file
    fclose(fptr);    
}
