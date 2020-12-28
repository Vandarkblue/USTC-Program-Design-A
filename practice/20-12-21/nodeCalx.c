/* nodeCalx.c -- A simple linked list calculator */

/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#define _NODE_NLEN 0x7f
#include "../../library/nodeCalx.h"

#define LINE "----------------------\n"
#define STRING_NO_CREATED "Please select a creating method first.\n"
#define INTEGERS_ONLY "Menu accepts integers only.\n"
#define NO_FUNCTION "Function not defined.\n" 

enum Method
{
	mNull, mHead, mTail, mSeq
};

void nodeCalxLogo(void);
Node *loadFile(char fname[]);
int saveFile(Node *head, FILE *fp);

int main(void)
{
	struct Student *head = NULL;
	struct Student *object = NULL;
	enum Method method = 0; // 1 as head-insert, 2 as tail-insert
	bool isSequentialized = false;

	int key = -1;
	int temp = 0;
	bool isReturn = false;

	bool isFileOpen = false;
	char fname[_NODE_NLEN];
	FILE *fp = NULL;

	nodeCalxLogo();

	while (true)
	{
		printf("---menu---\n");
		printf("0. Exit\n");
		printf("1. Create linked list\n");
		printf("2. Insert a node\n");
		printf("3. Delete a node\n");
		printf("4. Output the linked list\n");
		printf("5. Find a node\n");
		printf("6. Sequentialize\n");
		printf("9. Clear Screen\n");
		printf("---------\n");

		if (scanf("%d", &key))
		{
			switch (key)
			{
			case 0:
				nodeCalxLogo();
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
					printf("3. Read from file\n");
					printf("----------------------\n");
					if (scanf("%d", &key))
					{
						isReturn = true;
						switch (key)
						{
						case 0:
							break;
						case mHead:
							method = mHead;
							break;
						case mTail:
							method = mTail;
							break;
						case 3:
							method = mHead;
							isFileOpen = true;
							printf("Input file name: ");
							fflush(stdin);
							gets(fname);
							fflush(stdin);
							head = loadFile(fname);
							if (head == NULL)
							{
								method == mNull;
							}
							break;
						default:
							isReturn = false;
							printf(NO_FUNCTION);
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
				printf(LINE);
				if ((method == mHead || method == mTail) && isFileOpen == false)
				{
					printf("Input the first student.\n");
					head = stuNew();
				}
				break;
			case 2:
				switch (method)
				{
				case 1:
					// head = insertHeadNew(head);
					if (isSequentialized)
					{
						object = stuNew();
						head = nodeCalxSeqInst(head, object);
					}
					else
					{
						head = nodeCalxInstHeadNew(head);
					}
					break;
				case 2:
					// insertTailNew(head);
					if (isSequentialized)
					{
						object = stuNew();
						head = nodeCalxSeqInst(head, object);	
					}
					else
					{
						nodeCalxInstTailNew(head);
					}
					break;
				default:
					printf(STRING_NO_CREATED);
					break;
				}
				break;
			case 3:
				printf("Input the num of the student to delete: ");
				scanf("%d", &temp);
				// delete(head, temp);
				head = nodeCalxFindDelete(head, num, &temp);
				if (head == NULL)
				{
					method = 0;
				}
				break;
			case 4:
				// stuPrint(head);
				// nodeCalxPrintall(head);
				while (true)
				{
					printf("--------Output--------\n");
					printf("0. Return to main menu\n");
					printf("1. Screen\n");
					printf("2. File\n");
					printf("----------------------\n");
					if (scanf("%d", &key))
					{
						isReturn = true;
						switch (key)
						{
						case 0:
							break;
						case 1:
							nodeCalxPrintall(head);
							break;
						case 2:
							printf("Input file name: ");
							fflush(stdin);
							gets(fname);
							fflush(stdin);
							fp = fopen(fname, "wb");
							saveFile(head, fp);
							break;
						default:
							printf("Not valid integer.\n");
							isReturn = false;
							break;
						}
					}
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
				break;
			case 5:
				if (method == 0)
				{
					printf(STRING_NO_CREATED);
					break;
				}
				printf("Input the num of the student to find: ");
				scanf("%d", &temp);
				// object = findNum(head, temp);
				// stuPrintPart(object);
				object = head;
				while (object != NULL)
				{
					if (nodeCalxCheck(object, num, &temp))
					{
						break;
					}
					object = object->next;
				}
				nodeCalxPrint(object);
				break;
			case 6:
				isSequentialized = true;
				object = nodeCalxMergeSort(head, NULL);
				head = object;
			case 9:
				system("CLS");
				break;
			default:
				printf(NO_FUNCTION);
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

void nodeCalxLogo(void)
{
	printf("     __          _        ___      _      \n");
	printf("  /\\ \\ \\___   __| | ___  / __\\__ _| |_  __\n");
	printf(" /  \\/ / _ \\ / _` |/ _ \\/ /  / _` | \\ \\/ /\n");
	printf("/ /\\  / (_) | (_| |  __/ /__| (_| | |>  < \n");
	printf("\\_\\ \\/ \\___/ \\__,_|\\___\\____/\\__,_|_/_/\\_\\\n");
	return;
}

Node *inputFile(FILE *fp)
{
	char *ch;
	char *str[_NODE_NLEN];
	Node *head = malloc(sizeof(Node));
	Node *node = head;
	Node *pt = NULL;
	while (fscanf(fp, "%d	%s	%d	%d	%d	%d	%d", &node->gender, node->name, node->score, node->age, node->height, node->weight) != EOF)
	{
		pt = malloc(sizeof(Node));
		node->next = pt;
		node = pt;
	}
	node->next = NULL;
	return head;
}

Node *loadFile(char fname[])
{
	Node *p, *s, *head = NULL;
	FILE *fp;
	fp = fopen(fname, "rb");
	if (fp == NULL)
	{
		return NULL;
	}
	while (!feof(fp))
	{
		if (head == NULL)
		{
			p = (Node *)malloc(sizeof(Node));
			fread(p, sizeof(Node), 1, fp);
			if (feof(fp))
			{
				return NULL;
			}
			head = p;
			s = p;
			continue;
		}
		p = (Node *)malloc(sizeof(Node));
		fread(p, sizeof(Node), 1, fp);
		if (feof(fp))
		{
			s->next = NULL;
			break;
		}
		s->next = p;
		s = p;
		p->next = NULL;
	}
	fclose(fp);
	return head;
}

int saveFile(Node *head, FILE *fp)
{
	Node *p = head;
	if (fp == NULL)
	{
		return -1;
	}
	while (p != NULL)
	{
		fwrite(p, sizeof(Node), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 0;
}
