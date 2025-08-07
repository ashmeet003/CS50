#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

    student[3] = (Student){0};
    strcpy(student[3].name, "Ved");
    student[3].age = 19;
    student[3].gpa = 3.4;
    student[3].isFullTime = false;

    int size = sizeof(student) / sizeof(student[0]);

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
