#include "sort.h"
/**
 * return_head - function to return the head off the list
 * @listt: the list
 *
 * Return: the head of the list
 */
listint_t *return_head(listint_t *listt)
{
	while (listt->prev != NULL)
		listt = listt->prev;

	return listt;
}

/**
 * insertion_sort_list - function that use insertion sort to sort the list
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1;
	listint_t *temp2;
	listint_t *spot;


	temp1 = return_head(*list);
	for (temp1 = temp1->next; temp1;)
	{
		spot = temp1->next;
		while (temp1->prev != NULL && temp1->prev->n > temp1->n)
		{
			temp2 = temp1->prev;
			temp2->next = temp1->next;
			temp1->prev = temp2->prev;
			temp2->prev = temp1;
			temp1->next = temp2;

			if (temp1->next != NULL)
				temp1->prev->next = temp1;
			if (temp2->next != NULL)
				temp2->next->prev = temp2;
			print_list(return_head(*list));
		}
		temp1 = spot;
	}
	*list = return_head(*list);
}
