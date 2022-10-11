#include "sort.h"


/**
 * insertion_sort_list - Sorts list linked listusing
 * insertion sort
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	listint_t *nodeCurrent = NULL;
	listint_t *nodePrevious = NULL;
	listint_t *tempB;
	listint_t *tempA;

	if (list == NULL)
		return;
	
	node = (*list);
	while (node != NULL)
	{
		nodeCurrent = node;
		node = node->next;
		while (nodeCurrent->prev != NULL)
		{
			nodePrevious = nodeCurrent->prev;
			if (nodeCurrent->n < nodePrevious->n)
			{
				/*Swap*/
				tempA = nodeCurrent->next;
				tempB = nodePrevious->prev;
				nodeCurrent->next = nodePrevious;
				nodeCurrent->prev = tempB;
				nodePrevious->prev = nodeCurrent;
				nodePrevious->next = tempA;
				if (tempA != NULL)
					tempA->prev = nodePrevious;
				if (tempB != NULL)
					tempB->next = nodeCurrent;
				else
					*list = nodeCurrent;
				print_list(*list);
			} else
				break;
		}
	}

}
