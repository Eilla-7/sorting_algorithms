#include "sort.h"
/**
 * return_head - function to return the head of the list
 * @listt: the list
 *
 * Return: the head of the list
 */
listint_t *return_head(listint_t *listt)
{
	while (listt && listt->prev != NULL)
		listt = listt->prev;

	return listt;
}



/**
 * insertion_sort_list - function that uses insertion sort to sort the list
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	
	listint_t *temp1;
	listint_t *temp2;
       	listint_t *spot;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp1 = return_head(*list);
	for (temp1 = temp1->next; temp1; temp1 = spot)
	{
		spot = temp1->next;

		while (temp1->prev != NULL && temp1->prev->n > temp1->n)
		{
			temp2 = temp1->prev;

			if (temp2->prev != NULL)
				temp2->prev->next = temp1;
			if (temp1->next != NULL)
				temp1->next->prev = temp2;

			temp1->prev = temp2->prev;
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp2->prev = temp1;

			if (temp1->prev == NULL)
				*list = temp1;
			print_list(return_head(*list));
		}
	}
}

