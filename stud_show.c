#include <stdio.h>
#include "student.h"

void stud_show(void) {
    if (head == NULL) {
        printf("No records to display.\n");
        return;
    }

    Student *cur = head;
    printf("\n--------------------------------------\n");
    printf("Roll No     Name         Percentage\n");
    printf("--------------------------------------\n");
    while (cur != NULL) {
        printf("%-12d%-13s%.2f\n", cur->roll, cur->name, cur->percentage);
        cur = cur->next;
    }
    printf("--------------------------------------\n");
}
