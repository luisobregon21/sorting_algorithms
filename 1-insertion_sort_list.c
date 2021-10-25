#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: doubly link list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *tmp;
	int value = 0;

	if (list == NULL || (*list)->next == NULL)
		return;

	head = (*list)->next;

	while (head != NULL)
	{
		current = head;
		value = current->n;
		while (current->prev && current->prev->n > value)
		{
			tmp = current->prev;
			current->prev = tmp->prev;
			tmp->next = current->next;
			current->next = tmp;
			tmp->prev = current;
			if (tmp->next)
				tmp->next->prev = tmp;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		head = head->next;
	}
}
