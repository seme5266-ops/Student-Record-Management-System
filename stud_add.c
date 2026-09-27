#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* Finds the smallest positive roll number not currently in use.
   The list is kept sorted by roll number, so we just walk it
   looking for the first gap in the sequence 1,2,3,... */
static int get_next_roll(void) {
    int expected = 1;
    Student *cur = head;
    while (cur != NULL && cur->roll == expected) {
        expected++;
        cur = cur->next;
    }
    return expected;
}

void stud_add(void) {
    Student *new_node = (Student *)malloc(sizeof(Student));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->roll = get_next_roll();

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", new_node->name);

    printf("Enter Percentage: ");
    scanf("%f", &new_node->percentage);

    /* Insert keeping the list sorted by roll number */
    if (head == NULL || head->roll > new_node->roll) {
        new_node->next = head;
        head = new_node;
    } else {
        Student *cur = head;
        while (cur->next != NULL && cur->next->roll < new_node->roll) {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }

    printf("Record added successfully with Roll Number: %d\n", new_node->roll);
}
