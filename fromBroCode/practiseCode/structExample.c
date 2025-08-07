/*
    The program is designed to explain structs.
    A student struct array is introduced to hold value for a number of students.
    and displayed using function call.
*/
#include <stdio.h>
#include <string.h>  //used for strcpy
#include <stdbool.h> //needed for bool value

typedef struct{
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

void displayStudent(Student student);

int main(){

    Student student[4];
    student[0] = (Student){"James", 18, 3.7, true};
    student[1] = (Student){"Allen", 18, 3.5, false};
    student[2] = (Student){"Elena", 17, 3.9, true};
    // the values needs to be casted with (Student) since value are assigned after declaration and initialization
    // also called compound literal
    // the above could also be done together:
    // student[] = {{},{},{}};

    student[3] = (Student){0};
    strcpy(student[3].name, "Ved"); //no cast was used here since value assigning is from data type to data type
    student[3].age = 19;
    student[3].gpa = 3.4;
    student[3].isFullTime = false;

    /*  Another way for strcpy: safer alternative ; useful in buffer overflow situation
        strncpy(student.name, "Ved", sizeof(student.name) - 1);
        student.name[sizeof(student.name) - 1] = '\0';  // Ensure null termination

    */

    int size = sizeof(student) / sizeof(student[0]); //size of array student[]

    for(int i = 0; i < size; i++){
        displayStudent(student[i]);
    }
    return 0;
}

void displayStudent(Student student){
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
    printf("Is student full time: %s\n\n", ((student.isFullTime)? "Yes" : "No"));
}
