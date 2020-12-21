/* nodeCalx.c -- A simple linked list calculator */

/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdlib.h>
#include <stdbool.h>
#include "../../library/s_gets.h"

#define NLEN 16

#define LINE "----------------------\n"
#define STRING_NO_CREATED "Please select a creating method first.\n"
#define INTEGERS_ONLY "Menu accepts integers only.\n"

struct Student
{
	int num;
	char name[NLEN];
	char sex;
	int age;
	double grade;
	struct Student *next;
};

/* Insert one student in the front, return head pointer */
struct Student *insertHeadNew(struct Student *);
/* Insert one student in the back, return head pointer */
void insertTailNew(struct Student *);
/* Input one student, return NULL for fail */
struct Student *stuNew(void);
/* Print all of the students */
void stuPrint(struct Student *);
/* Print one student */
void stuPrintPart(struct Student *);
/* num as the student number, name[] as the name of *object */
void inputData(int, void *, char [], char []);
struct Student *findNum(struct Student *, int);
struct Student *delete(struct Student *, int);

int main(void)
{
	struct Student *head = NULL;
	struct Student *object = NULL;
	int method = 0; // 1 as head-insert, 2 as tail-insert

	int key = -1;
	int temp = 0;
	bool isReturn = false;

	// logo();

	while (true)
	{
		printf("---menu---\n");
		printf("0. Exit\n");
		printf("1. Create\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Print\n");
		printf("5. Find\n");
		printf("9. clrscr\n");
		printf("---------\n");
		
		if (scanf("%d", &key))
		{
			switch (key)
			{
			case 0:
				// logo();
				return 0;
			case 1:
				if (head != NULL)
				{
					// free linked list
				}
				while (true)
				{
					printf("--------Create--------\n");
					printf("0. Return to main menu\n");
					printf("1. Head-inssert\n");
					printf("2. Tail-insert\n");
					printf("----------------------\n");
					if (scanf("%d", &key))
					{
						isReturn = true;
						switch (key)
						{
						case 0:
							break;
						case 1:
							method = 1;
							break;
						case 2:
							method = 2;
							break;
						default:
							isReturn = false;
							printf("Function not defined.\n");
							break;
						} // switch (key)
					} // if Create input correct
					else
					{
						printf(INTEGERS_ONLY);
						fflush(stdin);
						isReturn = false;
					}
					if (isReturn)
					{
						break;
					}
				}
				printf("------------------------\n");
				printf("Input the first student.\n");
				head = stuNew();
				break;
			case 2:
				switch (method)
				{
				case 1:
					head = insertHeadNew(head);
					break;
				case 2:
					insertTailNew(head);
					break;
				default:
					printf(STRING_NO_CREATED);
					break;
				}
				break;
			case 3:
				printf("Input the num of the student to delete: ");
				scanf("%d", &temp);
				delete(head, temp);
				if (head == NULL)
				{
					method = 0;
				}
				break;
			case 4:
				stuPrint(head);
				break;
			case 5:
				if (method == 0)
				{
					printf(STRING_NO_CREATED);
					break;
				}
				printf("Input the num of the student to find: ");
				scanf("%d", &temp);
				object = findNum(head, temp);
				stuPrintPart(object);
				break;
			case 9:
				system("CLS");
				break;
			default:
				printf("Function not defined.\n");
				break;
			}
		}
		else
		{
			printf(INTEGERS_ONLY);
			fflush(stdin);
		}
		
	} // while true
	return -1;
}

struct Student *insertHeadNew(struct Student *head)
{
	struct Student *node = stuNew();
	node->next = head;
	return node;
}

void insertTailNew(struct Student *tail)
{
	if (tail->next == NULL)
	{
		struct Student *node = stuNew();
		tail->next = node;
		return;
	}
	insertTailNew(tail->next);
	return;
}

struct Student *stuNew(void)
{
	struct Student *student = (struct Student *)malloc(sizeof(struct Student));
	if (student == NULL)
	{
		return NULL;
	}
	char sex;

	printf("Input the num of the student, Ctrl+Z for end: ");
	if (scanf("%d",&student->num) == EOF)
	{
		free(student);
		return NULL;
	}
	printf("Input the name of student %d:\n", student->num);
	fflush(stdin);
	s_gets(student->name, NLEN);
	printf("Input the sex of student %d: ", student->num);
	fflush(stdin);
	student->sex = getchar();
	fflush(stdin);
	inputData(student->num, &student->age, "%d", "age");
	inputData(student->num, &student->grade, "%lf", "grade");
	student->next = NULL;
	return student;
}

void stuPrint(struct Student *student)
{
	printf("--------------\n");
	if (student == NULL)
	{
		printf("EOF\n");
		return;
	}
	printf("num == %d\n", student->num);
	printf("name == \"%s\"\n", student->name);
	printf("sex == \'%c\'\n", student->sex);
	printf("age == %d\n", student->age);
	printf("grade == %6.2lf\n", student->grade);
	stuPrint(student->next);
	return;
}

void stuPrintPart(struct Student *student)
{
	printf("--------------\n");
	if (student == NULL)
	{
		printf("NULL\n");
		return;
	}
	printf("num == %d\n", student->num);
	printf("name == \"%s\"\n", student->name);
	printf("sex == \'%c\'\n", student->sex);
	printf("age == %d\n", student->age);
	printf("grade == %6.2lf\n", student->grade);
	return;
}

void inputData(int num, void *object, char type[], char name[])
{
	// printf("Input the score of student %d: ", num);
	printf("Input the ");
	printf(name);
	printf(" of student %d: ", num);
	while (true)
	{
		if (scanf(type, object))
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

struct Student *findNum(struct Student *head, int num)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->num == num)
	{
		return head;
	}
	return findNum(head->next, num);
}

struct Student *delete(struct Student *head, int num)
{
	struct Student *init = head, *node = NULL;
	if (head == NULL)
	{
		printf("Not found.\n");
		return NULL;
	}
	if (head->num == num)
	{
		node = head;
		head = head->next;
		free(node);
		printf("Student %d has been deleted.\n", num);
		return head;
	}
	while (head->next != NULL)
	{
		if (head->next->num == num)
		{
			node = head->next;
			head->next = head->next->next;
			free(node);
			printf("Student %d has been deleted.\n", num);
			return init;
		}
	}
	printf("Not found.\n");
	return init;
}
