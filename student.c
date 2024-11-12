#include <stdio.h>
#include <stdbool.h>

//Define a structure to store student information
struct Student {
    char name[50];
    int roll_number;
    char course[50];
    float marks;
};

int main(){
    //Array to store information of 5 students
    struct Student students[5];
    int i, roll_search;
    bool found = false;

    //Get information for each student
    printf("Please enter the student information:\n");
    for(i = 0; i < 5; i++){
        printf("\nEnter name: ");
        scanf("%s", students[i].name);

        printf("Enter roll  number: ");
        scanf("%d", &students[i].roll_number);

        printf("Enter the course name: ");
        scanf("%s", students[i].course);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    //Ask for a roll number to display specific student's information
    printf("\nPlease enter the roll number of the student to display the information: ");
    scanf("%d", &roll_search);


    //Search for the student with the entered roll number
    for(i = 0; i < 5; i++){
        if(students[i].roll_number == roll_search){
            found = true;
            printf("\nThe information of the student is:\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll number: %d\n", students[i].roll_number);
            printf("Course name: %s\n", students[i].course);
            printf("Marks: %.1f\n", students[i].marks);
            break;
        }
    }

    //If the roll number was not found
    if(!found){
        printf("No student found with roll number %d.\n", roll_search);
    }
    
    return 0;
    
}