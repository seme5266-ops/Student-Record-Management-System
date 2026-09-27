#include <stdio.h>
#include <string.h>
#include "student.h"

static Student *find_by_roll(int roll) {
    Student *cur = head;
    while (cur != NULL) {
        if (cur->roll == roll) return cur;
        cur = cur->next;
    }
    return NULL;
}

static void modify_fields(Student *s) {
    char choice;
    printf("\nN/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'N' || choice == 'n') {
        printf("Enter New Name: ");
        scanf(" %49[^\n]", s->name);
        printf("Name updated successfully.\n");
    } else if (choice == 'P' || choice == 'p') {
        printf("Enter New Percentage: ");
        scanf("%f", &s->percentage);
        printf("Percentage updated successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void stud_mod(void) {
    char choice;
    if (head == NULL) {
        printf("No records to modify.\n");
        return;
    }

    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r') {
        int roll;
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
        Student *s = find_by_roll(roll);
        if (s == NULL) {
            printf("Roll Number %d not found.\n", roll);
            return;
        }
        modify_fields(s);

    } else if (choice == 'N' || choice == 'n' || choice == 'P' || choice == 'p') {
        Student *cur = head;
        int found = 0;

        printf("\nMatching Records:\n");
        printf("--------------------------------------\n");
        printf("Roll No     Name         Percentage\n");
        printf("--------------------------------------\n");

        if (choice == 'N' || choice == 'n') {
            char name[50];
            printf("Enter Name: ");
            scanf(" %49[^\n]", name);
            while (cur != NULL) {
                if (strcmp(cur->name, name) == 0) {
                    printf("%-12d%-13s%.2f\n", cur->roll, cur->name, cur->percentage);
                    found = 1;
                }
                cur = cur->next;
            }
        } else {
            float percentage;
            printf("Enter Percentage: ");
            scanf("%f", &percentage);
            while (cur != NULL) {
                if (cur->percentage == percentage) {
                    printf("%-12d%-13s%.2f\n", cur->roll, cur->name, cur->percentage);
                    found = 1;
                }
                cur = cur->next;
            }
        }
        printf("--------------------------------------\n");

        if (!found) {
            printf("No matching records found.\n");
            return;
        }

        int roll;
        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);
        Student *s = find_by_roll(roll);
        if (s == NULL) {
            printf("Roll Number %d not found.\n", roll);
            return;
        }
        modify_fields(s);

    } else {
        printf("Invalid choice.\n");
    }
}
