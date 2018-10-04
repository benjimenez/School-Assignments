#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void BensHeading()
{
    printf ("+--------------------------------------------------------+\n");
    printf ("|           Computer Science and Engineering    HW2 & 3  |\n");
    printf ("|            CSCE 1040 - Computer Science II             |\n");
    printf ("|    Benjamin Jimenez  bjj0051  bjj0051@my.unt.edu       |\n");
    printf ("+--------------------------------------------------------+\n");
}
void PrntMenu()
{
    printf ("\n+-------------------------------------------------------+");
    printf ("\n|\t\t\t\t\t0. Exit Program |\n");
    printf ("|1. Add a new course                                    |\n");
    printf ("|2. Add a new student                                   |\n");
    printf ("|3. Add a student to a course                           |\n");
    printf ("|4. Add grades for a student in a course                |\n");
    printf ("|5. Print a list of all grades for a student in a course|\n");
    printf ("|6. Print a list of all students in a course            |\n");
    printf ("|7. Compute the average for a student in a course       |\n");
    printf ("|8. Print a list of all courses                         |\n");
    printf ("|9. Print a list of all students                        |\n");
    printf ("|10. Compute the average for a course                   |\n");
    printf ("|11. Store Grade Book                                   |\n");
    printf ("|12. Load Grade book                                    |\n");
    printf ("+-------------------------------------------------------+\n\n");
}

//FUNCTION ADDS COURSE TO STRUCT ARRAY
void addCourse(Course *courses) //1  FINISHED
{
    c2 = c2 + 1;

    printf("Please enter a course number: ");   //prompt for courseID
    scanf("%d", &courses[c2].courseID);    //store course ID

    printf("Please enter a course name: "); //prompt for course name
    scanf("%s", courses[c2].courseName);    //store course name

    return;
}


//FUNCTION ADDS STUDENT TO STRUCT ARRAY
void addNewStudent(Student *students) //2  FINISHED
{
    s2 = s2 + 1;

    printf("Please enter the student's ID number: ");   //prompt for student ID
    scanf("%d", &students[s2].ID);    //store student ID

    printf("Please enter student's first name: "); //prompt for first name
    scanf("%s", students[s2].firstName);    //store student's first name

    printf("Please enter student's last name: ");   //prompt for student's last name
    scanf("%s", students[s2].lastName);     //store student's last name

    return;
}

//FUNCTION ADDS STUDENT TO COURSE
void addStuCourse(Enrollment *enroll) //3  FINISHED
{
    e=e+1;

    printf ("Enter student's ID number: ");     //prompts for student id
    scanf("%d", &enroll[e].studentID);    //stores in enroll struct array
    
    printf("Enter course number: ");    //prompts for course id
    scanf("%d", &enroll[e].courseID);   //stores in enroll struct array

}



//FUNCTION ADDS GRADES TO STUDENT IN A COURSE
void addGradesStu(Enrollment *enroll, Grade *gra) //4  FINISHED
{
    int i, j, k;

    printf ("Enter student's ID number: "); //prompt for id number
    scanf ("%d", &i);   //store id number

    printf("Enter course number: ");    //prompt for course number
    scanf("%d", &j);    //store course number

    for (k = 0; k <= e; k++)
    {
        if (enroll[k].studentID == i && enroll[k].courseID == j)
        {
            g=g+1;
            gra[g].studentID = i;
            gra[g].courseID = j;
            printf("Enter grade: ");    //prompt for grade
            scanf("%d", &gra[g].grades);    //store grade
            break;
        }
        else
        {

        }
    }
}

//FUNCTION PRINTS GRADES
void PrntGrds(Enrollment *enroll, Grade *gra) //5  FINISHED
{
    int i, j, k;
    printf ("Enter student's ID number: ");
    scanf ("%d", &i);
    printf ("Enter course number: ");
    scanf ("%d", &k);
    for (j = 0; j <= g; j++)
    {
        if ((gra[j].studentID == i) && (gra[j].courseID == k))
        {
            printf("%d\n", gra[j].grades);
        }
        else
        {

        }
    }
}

//FUNCTION PRINTS STUDENTS IN COURSE
void PrntStuInCo(Student *students, Enrollment *enroll) //6  FINISHED
{
    int i, j, k;
    printf("Enter course number: ");
    scanf("%d", &i);
    for (j = 0; j <= e; j++)
    {
        if (i == enroll[j].courseID)
        {
            for (k = 0; k <= s2; k++)
            {
                if (enroll[j].studentID == students[k].ID)
                {
                    printf("%s, %s\n", students[k].lastName, students[k].firstName);
                }
                else
                {

                }
            }
        }
        else
        {

        }
    }
}

//FUNCTION COPMUTES STUDENTS AVERAGE IN A COURSE
void CompStuAvg(Enrollment *enroll, Grade *gra) //7  FINISHED
{
    int i, j, k;
    int sum = 0; //sum of all grades
    int num = 0; //counter
    float avg; //average

    printf ("Enter student's ID number: ");
    scanf ("%d", &i);
    printf ("Enter course number: ");
    scanf ("%d", &k);
    for (j = 0; j <= g; j++)
    {
        if ((gra[j].studentID == i) && (gra[j].courseID == k))
        {
            num++; //counter
            sum = sum + gra[j].grades;
            num = 0 + num;
        }
        else
        {

        }
    }
    avg = ((float) sum) / num;
    printf("\nThe average is: %4.2f\n\n", avg);
}


//FUNCTION PRINTS ALL COURSES
void PrntCo(Course *courses) //8  FINISHED
{
    int a;
	if (course1 == 0)
	{
		for (a = 2; a <= c2 + 2; a++)
            {
                if (courses[a].courseID == 0)
                 {

                 }
                else
                {
                printf("\nCourse number: %d, Course name: %s\n",
                        courses[a].courseID, courses[a].courseName);
                }
            }
	}
	else
	{
	    for (a = 0; a <= c2; a++)
   	    {
        	if (courses[a].courseID == 0)
       		 {

        	 }
        	else
        	{
            	printf("\nCourse number: %d, Course name: %s\n",
                   	courses[a].courseID, courses[a].courseName);
        	}
    	    }
	}

    return;
}


//FUNCTION PRINTS ALL STUDENTS
void PrntStu(Student *students) //9 FINISHED
{
    int a;

	if (student1 == 0)
        {
            for (a = 2; a <= c2 + 2; a++)
            {
                if (courses[a].courseID == 0)
                 {

                 }
                else
                {
                printf("\nID: %d, Last name: %s, First name: %s\n",
                   students[a].ID, students[a].lastName, students[a].firstName);
                }
            }
        }
        else
        {
	for (a = 0; a<=s2; a++)
	{
        	if (students[a].ID == 0)
        	{

        	}
        	else
        	{
            	printf("\nID: %d, Last name: %s, First name: %s\n",
                   students[a].ID, students[a].lastName, students[a].firstName);
        	}
    	}
	}
}


//FUNCTION COPMUTES A COURSES AVERAGE
void CompAvgCo(Enrollment *enroll, Grade *gra) //10 FINISHED
{
    int i, j;
    int num = 0; //counter
    int sum = 0; //total of grades
    float avg; //average

    printf ("Enter course number: ");
    scanf ("%d", &i);

    for (j = 0; j <= g; j++)
    { // for
        if (i == gra[j].courseID)
        {
            num++; //counter will divide the sum for average
            sum = sum + gra[j].grades;
            num = 0 + num;
        }
        else
        {

        }
    } // for

    avg = ((float) sum) / num;
    printf("sum: %d / num: %d = class average: %4.2f\n\n", sum, num, avg);
}



//FUNCTION SAVES STRUCT ARRAYS TO A FILE
void SaveGr(Student *students, Course *courses, Enrollment *enroll, Grade *gra) //11 FINISHED
{
    int aa, bb, cc, dd;
    FILE* write1;
    write1 = fopen("info1.txt", "w");

    /* write c, c2, s, s2, e, e2, g, g2 */
    fprintf(write1, "%d %d %d %d %d %d %d %d, %d, %d, %d, %d",
            c, c2, s, s2, e, e2, g, g2, ccount, scount, ecount, gcount);

    fclose(write1);
    
    FILE* write2;
    write2 = fopen("info2.txt", "w");
    for (aa = 0; aa <= (c2); aa++) {
        fprintf(write2, "%d ", courses[aa].courseID);
        fprintf(write2, "%s ", courses[aa].courseName);
    }
    fclose(write2);
    
    FILE* write3;
    write3 = fopen("info3.txt", "w");
    for (bb = 0; bb <= (s2); bb++) {
        fprintf(write3, "%d ", students[bb].ID);
        fprintf(write3, "%s ", students[bb].firstName);
        fprintf(write3, "%s ", students[bb].lastName);
    }
    fclose(write3);
    
    FILE* write4;
    write4 = fopen("info4.txt", "w");
    for (cc = 0; cc <= (e); cc++) {
        fprintf(write4, "%d ", enroll[cc].courseID);
        fprintf(write4, "%d ", enroll[cc].studentID);
    }
    fclose(write4);
    
    FILE* write5;
    write5 = fopen("info5.txt", "w");
    for (dd = 0; dd <= (g); dd++) {
        fprintf(write5, "%d ", gra[dd].courseID);
        fprintf(write5, "%d ", gra[dd].studentID);
        fprintf(write5, "%d ", gra[dd].grades);
    }
    fclose(write5);

    /*FILE* write; //OPEN FILE WRITE
    write = fopen("gradebook.data", "wb");
    fwrite(courses, sizeof(Course), c, write);
    fwrite(students, sizeof(Student), s, write);
    fwrite(enroll, sizeof(Enrollment), e2, write);
    fwrite(gra, sizeof(Grade), g2, write);
    fclose(write); //CLOSE FILE WRITE*/
}

//FUNCTION LOADS STRUCT ARRAYS FROM A FILE
void LoadGr(Student *students, Course *courses, Enrollment *enroll, Grade *gra) //12 FINISHED
{
    int aa, bb, cc, dd;

    FILE* read1;
    read1 = fopen("info1.txt", "r");

    fscanf(read1, "%d %d %d %d %d %d %d %d %d %d %d %d",
           &c, &c2, &s, &s2, &e, &e2, &g, &g2, &ccount, &scount, &ecount, &gcount);
    fclose(read1);

    Course *a = (Course*)realloc(courses, (c) * sizeof(Course));
    courses = a;

    Student *b = (Student*)realloc(students, (s) * sizeof(Student));
    students = b;

    Enrollment *a1 = (Enrollment*)realloc(enroll, (e2) * sizeof(Enrollment));
    enroll = a1;

    Grade *d = (Grade*)realloc(gra, (g2) * sizeof(Grade));
    gra = d;
    
    FILE* read2;
    read2 = fopen("info2.txt", "r");
    for (aa = 0; aa <= (c2); aa++) {
        fscanf(read2, "%d", &courses[aa].courseID);
        printf("%d ", courses[aa].courseID);
        
        fscanf(read2, "%s", courses[aa].courseName);
        printf("%s ", courses[aa].courseName);
    }
    fclose(read2);
    
    FILE* read3;
    read3 = fopen("info3.txt", "r");
    for (bb = 0; bb <= (s2); bb++) {
        fscanf(read3, "%d", &students[bb].ID);
        printf("%d ", students[aa].ID);
        fscanf(read3, "%s", students[bb].firstName);
        printf("%s ", students[aa].firstName);
        fscanf(read3, "%s", students[bb].lastName);
        printf("%s ", students[aa].lastName);
    }
    
    fclose(read3);
    
    FILE* read4;
    read4 = fopen("info4.txt", "r");
    for (cc = 0; cc <= (e); cc++) {
        fscanf(read4, "%d", &enroll[cc].courseID);
        printf("%d ", enroll[cc].courseID);
        fscanf(read4, "%d", &enroll[cc].studentID);
        printf("%d ", enroll[cc].studentID);
    }
    
    fclose(read4);
    
    FILE* read5;
    read5 = fopen("info5.txt", "r");
    for (dd = 0; dd <= (g); dd++) {
        fscanf(read5, "%d", &gra[dd].courseID);
        printf("%d ", gra[dd].courseID);
        fscanf(read5, "%d", &gra[dd].studentID);
        printf("%d ", gra[dd].studentID);
        fscanf(read5, "%d", &gra[dd].grades);
        printf("%d ", gra[dd].grades);
    }
    
    fclose(read5);
	course1 = 0;
	student1 = 0;
	enroll1 = 0;
	grade1 = 0;
   /* FILE* read; //OPEN FILE READ
    read = fopen("gradebook.data", "rb");
    fread(courses, sizeof(Course), c, read);
    fread(students, sizeof(Student), s, read);
    fread(enroll, sizeof(Enrollment), e2, read);
    fread(gra, sizeof(Grade), g2, read);
    fclose(read); //CLOSE FILE READ*/
}
