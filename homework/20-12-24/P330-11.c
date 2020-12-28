/**
 * So hard
 */

#define _NODE_NLEN 0x20
#include "../../library/nodeCalx.h"

Node *deleteSame(Node *corresp, Node *delee);

int main(void)
{
	/* Test data */
	Node a = {1, 114, 100, 1, 1, false, "Billy Herrington", NULL};
	Node b = {2, 116, 201, 2, 2, true, "Van Darkholme", &a};
	Node *head_1 = &b;

	Node c = {3, 114, 312, 3, 3, false, "Ikariya Biollante", NULL};
	Node d = {4, 115, 423, 4, 4, true, "Gosaku Kamata", &c};
	Node *head_2 = &d;

	/** We know that we cannot free a named variable. 
	 * But usually the linked list is created by malloc().
	 * And in my environment this runs without warning.
	*/
	head_2 = deleteSame(head_1, head_2);
	nodeCalxPrintall(head_2);
	return 0;
}

/**
 * Return the new head of delee.
 * It has not been carefully tested for all cases.
 * I've tried to annotate it.
 */
Node *deleteSame(Node *corresp, Node *delee)
{
	/* Cyclic pointer in corresp */
	Node *pC = corresp;
	/* Cyclic pointer in delee */
	Node *pD = delee;
	/* Helper pointer for delete */
	Node *pS;

	/* confirm delee and corresp un-null */
	if (delee == NULL || corresp == NULL)
	{
		return delee;
	}

	while (pC != NULL)
	{
		if (delee->num == pC->num)
		{
			delee = pD->next;
			free(pD);
			if (delee == NULL)
			{
				return NULL;

			} // if no more nodes

			pC = corresp;			// reset
			pD = delee;				// reset
			continue;				// delee has been the next node

		} // if find a node to delete

		pC = pC->next;				// check the next node in corrresp

	} // while with unchecked node after pC

	if (delee->next = NULL)
	{
		return delee;

	} // if no more nodes

	pC = corresp;					// reset
	pD = delee;						// reset

	while (true)
	{
		while (pC != NULL)
		{
			if (pD->next == NULL)
			{
				return delee;		// finally return here

			} // if delee is throughly examined

			if (pD->next->num == pC->num)
			{
				pS = pD->next;		// not wild pointer
				pD->next = pS->next;
				free(pS);
				pC = corresp;		// reset
				continue;			// pD->next has been the next node
			}

			pC = pC->next;			// check the next node in corrresp

		} // while (pC != NULL)

		pD = pD->next;				// pD is not to be deleted

	} // while (true), in fact only if pD->next != NULL

	/* Must have returned in while (true) */
}
