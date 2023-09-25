#include "sort.h"

/**
  * insertion_sort_list - sorts a doubly linked list of integers in ascending
  * order using the Insertion sort algorithm
  * @list: doubly linked list to sort.
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		prev =  curr->prev;
		temp = curr;
		while (prev && prev->n > temp->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list((const listint_t *)*list);
			prev = temp->prev;
		}
		curr = curr->next;
	}
}
