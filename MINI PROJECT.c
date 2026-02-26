#include <stdio.h>
#include <string.h>
#define MAX 100
struct Contact {
    char name[50];
    char phone[15];
};
struct Contact contacts[MAX];
int count = 0;
void addContact() {
    if(count >= MAX) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", contacts[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[count].phone);

    count++;
    printf("Contact Added Successfully!\n");
}
void viewContacts() {
    if(count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for(int i = 0; i < count; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("-------------------\n");
    }
}
void searchContact() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact Found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}
void deleteContact() {
    char deleteName[50];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    for(int i = 0; i < count; i++) {
        if(strcmp(contacts[i].name, deleteName) == 0) {
            for(int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact Deleted Successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}  
