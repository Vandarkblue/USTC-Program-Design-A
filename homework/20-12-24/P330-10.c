#define _NODE_NLEN 0x20
#include "../../library/nodeCalx.h"

int main(void)
{
	/* Test data */
	Node a = {1, 114, 100, 1, 1, false, "Billy Herrington", NULL};
	Node b = {2, 116, 201, 2, 2, true, "Van Darkholme", &a};
	Node *head_1 = &b;

	// Node c = {3, 117, 312, 3, 3, false, "Ikariya Biollante", NULL};
	// Node d = {4, 115, 423, 4, 4, true, "Gosaku Kamata", &c};

	Node *head_2 = stuNew();
	head_2 = nodeCalxInstHeadNew(head_2);
	Node *head = NULL;

	head = nodeCalxMergeSort(head_1, head_2);
	nodeCalxPrintall(head);

	return 0;
}
