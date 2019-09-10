//Terrance Rutledge: This program is a contact management system. It adds and removes contacts while adding or removing information. It also counts the number of contacts and prints them.

#include "contact.h" 

/////////////////////////////////////////////////////////////////////////////////////////////
// add a new contact to your list of contacts
//	   1. Make sure a contact by that name does not exist (print an error message and exit if it exists)
//	   2. Add a new contact with that name (add-at-front)
Contact* addContact(Contact *myContacts, char *contactName) {
	Contact *newNode = malloc(sizeof(Contact));
	newNode->name = malloc(strlen(contactName)+1);
	strcpy(newNode->name, contactName);
	//if(strcmp(myContacts->name, contactName)==0){
	//	printf("Contact already exists");
	//	exit(0);
	//}
	newNode->next = myContacts;
	return newNode;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a new piece of inforamtion to the specified contact
//   1. Make sure a contact by that name exists (so you can add information to it)
//   2. If the informational item already exists, update the information's value to the new value
//   3. Otherwise, add the piece of information to the end of the contact's information list (add-at-end)

void addInformation(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {
	Contact *newNode = (Contact *) malloc (sizeof(Contact));
	newNode->name = (char *) malloc (sizeof(char) * (strlen(contactName)+1));
	newNode->information = (Info *) malloc (sizeof(Info));
	strcpy(newNode->name, infoName);
	newNode->next = NULL;
	return;

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// prints all the information for a given contact
//	1. Make sure a contact with that name exists
//	2. Print the name of the contact
//	3. print all the informational items <name|value> associated with that contact
void printContact(Contact *myContacts, char *contactName) {
	while(myContacts){
		printf("%s\n", myContacts->name);
		myContacts = myContacts->next;
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// returns the size of a given contact list
//	Iterate through the contact list to count the number of contacts, return that count
int count(Contact *myContacts) {
	if(myContacts == NULL) return 0;
	return 1 + count(myContacts->next);
}


/////////////////////////////////////////////////////////////////////////////////////////////
// prints all your contacts
//	For each contact
//	   a.  Print the name of the contact
//	   b.  Print all the <information name|information value> pairs in that contact
//	Note: this code can call other functions as needed
void print(Contact *myContacts) {
	while(myContacts){
		printf("%s\n", myContacts->name);
		myContacts = myContacts->next;
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// add a new contact (in alphabetical order)
//	1. Make sure a contact by that name does not exist 
//	2. Add a new contact with that name (add-in-order)
Contact *addContactOrdered(Contact *myContacts, char *contactName) {
	Contact *newNode = (Contact *) malloc ( sizeof(Contact) );
	newNode->name = (char *) malloc ( sizeof(char) * (strlen(contactName)+1) );
	strcpy(newNode->name, contactName);
	newNode->next = myContacts;

	if (myContacts == NULL)
		return newNode;

	if ( strcmp(contactName, myContacts->name) < 0 ) {
		newNode->next = myContacts;
		return newNode;
	}

	Contact *prev = myContacts;
	Contact *next = myContacts->next;
	while (next && strcmp(next->name, contactName) < 0) {
		prev = next;
		next = next->next;
	}

	prev->next = newNode;
	newNode->next = next;
	return myContacts;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// adds a new info to the specified contact (in alphabetical order)
//	1. Make sure a contact by that name exists (so you can add an info to it)
//	2. If the informational item already exists, update the item (replace its value with the new value)
//	3. Otherwise, add the new info to the contact (add-in-order)
void addInformationOrdered(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {
	Contact *newNode = (Contact *) malloc (sizeof(Contact));
	newNode->name = contactName;
	newNode->name = infoValue;
	newNode->next = NULL;

	if(myContacts == NULL) return;

	if(infoName > myContacts->name){
		newNode->next = myContacts;
	}

	Contact *after = myContacts;
	Contact *before = myContacts->next;
	while(before && before->name > infoName){
		after = before;
		before = before->next;
	}
	after->next = newNode;
	newNode->next = before;

	return;


	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// remove information from a contact
//	1. Make sure a contact with that name exists
//	2. Make sure the informational item exists in that contact
//	3. Remove that piece of information from the contact
void removeInformation(Contact *myContacts, char *contactName, char *infoName) {
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// remove a contact (and all the informational items for that contact)
//	1. Make sure a contact with that name exists
//	2. Remove that contact 
Contact *removeContact(Contact *myContacts, char *contactName) {

	if(myContacts == NULL) return myContacts;
	if(strcmp(myContacts->name, contactName)==0){
		Contact *ptr = myContacts->next;
		free(myContacts->name);
		free(myContacts);
		return ptr;
	}

	Contact *prev = myContacts;
	Contact *curr = myContacts->next;
	while(curr && (strcmp(curr->name, contactName) != 0)){
		prev = curr;
		curr = curr->next;
	}
	if(curr == NULL) return myContacts;
	prev->next = curr->next;
	free(curr->name);
	free(curr);

	return myContacts;

	return NULL;
}
