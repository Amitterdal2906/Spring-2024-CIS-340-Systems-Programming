#ifndef RECORDS_H
#define RECORDS_H

#define MAX_NAME_LENGTH 50
#define PHONE_NUMBER_LENGTH 20
#define MAX_STUDENTS 100

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char middleInitial;
    char lastName[MAX_NAME_LENGTH];
    float GPA;
    long int phoneNumber;
} Student;

void addStudent(Student students[], int *numStudents);
void findStudentByPhoneNumber(Student students[], int numStudents);
void deleteStudentByPhoneNumber(Student students[], int *numStudents);

#endif /* RECORDS_H */