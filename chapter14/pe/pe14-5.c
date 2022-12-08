#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN 40
#define CSIZE 4

struct name
{
    char first[LEN];
    char last[LEN];
};

struct student
{
    struct name handle;
    float grade[3];
    float average;
};
typedef struct student Student;
void cleanbuf();
char * s_gets(char * st, int n);
void set_students_grade(Student * students, int csize);
int search(char * name, Student * students, int csize);
void average(Student * students, int csize);
void print(Student * students, int csize);
float class_average(Student * students, int csize);

int main(void)
{
    Student students[CSIZE] = {
        { "David", "Craft" },
        { "Jesse", "Smith" },
        { "James", "Morris" },
        { "Kyle", "Reyes" }
    };

    set_students_grade(students, CSIZE);
    average(students, CSIZE);
    print(students, CSIZE);
    printf("Class average: %.2f\n",class_average(students, CSIZE));
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret;
    ret = fgets(st, n, stdin);
    if (ret)
    {
        int i = 0;
        while (st[i]!='\n' && st[i] != '\0')
            i++;

        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
            continue;
    }
    return ret;
}

void set_students_grade(Student * students, int csize)
{
    char name[LEN];
    puts("Enter first name (empty line to quit):");
    while (s_gets(name, LEN) != NULL && name[0] != '\0')
    {
        int index = search(name, students, csize);
        if (index < 0)
        {
            printf("%s is not in this class. Check it!\n", name);
            puts("Enter next first name (empty line to quit):");
            continue;
        }

        printf("Enter your grade: ");
        scanf("%f %f %f", &students[index].grade[0], 
                &students[index].grade[1], &students[index].grade[2]);
        cleanbuf();
        puts("Enter next first name (empty line to quit):");
    }
}

int search(char * name, Student * students, int csize)
{
    for (int i = 0; i < csize; i++)
    {
        int namelen = strlen(name);
        if (namelen != strlen(students[i].handle.first))
            continue;
        
        for (int j = 0; j < namelen; j++)
        {
            if (tolower(name[j]) != tolower(students[i].handle.first[j]))
                break;

            if (j == namelen-1)
                return i;
        }
        
    }

    return -1;
}

void average(Student * students, int csize)
{
    for (int i = 0; i < csize; i++)
    {
        float total = 0;
        for (int j = 0; j < 3; j++)
            total += students[i].grade[j];
        students[i].average = total / 3;
    }
}

void print(Student * students, int csize)
{
    for (int i = 0; i < csize; i++)
    {
        printf("%s %s: %.2f %.2f %.2f, average: %.2f;\n", students[i].handle.first, students[i].handle.last, students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].average);
    }
}

float class_average(Student * students, int csize)
{
    float total = 0;
    for (int i = 0; i < csize; i++)
        total += students[i].average;
    return total / csize;
}

void cleanbuf()
{
    while (getchar() != '\n')
    {
        continue;
    }
    
}