#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

//Declare the Structure
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

//Function Prototypes
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
int validatephone(AddressBook *addressBook , char *phone);
int validate_email(AddressBook *addressBook , char *email);

#endif
