#include <stdio.h>
#include <stdlib.h>
#include "records.h"

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int option;

    do {
        printf("\n1. Add record\n");
        printf("2. Find record by phone number\n");
        printf("3. Delete record by phone number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                findStudentByPhoneNumber(students, numStudents);
                break;
            case 3:
                deleteStudentByPhoneNumber(students, &numStudents);
                break;
            case 4:
                // Save data to file
                FILE *file = fopen("data.txt", "w");
                if (file != NULL) {
                    fwrite(students, sizeof(Student), numStudents, file);
                    fclose(file);
                    printf("Data saved to file successfully.\n");
                } else {
                    printf("Error opening file for writing.\n");
                }
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}