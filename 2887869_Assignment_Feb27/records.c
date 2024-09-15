#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"


void addStudent(Student students[], int *numStudents) {
    if (*numStudents < MAX_STUDENTS) {
        printf("Enter first name: ");
        scanf("%s", students[*numStudents].firstName);
        
        printf("Enter middle initial: ");
        scanf(" %c", &students[*numStudents].middleInitial);
        
        
        // Clear input buffer
        while(getchar() != '\n');

        printf("Enter last name: ");
        scanf("%s", students[*numStudents].lastName);
        
        printf("Enter GPA: ");
        scanf("%f", &students[*numStudents].GPA);
        
        printf("Enter phone number: ");
        scanf("%ld", &students[*numStudents].phoneNumber);
        (*numStudents)++;
        printf("Record added successfully.\n");
    } else {
        printf("Cannot add more Records. Maximum limit reached.\n");
    }
}

void findStudentByPhoneNumber(Student students[], int numStudents) {
    long int phoneNumber;
    printf("Enter phone number to search: ");
    scanf("%ld", &phoneNumber);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].phoneNumber == phoneNumber) {
            printf("Record found:\n");
            printf("Name: %s %c %s\n", students[i].firstName, students[i].middleInitial, students[i].lastName);
            printf("GPA: %.2f\n", students[i].GPA);
            printf("Phone number: %ld\n", students[i].phoneNumber);
            return;
        }
    }
    printf("Record with phone number %ld not found.\n", phoneNumber);
}

void deleteStudentByPhoneNumber(Student students[], int *numStudents) {
    long int phoneNumber;
    printf("Enter phone number to delete: ");
    scanf("%ld", &phoneNumber);
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].phoneNumber == phoneNumber) {
            for (int j = i; j < *numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            (*numStudents)--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record with phone number %ld not found.\n", phoneNumber);
}