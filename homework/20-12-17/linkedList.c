/* linkedList.c -- A simple linked list calculator */

/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdlib.h>
#include <stdbool.h>
#include "../../library/s_gets.h"

#define NLEN 0x10

#define _ERR_MALLOC "Cannot put new students.\n"

typedef struct Student
{
	int num;
	char name[NLEN];
	/* 0 an female, 1 as male, no other */
	bool gender;
	int score;
	int weight;
	int height;
	/* (next == NULL) == the last */
	struct Student *next;
}Student;

/* insert one student in the front, return head pointer */
Student *insertHeadNew(Student *);
/* insert one student in the back, return head pointer */
void insertTailNew(Student *);
/* Input one student, return NULL for fail */
Student *stuNew(void);
/* Print all of the students */
void stuPrint(Student *);
/* num as the student number, name[] as the name of *object */
void inputInteger(int, int *, char []);

int main(void)
{
	Student *student = stuNew();
	stuPrint(student);
	student = insertHeadNew(student);
	insertTailNew(student);
	stuPrint(student);
	return 0;
}

Student *insertHeadNew(Student *head)
{
	Student *node = stuNew();
	if (node == NULL)
	{
		return head;
	}
	node->next = head;
	return node;
}

void insertTailNew(Student *tail)
{
	if (tail->next == NULL)
	{
		Student *node = stuNew();
		tail->next = node;
		return;
	}
	insertTailNew(tail->next);
	return;
}

Student *stuNew(void)
{
	Student *student = (Student *)malloc(sizeof(Student));
	if (student == NULL)
	{
		fprintf(stderr, _ERR_MALLOC);
		return NULL;
	}
	char gender;
	printf("Input the num of the student, Ctrl+Z for end: ");
	if (scanf("%d",&student->num) == EOF)
	{
		free(student);
		return NULL;
	}
	printf("Input the name of student %d, Ctrl+Z for end:\n", student->num);
	fflush(stdin);
	if (s_gets(student->name, NLEN) == NULL)
	{
		free(student);
		return NULL;
	}
	printf("Input the gender(M/F) of student %d: ", student->num);
	scanf("%c", &gender);
	while (true)
	{
		if (gender == 'F' || gender == 'f')
		{
			student->gender = false;
			break;
		}
		else if (gender == 'M' || gender == 'm')
		{
			student->gender = true;
			break;
		}
		else
		{
			fflush(stdin);
			printf("Input the gender(M/F) of student %d: ", student->num);
			scanf("%c", &gender);
		}
	}
	inputInteger(student->num, &student->score, "score");
	inputInteger(student->num, &student->weight, "weight");
	inputInteger(student->num, &student->height, "height");
	student->next = NULL;
	return student;
}

void stuPrint(Student *student)
{
	printf("---------");
	if (student == NULL)
	{
		return;
	}
	printf("num == %d\n", student->num);
	printf("name == %s\n", student->name);
	printf("gender == %s\n", student->gender?"Male":"Female");
	printf("score == %d\n", student->score);
	printf("weight == %d\n", student->weight);
	printf("height == %d\n", student->height);
	stuPrint(student->next);
	return;
}

void inputInteger(int num, int *object, char name[])
{
	// printf("Input the score of student %d: ", num);
	printf("Input the ");
	printf(name);
	printf(" of student %d: ", num);
	while (true)
	{
		if (scanf("%d", object))
		{
			break;
		}
		else
		{
			fflush(stdin);
			printf("Input the ");
			printf(name);
			printf(" of student %d: ", num);
		}
	}
	return;
}
