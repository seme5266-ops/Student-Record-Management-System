#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static void delete_by_roll(int roll) {
    Student *cur = head, *prev = NULL;

    while (cur != NULL && cur->roll != roll) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Roll Number %d not found.\n", roll);
        return;
    }

    if (prev == NULL) {
        head = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
    printf("Record with Roll Number %d deleted successfully.\n", roll);
}

void stud_del(void) {
    char choice;
    if (head == NULL) {
        printf("No records to delete.\n");
        return;
    }

    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r') {
        int roll;
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
        delete_by_roll(roll);

    } else if (choice == 'N' || choice == 'n') {
        char name[50];
        int found = 0;
        Student *cur = head;

        printf("Enter Name: ");
        scanf(" %49[^\n]", name);

        printf("\nMatching Records:\n");
        printf("--------------------------------------\n");
        printf("Roll No     Name         Percentage\n");
        printf("--------------------------------------\n");
        while (cur != NULL) {
            if (strcmp(cur->name, name) == 0) {
                printf("%-12d%-13s%.2f\n", cur->roll, cur->name, cur->percentage);
                found = 1;
            }
            cur = cur->next;
        }
        printf("--------------------------------------\n");

        if (!found) {
            printf("No matching records found.\n");
            return;
        }

        int roll;
        printf("Enter Roll Number to delete: ");
        scanf("%d", &roll);
        delete_by_roll(roll);

    } else {
        printf("Invalid choice.\n");
    }
}
