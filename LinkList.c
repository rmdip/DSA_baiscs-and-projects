#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student Node
struct Student {
    int id;
    char name[50];
    float cgpa;
    struct Student* next;
};

// Head Pointer
struct Student* head = NULL;

// Add Student
void addStudent() {
    struct Student* newNode;
    newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter CGPA: ");
    scanf("%f", &newNode->cgpa);

    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
    } else {
        struct Student* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nStudent Added Successfully!\n");
}

// Display Students
void displayStudents() {
    struct Student* temp = head;

    if (temp == NULL) {
        printf("\nNo Students Found!\n");
        return;
    }

    printf("\n--- Student List ---\n");

    while (temp != NULL) {
        printf("ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("CGPA: %.2f\n", temp->cgpa);
        printf("-------------------\n");

        temp = temp->next;
    }
}

// Search Student
void searchStudent() {
    int id;
    printf("Enter Student ID to Search: ");
    scanf("%d", &id);

    struct Student* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("CGPA: %.2f\n", temp->cgpa);
            return;
        }

        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

// Delete Student
void deleteStudent() {
    int id;
    printf("Enter Student ID to Delete: ");
    scanf("%d", &id);

    struct Student *temp = head, *prev = NULL;

    // If head node itself holds the ID
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);

        printf("\nStudent Deleted Successfully!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // Student not found
    if (temp == NULL) {
        printf("\nStudent Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nStudent Deleted Successfully!\n");
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Manager =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("\nExiting Program...\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
