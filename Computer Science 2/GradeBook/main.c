//Benjamin Jimenez

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define Chunk 2

int main()
{
    course1 = 1, grade1 = 1, enroll1 = 1, student1 = 1;
    c = 2;
    s = 2;
    e2 = 2;
    g2 = 2;
    e = -1;
    g = -1;
    c2 = -1;
    s2 = -1;
    scount = 0;
    ccount = 0;
    ecount = 0;
    gcount = 0;
    students = (Student *) malloc(sizeof(Student));
    courses = (Course *) malloc(sizeof(Course));
    enroll = (Enrollment *)malloc(sizeof(Enrollment));
    gra = (Grade *)malloc(sizeof(Grade));


    int num = 1;    //menu selection number

    BensHeading();

    printf ("\n\t\tWelcome to Gradebook 1.0!\n");   //HELLO :)
    while(num != 0) // 0 = exit program
    {  //open while loop

        PrntMenu(); //call menu function

        //prompt/menu//
        printf ("Type in a number to choose an option.\n");
        printf ("The number must be between 0 and 12, inclusively: ");
        scanf ("%d", &num);

        if ((num >= 0) && (num <= 12)) //so user chooses a valid option
        {  //open if statement

            switch (num)                   //*****//MENU//*****//

            {  //open switch

                case 0:
                    //close gradebook program;
                    break;
                case 1:
                    ccount = ccount + 1;
                    c = 1 + c;
                    if (ccount == 2) //must equal Chunk
                    {
                        Course *p = (Course*)realloc(courses, (Chunk + c) * sizeof(Course));
                        courses = p;
                        ccount = 0;
                    }
                    else
                    {

                    }
                    addCourse(courses); //add courses
                    break;

                case 2:
                    scount = scount + 1;
                    s = 1 + s;
                    if (scount == 2)
                    {
                        Student *p = (Student*)realloc(students, (Chunk + s) * sizeof(Student));
                        students = p;
                        scount = 0;
                    }
                    else
                    {

                    }
                    addNewStudent(students);    //add student
                    break;

                case 3:
                    ecount = ecount + 1;
                    e2 = 1 + e2;
                    if (ecount == 2) //must equal Chunk
                    {
                        Enrollment *p = (Enrollment*)realloc(enroll, (Chunk + e2) * sizeof(Enrollment));
                        enroll = p;
                        ecount = 0;
                    }
                    else
                    {

                    }
                    addStuCourse(enroll);    //add student to course
                    break;

                case 4:
                    gcount = gcount + 1;
                    g2 = 1 + g2;
                    if (gcount == 2) //must equal Chunk
                    {
                        Grade *p = (Grade*)realloc(gra, (Chunk + g2) * sizeof(Grade));
                        gra = p;
                        gcount = 0;
                    }
                    else
                    {

                    }
                    addGradesStu(enroll, gra);     // add grades to student in course
                    break;

                case 5:
                    PrntGrds(enroll, gra);     //print grades for student in course
                    break;

                case 6:
                    PrntStuInCo(students, enroll);  //print students in course
                    break;

                case 7:
                    CompStuAvg(enroll, gra);   //compute students average
                    break;

                case 8:
                    PrntCo(courses);   //print list of courses
                    break;

                case 9:
                    PrntStu(students);  //print students
                    break;

                case 10:
                    CompAvgCo(enroll, gra);    //compute course average
                    break;

                case 11:
                    SaveGr(students, courses, enroll, gra);   //save grades
                    break;

                case 12:
                    LoadGr(students, courses, enroll, gra);   //load grades
                    break;

            } //close switch//

        }  //close if statement
        else
        {  //open else statement
            printf ("Sorry, your number was not between 0 and 12.\n");
        }  //close else statement

    } //close while loop//

    //FREE MEMORY//
    free(courses);
    free(students);
    free(gra);
    free(enroll);

    return 0;
}


