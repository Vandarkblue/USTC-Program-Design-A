/* Copyright (c) 2020 Dec Randomizer.

This file is licensed under the MIT License.

For more infomation, visit
<https://github.com/Vandarkblue/USTC-Program-Design-A/>.  */

/**
 * Structure functions used for Node infomation "nodeCalx.h"
 */

#ifndef _NODE_CALX_H
#define _NODE_CALX_H

#include <stdlib.h>
#include "./s_gets.h"

/**
 * Global settings
 */

#ifndef _NODE_NLEN
/* The maximal length of name */
#define _NODE_NLEN 0xff
#endif

/**
 * Defined Strings
 */

#define _NODE_LINE "----------------------------------------\n"
#define _ERR_MALLOC "Cannot put new students.\n"
#define _INPUT_GENDER "Input the gender(M/F) of Student %d: "

/**
 * Node Structure
 */

typedef struct Student
{
	int age;
	int num;
	/* score as exact value is stored as integer */
	int score;
	int weight;
	int height;
	/* 0 an female, 1 as male */
	bool gender;
	char name[_NODE_NLEN];
	/* (next == NULL) == the last */
	struct Student *next;

} Node;

typedef enum Properties
{
	age, num, score, weight, height, gender, name

} Element;

/**
 * Function Declarations
 */

/* Create a new node for a student */
Node *stuNew(void);
/* insert one student in the front, return head pointer */
Node *nodeCalxInstHeadNew(Node *head);
/* insert one student in the back */
void nodeCalxInstTailNew(Node *head);
/* Insert a node into a sequenced list */
Node *nodeCalxSeqInst(Node *head, Node *node);
/* Print the infomation of a node */
Node *nodeCalxPrint(Node *Node);
/* Print the infomation of all nodes */
void nodeCalxPrintall(Node *head);
/* In build */
Node *nodeCalxMergeSort(Node *h0, Node *h1);
/* Delete a node with specific data */
Node *nodeCalxFindDelete(Node *head, Element type, void *value);
/* Check a node with a given item value */
bool nodeCalxCheck(Node *head, Element type, void *value);

/**
 * Function Bodies
 */

Node *stuNew(void)
{
	float scoreF;
	char gender;
	Node *node = (Node *)malloc(sizeof(Node));

	if (node == NULL)
	{
		fprintf(stderr, _ERR_MALLOC);
		return NULL;
	}
	printf("Input the num of the student, Ctrl+Z for end: ");
	if (scanf("%d",&node->num) == EOF)
	{
		free(node);
		return NULL;
	}
	printf("Input the name of Student %d, Ctrl+Z for end:\n", node->num);
	fflush(stdin);
	if (s_gets(node->name, _NODE_NLEN) == NULL)
	{
		free(node);
		return NULL;
	}
	printf(_INPUT_GENDER, node->num);
	scanf("%c", &gender);
	while (true)
	{
		if (gender == 'F' || gender == 'f')
		{
			node->gender = false;
			break;
		}
		else if (gender == 'M' || gender == 'm')
		{
			node->gender = true;
			break;
		}
		else
		{
			fflush(stdin);
			printf(_INPUT_GENDER, node->num);
			scanf("%c", &gender);
		}
	}
	printf("Input the score of Student %d: ", node->num);
	while (true)
	{
		if (scanf("%f", &scoreF))
		{
			break;
		}
		else
		{
			fflush(stdin);
			printf("Input the score of Student %d: ", node->num);
		}
	}
	node->score = (int)(100 * scoreF);
	inputInteger(node->num, &node->age, "age");
	inputInteger(node->num, &node->weight, "weight");
	inputInteger(node->num, &node->height, "height");
	node->next = NULL;
	return node;
}

Node *nodeCalxInstHeadNew(Node *head)
{
	Node *node = stuNew();

	if (node == NULL)
	{
		return head;
	}
	node->next = head;
	return node;
}

void nodeCalxInstTailNew(Node *tail)
{
	if (tail->next == NULL)
	{
		Node *node = stuNew();
		tail->next = node;
		return;
	}
	nodeCalxInstTailNew(tail->next);
	return;
}

Node *nodeCalxSeqInst(Node *head, Node *node)
{
	Node *pointer = head;

	if (head == NULL)
	{
		return node;
	}

	if (head->num > node->num)
	{
		node->next = head;
		return node;
	}

	while (pointer->next != NULL && pointer->next->num < node->num)
	{
		pointer = pointer->next;
	}

	node->next = pointer->next;
	pointer->next = node;

	return head;
}

Node *nodeCalxPrint(Node *node)
{
	printf(_NODE_LINE);
	if (node == NULL)
	{
		return NULL;
	}
	printf("No.%d  %s\n", node->num, node->name);
	printf("Age: %d\n", node->age);
	printf("Gender: %s\n", node->gender?"Male":"Female");
	printf("Score: %d.%d\n", node->score/100, node->score%100);
	printf("Weight: %d\n", node->weight);
	printf("Height: %d\n", node->height);
	return node->next;
}

void nodeCalxPrintall(Node *head)
{
	if (head == NULL)
	{
		printf("NULL\n"_NODE_LINE);
	}
	while (head != NULL)
	{
		head = nodeCalxPrint(head);
	}
	printf(_NODE_LINE);
	return;
}

/* Question: Can variable-number-parameter function be used? */
Node *nodeCalxMergeSort(Node *h0, Node *h1)
{
	Node *dest = NULL, *pointer = NULL;\

	while (h0 != NULL)
	{
		pointer = h0->next;
		h0->next = NULL;
		dest = nodeCalxSeqInst(dest, h0);
		h0 = pointer;
	}
	while (h1 != NULL)
	{
		pointer = h1->next;
		h1->next = NULL;
		dest = nodeCalxSeqInst(dest, h1);
		h1 = pointer;
	}
	return dest;
}

Node *nodeCalxFindDelete(Node *head, Element type, void *value)
{
	Node *init = head, *node = NULL;

	if (head == NULL)
	{
		printf("Not found.\n");
		return NULL;
	}

	if (nodeCalxCheck(head, type, value))
	{
		node = head;
		head = head->next;
		free(node);
		printf("Node %d has been deleted.\n", value);
		return head;
	}

	while (head->next != NULL)
	{
		if (nodeCalxCheck(head->next, type, value))
		{
			node = head->next;
			head->next = head->next->next;
			free(node);
			printf("Node %d has been deleted.\n", value);
			return init;
		}
	}
	printf("Not found.\n");
	return init;
}

bool nodeCalxCheck(Node *node, Element type, void *value)
{
	if (node == NULL)
	{
		return false;
	}
	switch (type)
	{
	case age:		return (*(int *)value == node->age);
	case num:		return (*(int *)value == node->num);
	case score:		return (*(int *)value == node->score);
	case weight:	return (*(int *)value == node->weight);
	case height:	return (*(int *)value == node->height);
	case gender:	return (*(bool *)value == node->gender);
	case name:		return (bool)strcmp((char *)value, node->name);
	}
}

#endif /* nodeCalx.h */
