/*
					 PHONEBOOK
			(CONTACT MANAGEMENT MADE EASY)
	A Contact management application using C language
	that allows users to manage their contacts, store
	contact information, and perform various operations
		on their contact list...

PROJECT MADE BY-
	---> TINWALA HUSSAIN S.
	---> YADAV VANSH

NOTE - Run the Code in Turbo C++
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

// Template of Structure for saving the details of a contact
struct Contact
{
	char name[50];
	char surname[50];
	char phoneNumber[15];
	char email[100];
};

// All Functions used in this Program
int saveUserCredentials(const char *filename);
int userLogin(int *success, char *username);
int new_contact();
int deleteContact(const char *filename);
int listofcontacts();
int viewContact(const char *filename, int searchBy, const char *searchKey);
int editContact(const char *filename);
int validatePhoneNumber(char *phoneNumber);
int validateemail(char email[100]);
int deleteallContacts(const char *filename);

int main()
{
	char newuser[4], username[100];
	int success = 0, z, k, l, temp;
	char menuchoice[2];
	clrscr();
	window(1, 1, 80, 25);
	textbackground(BLACK);
	clrscr();
	textcolor(6);
	gotoxy(37, 8);
	cprintf("Phone Book");
	gotoxy(27, 10);
	textcolor(7);
	cprintf("(Contact Management made Easy)");
	gotoxy(34, 12);
	textcolor(6);
	for (z = 1; z <= 17; z++)
	{
		cprintf("%c", 220);
		delay(80);
	}
	clrscr();
	gotoxy(32, 5);
	textcolor(11);
	cprintf("Welcome to Phone Book");
	gotoxy(33, 7);
	textcolor(15);
	cprintf("(Things you can Do)");
	gotoxy(2, 8);
	for (l = 1; l <= 76; l++)
	{
		printf("-");
	}
	gotoxy(2, 10);
	for (l = 1; l <= 76; l++)
	{
		printf("-");
	}
	gotoxy(2, 9);
	textcolor(12);
	for (l = 1; l <= 76; l++)
	{
		printf("*");
	}
	textcolor(15);
	for (k = 11; k <= 22; k++)
	{
		gotoxy(18, k);
		printf("|");
		gotoxy(38, k);
		printf("|");
		gotoxy(60, k);
		printf("|");
	}

	gotoxy(3, 12);
	textcolor(11);
	delay(300);
	cprintf("Add Contacts");
	gotoxy(22, 12);
	cprintf("View Contacts");
	gotoxy(43, 12);
	cprintf("Search Contacts");
	gotoxy(64, 12);
	cprintf("Edit Contacts");
	gotoxy(25, 24);
	gotoxy(2, 15);
	textcolor(15);
	delay(450);
	cprintf("Easily add your");
	gotoxy(21, 15);
	cprintf("View the list of");
	gotoxy(43, 15);
	cprintf("Easily search");
	gotoxy(64, 15);
	cprintf("Edit your");
	gotoxy(4, 16);
	delay(520);
	cprintf("Contacts");
	gotoxy(22, 16);
	cprintf("your contacts");
	gotoxy(43, 16);
	cprintf("your contacts");
	gotoxy(64, 16);
	cprintf("contacts");
	gotoxy(2, 17);
	delay(570);
	cprintf("and save them");
	gotoxy(24, 17);
	cprintf("easily at");
	gotoxy(42, 17);
	cprintf("by name,surname,");
	gotoxy(64, 17);
	cprintf("easily.");
	gotoxy(4, 18);
	delay(620);
	cprintf("securely.");
	gotoxy(24, 18);
	cprintf("one place.");
	gotoxy(40, 18);
	cprintf("phonenumber & email.");
	gotoxy(27, 24);
	textcolor(12);
	for (z = 1; z <= 30; z++)
	{
		cprintf("%c", 220);
		delay(100);
	}

	window(1, 1, 80, 25);
	textbackground(BLACK);
	clrscr();
	gotoxy(35, 3);
	printf("-------------");
	//	gotoxy(33, 4);
	//	printf("|");
	gotoxy(37, 4);
	textcolor(3);
	cprintf("PhoneBook");
	//	gotoxy(45, 4);
	// printf("|");
	gotoxy(35, 5);
	printf("-------------");
	window(10, 7, 70, 18);
	textbackground(7);
	clrscr();
	gotoxy(5, 2);
	textcolor(12);
	cprintf("Are You a new User(Yes/No) : ");
	scanf("%s", newuser);

	if (strcmp(newuser, "Yes") == 0)
	{
		saveUserCredentials("user_data.txt");
		clrscr();
		userLogin(&success, username);
	}

	else if (strcmp(newuser, "No") == 0)
	{
		userLogin(&success, username);
	}

	else
	{
		gotoxy(23, 8);
		cprintf("Enter Valid input");
		gotoxy(19, 10);
		textcolor(GREEN + BLINK);
		cprintf("Press any key to exit...");
	}

	if (success == 1)
	{
		window(1, 1, 80, 25);
		textbackground(BLACK);
		clrscr();
		textcolor(12);
		gotoxy(35, 11);
		cprintf("Welcome %s", username);
		gotoxy(35, 12);
		textcolor(15);
		for (z = 1; z <= 8; z++)
		{
			cprintf("%c ", 220);
			delay(330);
		}

		do
		{
			window(1, 1, 80, 25);
			textbackground(BLACK);
			clrscr();
			window(24, 3, 56, 21);
			textbackground(6);
			clrscr();
			window(25, 4, 55, 20);
			textbackground(7);
			clrscr();
			gotoxy(13, 2);
			textcolor(6);
			cprintf("Options");
			textcolor(BLACK);
			for (z = 1; z <= 31; z++)
			{
				gotoxy(z, 1);
				cprintf("-");
				gotoxy(z, 3);
				cprintf("-");
			}
			textcolor(8);
			gotoxy(5, 5);
			cprintf("1.Add new Contact");
			gotoxy(5, 6);
			cprintf("2.Delete a Contact");
			gotoxy(5, 7);
			cprintf("3.Search Contact");
			gotoxy(5, 8);
			cprintf("4.View List of Contacts\n");
			gotoxy(5, 9);
			cprintf("5.Edit Contact");
			gotoxy(5, 10);
			cprintf("6.Delete All Contacts");
			gotoxy(5, 11);
			cprintf("Enter 7 to exit");
			gotoxy(6, 13);
			textcolor(12);
			cprintf("Enter your Choice: ");
			scanf("%s", menuchoice);
			if (menuchoice[1] == '\0')
			{

				switch (menuchoice[0])
				{
				case '1':
				{
					temp = new_contact();
					break;
				}
				case '2':
				{
					temp = deleteContact("contacts.txt");
					break;
				}
				case '3':
				{
					int choice;
					char searchKey[50];
					clrscr();

					window(1, 1, 80, 15);
					textbackground(BLACK);
					clrscr();
					gotoxy(35, 3);
					textcolor(3);
					cprintf("SEARCH CONTACT");
					window(11, 5, 67, 25);
					textbackground(12);
					clrscr();
					window(13, 6, 65, 24);
					textbackground(7);
					clrscr();
					gotoxy(2, 4);
					textcolor(6);
					cprintf("Enter the search criteria:");
					gotoxy(5, 6);
					textcolor(8);
					printf("1. Search by Name");
					gotoxy(5, 7);
					printf("2. Search by Surname");
					gotoxy(5, 8);
					printf("3. Search by Phone Number");
					gotoxy(5, 9);
					printf("4. Search by Email");
					gotoxy(3, 11);
					printf("Enter your choice (1-4): ");
					scanf("%d", &choice);

					if (choice < 1 || choice > 4)
					{
						gotoxy(5, 14);
						cprintf("Invalid choice.");
						getch();
						break;
					}
					switch (choice)
					{
					case 1:
					{
						char searchbyname[50];
						clrscr();
						gotoxy(2, 4);
						printf("Enter the name to search: ");
						scanf("%s", searchbyname);
						temp = viewContact("contacts.txt", choice, searchbyname);
						break;
					}
					case 2:
					{
						char searchbysurname[50];
						clrscr();
						gotoxy(2, 4);
						printf("Enter the Surname to search: ");
						scanf("%s", searchbysurname);
						temp = viewContact("contacts.txt", choice, searchbysurname);
						break;
					}
					case 3:
					{
						char searchbyphoneno[15];
						clrscr();
						gotoxy(2, 4);
						printf("Enter the Phonenumber to search: ");
						scanf("%s", searchbyphoneno);
						temp = viewContact("contacts.txt", choice, searchbyphoneno);
						break;
					}
					case 4:
					{
						char searchbyemail[15];
						clrscr();
						gotoxy(2, 4);
						printf("Enter the Email Id to search: ");
						scanf("%s", searchbyemail);
						temp = viewContact("contacts.txt", choice, searchbyemail);
						break;
					}
					default:
						gotoxy(5, 14);
						cprintf("Invalid choice.");
						getch();
						break;
					}
					break;
				}
				case '4':
				{
					temp = listofcontacts();
					break;
				}
				case '5':
				{
					temp = editContact("contacts.txt");
					break;
				}
				case '6':
				{
					temp = deleteallContacts("contacts.txt");
					break;
				}
				case '7':
				{
					window(1, 1, 80, 25);
					textbackground(BLACK);
					clrscr();
					gotoxy(35, 8);
					textcolor(12);
					cprintf("Phone Book");
					gotoxy(25, 10);
					textcolor(7);
					cprintf("Thanks for using our Software");
					gotoxy(18, 15);
					cprintf("Developed by: Hussain Tinwala & Vansh Yadav");
					gotoxy(30, 17);
					textcolor(15);
					cprintf("Please wait a second...");
					gotoxy(36, 19);
					for (z = 1; z <= 6; z++)
					{
						cprintf("%c ", 248);
						delay(330);
					}

					return 0;
				}
				default:
				{
					gotoxy(8, 14);
					printf("Enter Valid Choice");
					getch();
					break;
				}
				}
			}
			else
			{
				gotoxy(8, 14);
				printf("Enter Valid Choice");
				getch();
			}
		} while (menuchoice != '6');
	}

	getch();
	clrscr();
	clrscr();

	return 0;
}

//----------------------------------//
// ******** SIGNUP FUNCTION ******** //
//----------------------------------//
int saveUserCredentials(const char *filename)
{
	char email[100], ch, password[100], username[100];
	FILE *file;
	int i = 0;

	window(1, 1, 80, 25);
	textbackground(BLACK);
	clrscr();
	gotoxy(37, 3);
	textcolor(3);
	cprintf("SIGN UP");

	// Asking for Username, Email Id and Password
	window(13, 5, 67, 25);
	textbackground(6);
	clrscr();
	window(15, 6, 65, 24);
	textbackground(7);
	clrscr();
	textcolor(12);
	gotoxy(2, 5);
	cprintf("Enter Username: ");
	scanf("%s", username);

	do
	{
		clrscr();
		textcolor(12);
		gotoxy(2, 5);
		cprintf("Enter Username: %s", username);
		gotoxy(2, 7);
		cprintf("Enter your Email ID: ");
		scanf("%s", email);

		// Validating Email Id
		// Calling Function validateemail
		if (validateemail(email))
		{
			break;
		}
		else
		{
			gotoxy(8, 10);
			textcolor(4);
			cprintf("Invalid Email Id. Please try again.");
			getch();
		}
	} while (1);

	gotoxy(2, 9);
	textcolor(RED);
	cprintf("Create password: ");
	while (1)
	{
		ch = getch();
		// Taking character value in ch
		if (ch == 13)
		{
			// Storing a null character at the end
			password[i] = '\0';
			break;
		}
		password[i++] = ch;
		// Printing stars everytime when character is entered
		printf("*");
	}

	// Creating a file for writing
	file = fopen(filename, "a");

	// Checking if the file was opened successfully
	if (file == NULL)
	{
		gotoxy(8, 12);
		printf("Error creating file.");
		return 0;
	}

	// Writing the email and password to the file
	fprintf(file, "Username: %s Email Id: %s Password: %s\n", username, email, password);

	// Closing the file
	fclose(file);

	gotoxy(6, 17);
	textcolor(GREEN + BLINK);
	cprintf("Press any key to continue...");
	getch();
	return 0;
}

//----------------------------------//
// ******** Login Function ******** //
//----------------------------------//
int userLogin(int *success, char *username)
{
	char email[100], password[100], ch;
	int i = 0;
	FILE *file = fopen("user_data.txt", "r");
	char line[200];
	int accountFound = 0;

	window(1, 1, 80, 25);
	textbackground(BLACK);
	clrscr();
	gotoxy(37, 3);
	textcolor(3);
	cprintf("SIGN IN");

	if (file == NULL)
	{
		printf("Error opening file.");
		return 0;
	}
	window(13, 5, 67, 25);
	textbackground(12);
	clrscr();
	window(15, 6, 65, 24);
	textbackground(7);
	clrscr();
	gotoxy(2, 5);
	textcolor(12);
	cprintf("Enter your email: ");
	scanf("%s", email);

	while (fgets(line, sizeof(line), file))
	{
		char storedEmail[100], ch, storedPassword[100], storedUsername[100];
		if (sscanf(line, "Username: %s Email Id: %s Password: %s", storedUsername, storedEmail, storedPassword) == 3)
		{
			// If Email entered by user and storedemail are same...
			// Then asking for password
			if (strcmp(email, storedEmail) == 0)
			{
				accountFound = 1;

				strcpy(username, storedUsername);
				gotoxy(2, 7);
				textcolor(RED + BLINK);
				cprintf("Enter your password: ");
				while (1)
				{
					// Taking character value in ch
					ch = getch();
					if (ch == 13)
					{
						// Storing a null character at the end
						password[i] = '\0';
						break;
					}
					password[i++] = ch;
					// Printing stars everytime when character is entered
					printf("*");
				}
				if (strcmp(password, storedPassword) == 0)
				{
					gotoxy(19, 17);
					textcolor(GREEN);
					cprintf("Login successful!");
					fclose(file);
					// Updating the value of success to acces the phonebook
					*success = 1;
					gotoxy(22, 18);
					cprintf("Please Wait...");
					delay(300);
					return 0;
				}
				else
				{
					gotoxy(19, 12);
					textcolor(RED);
					cprintf("Invalid password.");
					*success = 0;
					gotoxy(15, 14);
					textcolor(GREEN + BLINK);
					cprintf("Press any key to exit...");
					getch();
					fclose(file);
					return 0;
				}
			}
		}
	}

	fclose(file);

	// If email was not found or is not valid
	if (accountFound == 0)
	{
		gotoxy(18, 9);
		textcolor(RED + BLINK);
		cprintf("Invalid Email ID\n");
		gotoxy(15, 11);
		textcolor(GREEN + BLINK);
		cprintf("Press any key to exit...");
		getch();
		return 0;
	}

	return 0;
}

//----------------------------------//
// ******** ADD CONTACT FUNCTION ******** //
//----------------------------------//
int new_contact()
{
	// Declaring a Contact structure to save the new contact information
	struct Contact newContact;
	FILE *file;
	window(1, 1, 80, 25);
	textbackground(BLACK);
	clrscr();
	gotoxy(35, 3);
	textcolor(3);
	cprintf("ADD CONTACT");

	// Taking Input for new contact details
	window(11, 5, 67, 25);
	textbackground(12);
	clrscr();
	window(13, 6, 65, 24);
	textbackground(7);
	clrscr();
	gotoxy(2, 3);
	textcolor(8);
	cprintf("Enter the following information for the new contact\n");
	gotoxy(3, 7);
	textcolor(6);
	cprintf("Name: ");
	scanf("%s", newContact.name);
	gotoxy(3, 8);
	cprintf("Surname: ");
	scanf("%s", newContact.surname);

	// Loop if the phonenumber is not valid
	do
	{
		clrscr();
		gotoxy(2, 3);
		textcolor(8);
		cprintf("Enter the following information for the new contact\n");
		gotoxy(3, 7);
		textcolor(6);
		cprintf("Name: %s", newContact.name);
		gotoxy(3, 8);
		cprintf("Surname: %s", newContact.surname);
		gotoxy(3, 9);
		cprintf("Phone Number(10-Digits): ");
		scanf("%s", newContact.phoneNumber);

		if (validatePhoneNumber(newContact.phoneNumber))
		{
			break; // Exit the loop if the phone number is valid
		}
		else
		{
			gotoxy(8, 11);
			textcolor(4);
			cprintf("Invalid phone number. Please try again.");
			getch();
		}
	} while (1);

	// Loop if the email id is invalid
	do
	{
		clrscr();
		gotoxy(2, 3);
		textcolor(8);
		cprintf("Enter the following information for the new contact");
		gotoxy(3, 7);
		textcolor(6);
		cprintf("Name: %s", newContact.name);
		gotoxy(3, 8);
		cprintf("Surname: %s", newContact.surname);
		gotoxy(3, 9);
		cprintf("Phone Number(10-Digits): %s", newContact.phoneNumber);
		gotoxy(3, 10);
		cprintf("Email: ");
		scanf("%s", newContact.email);
		if (validateemail(newContact.email))
		{
			break;
		}
		else
		{
			gotoxy(8, 11);
			textcolor(4);
			cprintf("Invalid Email Id. Please try again.");
			getch();
		}
	} while (1);

	// Opening the file in append mode for printing the contacts
	file = fopen("contacts.txt", "a");

	if (file == NULL)
	{
		gotoxy(10, 13);
		cprintf("Error opening the file.\n");
		return 0;
	}

	// Writing the new contact to the file
	fprintf(file, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n", newContact.name, newContact.surname, newContact.phoneNumber, newContact.email);

	// Closing the file
	fclose(file);
	gotoxy(17, 17);
	textcolor(8);
	cprintf("Contact saved successfully!\n");

	getch();
	return 0;
}

//--------------------------------------------//
// ******** LIST OF CONTACTS FUNCTION ******** //
//-------------------------------------------//
int listofcontacts()
{
	FILE *fp;
	int i = 6, z = 0;
	struct Contact cont;
	window(1, 1, 80, 25);
	textbackground(15);
	clrscr();
	textcolor(6);
	gotoxy(35, 2);
	cprintf("List of Contacts");
	textcolor(BLACK);
	gotoxy(1, 3);

	// Only for Design
	for (z = 1; z <= 80; z++)
	{
		cprintf("-");
	}
	gotoxy(1, 5);
	for (z = 1; z <= 80; z++)
	{
		cprintf("-");
	}
	for (z = 4; z <= 24; z++)
	{
		gotoxy(18, z);
		cprintf("|");
		gotoxy(35, z);
		cprintf("|");
		gotoxy(55, z);
		cprintf("|");
	}
	textcolor(4);
	gotoxy(5, 4);
	cprintf("Name");
	gotoxy(22, 4);
	cprintf("Surname");
	gotoxy(38, 4);
	cprintf("Phone Number");
	gotoxy(59, 4);
	cprintf("Email Id");
	textcolor(8);
	// Opening the file in reading mode for reading the contacts...
	fp = fopen("contacts.txt", "r");
	if (fp == NULL)
	{
		gotoxy(28, 12);
		printf("Failed to open the file.\n");
		return 1;
	}

	// Scanning the Contacts from the file and printing them...
	while (fscanf(fp, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n", cont.name, cont.surname, cont.phoneNumber, cont.email) == 4)
	{
		textcolor(8);
		gotoxy(4, i);
		cprintf("%s", cont.name);
		gotoxy(21, i);
		cprintf("%s", cont.surname);
		gotoxy(38, i);
		cprintf("%s", cont.phoneNumber);
		gotoxy(57, i);
		cprintf("%s", cont.email);
		i = i++;
	}

	// Closing the file
	fclose(fp);
	gotoxy(2, 25);
	textcolor(RED + BLINK);
	cprintf("Press any key to go to Options...");
	getch();
	return 0;
}

//--------------------------------------------//
// ******** DELETE CONTACT FUNCTION ******** //
//-------------------------------------------//
int deleteContact(const char *filename)
{
	struct Contact cont;
	// Opening the contacts.txt file in reading mode
	FILE *originalFile = fopen(filename, "r");
	// Opening the temp.txt file in writing mode
	FILE *tempFile = fopen("temp.txt", "w");
	char contactNameToDelete[50];
	int deletesuccess = 0;

	window(1, 1, 80, 15);
	textbackground(BLACK);
	clrscr();
	gotoxy(35, 3);
	textcolor(3);
	cprintf("DELETE CONTACT");
	window(11, 5, 67, 25);
	textbackground(12);
	clrscr();
	window(13, 6, 65, 24);
	textbackground(7);
	clrscr();
	gotoxy(2, 4);
	textcolor(8);
	cprintf("Enter the name of the contact to delete: ");
	scanf("%s", contactNameToDelete);

	if (originalFile == NULL || tempFile == NULL)
	{
		gotoxy(8, 7);
		printf("Error opening files.\n");
		return 0;
	}

	while (fscanf(originalFile, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n",
				  cont.name, cont.surname, cont.phoneNumber, cont.email) == 4)
	{

		if (strcmp(cont.name, contactNameToDelete) != 0)
		{
			// Writing the contacts to the temporary file if it's not the one to be deleted
			fprintf(tempFile, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n",
					cont.name, cont.surname, cont.phoneNumber, cont.email);
		}
		else
		{
			deletesuccess = 1;
			gotoxy(15, 9);
			textcolor(GREEN);
			cprintf("Contact Deleted successfully");
		}
	}
	fclose(originalFile);
	fclose(tempFile);

	// If Contact not found...
	if (deletesuccess == 0)
	{
		gotoxy(19, 9);
		textcolor(RED);
		cprintf("Contact Not found");
	}

	// Removing the original file
	remove(filename);

	// Renaming the temporary file to the original file
	rename("temp.txt", filename);

	gotoxy(12, 14);
	textcolor(GREEN + BLINK);
	cprintf("Press any key to go to options...");
	getch();
	return 0;
}

//--------------------------------------------//
// ******** SEARCH CONTACT FUNCTION ******** //
//-------------------------------------------//
int viewContact(const char *filename, int searchBy, const char *searchKey)
{
	struct Contact cont;
	int found = 0;
	// Opening file in reading mode
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error opening the file.\n");
		return 0;
	}

	// Scanning the Contacts from the file
	while (fscanf(file, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n",
				  cont.name, cont.surname, cont.phoneNumber, cont.email) == 4)
	{

		int match = 0;

		switch (searchBy)
		{
		case 1: // Search by name
			match = (strcmp(cont.name, searchKey) == 0);
			break;
		case 2: // Search by surname
			match = (strcmp(cont.surname, searchKey) == 0);
			break;
		case 3: // Search by phone number
			match = (strcmp(cont.phoneNumber, searchKey) == 0);
			break;
		case 4: // Search by email
			match = (strcmp(cont.email, searchKey) == 0);
			break;
		default:
			gotoxy(20, 8);
			cprintf("Invalid choice.");
			getch();
			fclose(file);
			break;
		}

		if (match)
		{
			gotoxy(21, 6);
			textcolor(8);
			cprintf("Contact found\n");
			gotoxy(4, 8);
			cprintf("Name: %s\n", cont.name);
			gotoxy(4, 9);
			cprintf("Surname: %s\n", cont.surname);
			gotoxy(4, 10);
			cprintf("Phone Number: %s\n", cont.phoneNumber);
			gotoxy(4, 11);
			cprintf("Email: %s\n", cont.email);
			found = 1;
			break;
		}
	}

	fclose(file);

	if (!found)
	{
		gotoxy(20, 8);
		cprintf("Contact not found.\n");
	}
	gotoxy(12, 14);
	textcolor(GREEN + BLINK);
	cprintf("Press any key to go to options...");

	getch();
	return 0;
}

//--------------------------------------------//
// ******** EDIT CONTACT FUNCTION ******** //
//-------------------------------------------//
int editContact(const char *filename)
{
	struct Contact cont;
	FILE *originalFile = fopen(filename, "r");
	FILE *tempFile = fopen("temp.txt", "w");
	char contactNameToEdit[50];
	int editsuccess = 0, editchoice;

	window(1, 1, 80, 15);
	textbackground(BLACK);
	clrscr();
	gotoxy(35, 3);
	textcolor(3);
	cprintf("EDIT CONTACT");
	window(11, 5, 67, 25);
	textbackground(12);
	clrscr();
	window(13, 6, 65, 24);
	textbackground(7);
	clrscr();
	gotoxy(2, 4);
	// Asking for the contact name to edit
	printf("Enter the name of contact to edit: ");
	scanf("%s", contactNameToEdit);
	// Scanning the file and storing it in the structure
	while (fscanf(originalFile, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n",
				  cont.name, cont.surname, cont.phoneNumber, cont.email) == 4)
	{

		if (strcmp(cont.name, contactNameToEdit) == 0)
		{
			// If Contact found, printing it...
			gotoxy(21, 6);
			textcolor(6);
			cprintf("Contact Found");
			textcolor(8);
			gotoxy(6, 8);
			cprintf("Name: %s", cont.name);
			gotoxy(6, 9);
			cprintf("Surname: %s", cont.surname);
			gotoxy(6, 10);
			cprintf("Phone Number: %s", cont.phoneNumber);
			gotoxy(6, 11);
			cprintf("Email: %s", cont.email);
			gotoxy(12, 15);
			textcolor(GREEN + BLINK);
			cprintf("Press any key to edit this contact...");
			getch();
			textcolor(6);
			cprintf(" ");
			clrscr();
			gotoxy(2, 4);
			textcolor(6);
			cprintf("Enter the choice to edit");
			gotoxy(5, 6);
			textcolor(8);
			cprintf("1. Edit name");
			gotoxy(5, 7);
			cprintf("2. Edit surname");
			gotoxy(5, 8);
			cprintf("3. Edit phonenumber");
			gotoxy(5, 9);
			cprintf("4. Edit email id");
			textcolor(6);
			// Allowing to edit the contacts
			gotoxy(5, 11);
			cprintf("Enter your choice: ");
			scanf("%d", &editchoice);
			switch (editchoice)
			{
			case 1: // Edit name
			{
				gotoxy(5, 13);
				cprintf("Enter the new name: ");
				scanf("%s", cont.name);
				break;
			}
			case 2: // Edit surname
			{
				gotoxy(5, 13);
				cprintf("Enter the new surname: ");
				scanf("%s", cont.surname);
				break;
			}
			case 3: // Edit phone number
			{
				while (1)
				{
					clrscr();
					gotoxy(5, 13);
					cprintf("Enter the new phonenumber: ");
					scanf("%s", cont.phoneNumber);
					if (validatePhoneNumber(cont.phoneNumber))
					{
						break;
					}
					else
					{
						gotoxy(9, 15);
						cprintf("Invalid Phonenumber, Please try again.");
						getch();
					}
				}
				break;
			}
			case 4: // Edit email
			{
				while (1)
				{
					clrscr();
					gotoxy(5, 13);
					cprintf("Enter the new email id: ");
					scanf("%s", cont.email);
					if (validateemail(cont.email))
					{
						break;
					}
					else
					{
						gotoxy(9, 15);
						cprintf("Invalid Email Id, Please try again.");
						getch();
					}
				}
				break;
			}
			default:
			{
				gotoxy(20, 13);
				cprintf("Invalid choice.");
				fclose(originalFile);
				remove("temp.txt");
				getch();
				// break;
				return 0;
			}
			}

			// Writing the modified contact details to the temporary file
			fprintf(tempFile, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n",
					cont.name, cont.surname, cont.phoneNumber, cont.email);
			editsuccess = 1;
		}
		else
		{
			// Writing unchanged contacts to the temporary file
			fprintf(tempFile, "Name: %s Surname: %s Phonenumber: %s Email Id: %s\n",
					cont.name, cont.surname, cont.phoneNumber, cont.email);
		}
	}
	fclose(originalFile);
	fclose(tempFile);

	if (editsuccess == 0)
	{
		gotoxy(10, 7);
		textcolor(RED);
		printf("Contact not found for editing.\n");
		remove("temp.txt");
	}
	else
	{
		// Renaming the temporary file to the original file
		remove(filename);
		rename("temp.txt", filename);
		gotoxy(9, 15);
		textcolor(GREEN);
		cprintf("Contact information updated successfully.\n");
		gotoxy(5, 17);
		textcolor(RED + BLINK);
		cprintf("Press any key to go to options...");
	}
	getch();
	return 0;
}

//--------------------------------------------//
// ******** VALIDATE PHONENUMBER FUNCTION ******** //
//-------------------------------------------//
int validatePhoneNumber(char *phoneNumber)
{
	int length = strlen(phoneNumber), i;

	// Checking if the length is valid (10 digits excluding country code)
	if (length != 10)
	{
		return 0;
	}

	// Checking if all characters are digits
	for (i = 0; i < length; i++)
	{
		if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
		{
			return 0;
		}
	}

	// Returning true if Valid phone number
	return 1;
}

//--------------------------------------------//
// ******** VALIDATE EMAIL FUNCTION ******** //
//-------------------------------------------//
int validateemail(char email[100])
{
	int len = strlen(email), i, flag = 0, dotflag = 0;
	if (len <= 10)
	{
		return 0;
	}
	for (i = 0; i < len; i++)
	{
		if (email[i] == '@')
		{
			flag = 1;
		}
		if (email[i] == '.')
		{
			dotflag = 1;
		}
	}
	if (dotflag == 1 && flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//--------------------------------------------//
// ******** DELETE ALL CONTACTS FUNCTION ******** //
//-------------------------------------------//
int deleteallContacts(const char *filename)
{
	FILE *originalFile = fopen(filename, "r");
	FILE *tempFile = fopen("temp.txt", "w");
	char contactNameToDelete[50];
	int z = 0;

	window(1, 1, 80, 15);
	textbackground(BLACK);
	clrscr();
	gotoxy(31, 3);
	textcolor(3);
	cprintf("DELETE ALL CONTACTS");
	window(11, 5, 67, 25);
	textbackground(12);
	clrscr();
	window(13, 6, 65, 24);
	textbackground(7);
	clrscr();
	gotoxy(16, 4);
	textcolor(8);
	cprintf("Deleting All Contacts");
	gotoxy(18, 6);
	cprintf("Just a second....");
	gotoxy(23, 12);
	for (z = 1; z <= 5; z++)
	{
		textcolor(RED);
		cprintf("%c ", 220);
		delay(330);
	}

	if (originalFile == NULL || tempFile == NULL)
	{
		gotoxy(8, 7);
		printf("Error opening files.\n");
	}
	fclose(originalFile);
	fclose(tempFile);

	// Renaming the temporary file to the original file
	// Removing the original file
	remove(filename);
	rename("temp.txt", filename);
	gotoxy(12, 14);
	textcolor(GREEN);
	cprintf("All Contacts Deleted Successfully");
	gotoxy(12, 14);
	delay(330);
	return 0;
}
