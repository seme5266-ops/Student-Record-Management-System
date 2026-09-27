#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define FILENAME "student.dat"

void stud_save(void) {
    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    Student *cur = head;
    while (cur != NULL) {
        fwrite(&cur->roll, sizeof(int), 1, fp);
        fwrite(cur->name, sizeof(char), 50, fp);
        fwrite(&cur->percentage, sizeof(float), 1, fp);
        cur = cur->next;
    }

    fclose(fp);
}

void stud_load(void) {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        return; /* no saved file yet, start with an empty list */
    }

    Student *tail = NULL;
    while (1) {
        Student *new_node = (Student *)malloc(sizeof(Student));
        if (new_node == NULL) {
            printf("Memory allocation failed while loading.\n");
            break;
        }

        size_t r1 = fread(&new_node->roll, sizeof(int), 1, fp);
        size_t r2 = fread(new_node->name, sizeof(char), 50, fp);
        size_t r3 = fread(&new_node->percentage, sizeof(float), 1, fp);

        if (r1 != 1 || r2 != 50 || r3 != 1) {
            free(new_node);
            break;
        }

        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
        }
        tail = new_node;
    }

    fclose(fp);
    printf("Records loaded from %s\n", FILENAME);
}
