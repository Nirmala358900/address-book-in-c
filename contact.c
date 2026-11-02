
/* 
   Name: Nirmala B
   Date: 03/10/2026
   Project Title: AddressBook
   Description: AddressBook is a console-based application developed in C that allows users to store,
   manage,and search contact information efficiently.It uses file handling for persistent storage and
   provides operations like Create,Edit,Delete,Search,and List contacts.

*/

//File which contains all the function definitions

//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"


//Function definition for list of contacts
void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
     printf("NAME\t\t\tPHONE\t\tEMAIL\n");

    //printing list of contacts available in the AddressBook
    for(int i=0 ; i < addressBook -> contactCount ; i++)
    {
        printf("%-20s %-15s %s\n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
    }
    
}

//Function definition for Loading the contacts from the file
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
  
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

//Function definition for Creating the contacts
void createContact(AddressBook *addressBook)
{
	//The logic to create a Contacts 

    //Declare the string 
    char str[100];
    printf("Enter the name: ");

    //Reading Name from the User
    scanf(" %[^\n]" ,str);

    //copying the User entered Name to the AddressBook 
    strcpy(addressBook -> contacts[addressBook -> contactCount].name,str);
    
    int valid_phone; 
    //validation for the phone number
    do{
        printf("Enter the Phone: ");

        //Reading Phone from the User
        scanf("%s" ,str);

        //Call the Validationphone function  
        valid_phone = validatephone(addressBook ,str);

        //enters the loop if return value is 0,loop continues until user enter the valid phone
        if(!valid_phone)
            printf("Invalid Phone details,Enter the correct details \n");
    }while(!valid_phone);

    //copying the User entered Phone to the AddressBook 
    strcpy(addressBook -> contacts[addressBook -> contactCount].phone, str);

    int valid_email;
     //Validation for Email 
    do{
        printf("Enter the email: ");

        //Reading email from the User
        scanf("%s" ,str);

        //Call the Validationemail function
        valid_email = validate_email(addressBook , str);

        //enters the loop if return value is 0,loop continues until user enter the valid email
        if(!valid_email)
            printf("Invalid Email , Enter the correct email details\n");
    }while(!valid_email);    

    //copying the User entered email to the AddressBook
    strcpy(addressBook -> contacts[addressBook -> contactCount].email,str);

    //Increment the contactcount in the AddressBook
    addressBook -> contactCount ++;

    //Message for correct execution
    printf("Create contact Successful");
    
}


//Function definition for Searching the contacts
int searchContact(AddressBook *addressBook) 
{
    //The logic for searching the contacts

    //Declare the string 
    char str[100];
    int menu;
    char *ret;

    //Ask the user to enter the option
    int found = 0;
    printf("1.search by Name\n");
    printf("2.search by phone\n");
    printf("3.search by email\n ");
    printf("Enter your choice :");
    scanf("%d" ,&menu);

    //Depending on the user choice respective case will execute
    switch(menu)
    {
        //Serching based on the name
        case 1:
        {
            printf("Enter the name to be searched: ");
            scanf(" %[^\n]" ,str);
            
            //Run the loop less than contactcount times
            for(int i=0 ; i < addressBook -> contactCount ; i++)
            {
                //returns 1, if the entered substring found in the AddressBook
                ret = strcasestr(addressBook -> contacts[i].name,str);
                if(ret) //if return value is 1,then enters the loop
                {
                    printf("%d. ",i);
                    printf("%s %s %s",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                    found = 1;
                }
            }
            break;
        }  

        //Serching based on the phone
        case 2: 
        {
            printf("Enter the phone number to be searched: ");
            scanf("%s" ,str);

            //Run the loop less than contactcount times
            for(int i=0 ; i < addressBook -> contactCount ; i++)
            {
                //returns 1, if the entered substring found in the AddressBook
                ret = strcasestr(addressBook -> contacts[i].phone,str);
                if(ret) //if return value is 1,then enters the loop
                {
                    printf("%d. ",i);
                    printf("%s %s %s",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
                    found = 1;
                }
            }
            break;               
        }

        //Serching based on the email
        case 3: 
        {
            printf("Enter the email to be searched: ");
            scanf("%s" ,str);

            //Run the loop less than contactcount times
            for(int i=0 ; i < addressBook -> contactCount ; i++)
            {
                //returns 1, if the entered substring found in the AddressBook
                ret = strcasestr(addressBook -> contacts[i].email,str);
                if(ret) //if return value is 1,then enters the loop
                {
                    printf("%d. ",i);
                    printf("%s %s %s",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
            
                    found = 1;
                }
            }  
            break;  
        }
        default :
        printf("Inavlid Input");
    }

    //There is no contact present in the AddressBook return 0
    if(!found)
    {
        printf("Contact not found");
        return 0;
    }

    //There is a contact present in the AddressBook return 1
        return 1;
}


//Function definition for editing the contacts
void editContact(AddressBook *addressBook)
{
	//The logic for Editing contact 

    //call the search function,depending on the return value from the search nezt execution takes place
    int ret = searchContact(addressBook);

    //The return value is 1
    if(ret == 1)
    {
       int index;
       printf("\n");
       printf("Enter the index want to edit: \n");

       //Ask the user to edit 
       scanf("%d",&index);
       int option;
       printf("Enter the option by which you want to edit: ");
       printf("\n");
       printf("1. Edit by name\n");
       printf("2. Edit by phone\n");
       printf("3. Edit by email\n");
       scanf("%d" ,&option);

       int valid_phone;
       int valid_email;

       if(option == 1)
       {
         printf("Edit the information: \n");
         char str[50];
         scanf(" %[^\n]",str);

         //copy the enterd name to the previous contact
         strcpy(addressBook -> contacts[index].name, str);
       }

       else if(option == 2)
       {
         char str[50];
         do{
             printf("Enter the Phone: ");
             scanf("%s" ,str);

              //Call the validphone function for entering the valid phone 
             valid_phone = validatephone(addressBook ,str);
             if(!valid_phone)
                 printf("Invalid Phone details,Enter the correct details \n");
         }while(!valid_phone);
         
         //copy the enterd name to the previous contact
         strcpy(addressBook -> contacts[index].phone, str);
        }

        else if(option == 3)
        {
         char str[50];
         do{
              printf("Enter the email: ");
              scanf("%s" ,str);
              valid_email = validate_email(addressBook , str);
             //Call the validphone function for entering the valid phone 
              if(!valid_email)
                  printf("Invalid Email , Enter the correct email details\n");
         }while(!valid_email);    
          //copy the enterd name to the previous contact
         strcpy(addressBook -> contacts[index].email, str);
       }

       else
       {
         printf("Enter the valid choice: ");
       }

       //Print the Index number,which helps for deleting
        printf("Index Value :%d\n",index);
        printf("The Edit contact successfull");
    }

    //The return value is 0,prints the below message
    else
    {
        printf(" Can't perform the edit option: ");   
    }   
    
}

//Function definition for editing the contacts
void deleteContact(AddressBook *addressBook)
{
	//The logic for deleting the contacts

    //call the search function,depending on the return value from the search nezt execution takes place
    int ret = searchContact(addressBook);

    //The return value is 1
    if(ret == 1)
    {
       int index;
       printf("\n");
       printf("Enter the index want to delete: \n");
       scanf("%d",&index);  //Based on the index value contact gets deleted
       char sure;
       printf("Are you sure you want to delete this number: ('Y' or 'N')");
       scanf(" %c",&sure);
       if(sure == 'Y' || sure == 'y')
       {
        //Shifting of contacts takes place
          for(int i = index ; i < addressBook -> contactCount - 1 ; i++ )
          {
               addressBook -> contacts[i] = addressBook -> contacts[i + 1];  
          }
           printf("The contact deleted successfully");
       }
       else
       {
          deleteContact(addressBook);
        }  

        //Decrement the contact count
       addressBook -> contactCount -- ;  
    }

    else
    {
        printf("The contact is not found to delete\n");
    }
        
}
