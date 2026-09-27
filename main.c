#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student *head = NULL;

/* Swaps the data fields of two nodes (not the nodes themselves),
   so each student's roll number stays attached to their record. */
static void swap_data(Student *a, Student *b) {
    int roll = a->roll;
    char name[50];
    float percentage = a->percentage;
    strcpy(name, a->name);

    a->roll = b->roll;
    a->percentage = b->percentage;
    strcpy(a->name, b->name);

    b->roll = roll;
    b->percentage = percentage;
    strcpy(b->name, name);
}

static void sort_by_name(void) {
    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (strcmp(ptr1->name, ptr1->next->name) > 0) {
                swap_data(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

static void sort_by_percentage(void) {
    int swapped;
    Student *ptr1;
    Student *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->percentage > ptr1->next->percentage) {
                swap_data(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void stud_sort(void) {
    char choice;
    if (head == NULL) {
        printf("No records to sort.\n");
        return;
    }

    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'N' || choice == 'n') {
        sort_by_name();
        printf("Records sorted by name.\n");
    } else if (choice == 'P' || choice == 'p') {
        sort_by_percentage();
        printf("Records sorted by percentage.\n");
    } else {
        printf("Invalid choice.\n");
        return;
    }

    stud_show();
}

static void display_menu(void) {
    printf("\n**** STUDENT RECORD MENU ****\n");
    printf("A/a : Add New Record\n");
    printf("D/d : Delete a Record\n");
    printf("S/s : Show the List\n");
    printf("M/m : Modify a Record\n");
    printf("V/v : Save\n");
    printf("T/t : Sort the List\n");
    printf("E/e : Exit\n");
    printf("Enter Your Choice: ");
}

int main(void) {
    char choice;
    int running = 1;

    stud_load();

    while (running) {
        display_menu();
        if (scanf(" %c", &choice) != 1) break;

        switch (choice) {
            case 'A': case 'a':
                stud_add();
                break;
            case 'D': case 'd':
                stud_del();
                break;
            case 'S': case 's':
                stud_show();
                break;
            case 'M': case 'm':
                stud_mod();
                break;
            case 'V': case 'v':
                stud_save();
                printf("Records saved successfully.\n");
                break;
            case 'T': case 't':
                stud_sort();
                break;
            case 'E': case 'e': {
                char exit_choice;
                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");
                if (scanf(" %c", &exit_choice) != 1) exit_choice = 'e';

                if (exit_choice == 'S' || exit_choice == 's') {
                    stud_save();
                    printf("Records saved. Exiting...\n");
                } else {
                    printf("Exiting without saving...\n");
                }
                running = 0;
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    /* free all allocated memory before exit */
    Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
