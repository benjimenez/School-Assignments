#include <stdio.h>
#include <stdlib.h>
#define Chunk 2

//STRUCTURES
typedef struct {
    int ID; //student ID
    char firstName[20]; //students first name
    char lastName[20];  // students last name
} Student;

typedef struct {
    int courseID;   //courseID
    char courseName[30];    //course name
} Course;

typedef struct {
    int courseID;   //course id //LINKED
    int studentID;  //student id //LINKED
} Enrollment;

typedef struct {
    int courseID;   //course id //LINKED
    int studentID;  //student id //LINKED
    int grades;     //grades //LINKED
} Grade;
/////////////////////////

int student1, course1, enroll1, grade1;
int s, s2, c2, c, e, g, e2, g2;
int scount, ccount, ecount, gcount;
//int ww = 0, xx = 0, yy = 0, zz = 0;

Course *courses;
Student *students;
Enrollment *enroll;
Grade *gra;

//FUNCTIONS

void BensHeading(); //heading
void PrntMenu();  //menu

void addCourse(Course *courses);  //1
void addNewStudent(Student *students);  //2
void addStuCourse(Enrollment *enroll);  //3
void addGradesStu(Enrollment *enroll, Grade *gra);  //4
void PrntGrds(Enrollment *enroll, Grade *gra);  //5
void PrntStuInCo(Student *students, Enrollment *enroll);  //6
void CompStuAvg(Enrollment *enroll, Grade *gra);  //7
void PrntCo(Course *courses);  //8
void PrntStu(Student *students);  //9
void CompAvgCo(Enrollment *enroll, Grade *gra);  //10
void SaveGr(Student *students, Course *courses, Enrollment *enroll, Grade *gra);  //11
void LoadGr(Student *students, Course *courses, Enrollment *enroll, Grade *gra);  //12
/////////////////////


