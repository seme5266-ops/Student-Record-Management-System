#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int roll;
    char name[50];
    float percentage;
    struct Student *next;
} Student;

/* Shared linked list head, defined in main.c */
extern Student *head;

void stud_add();
void stud_del();
void stud_show();
void stud_mod();
void stud_save();
void stud_load();
void stud_sort();

#endif
