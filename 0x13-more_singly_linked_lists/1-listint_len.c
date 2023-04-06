#include "lists.h"

/**
 * listint_len - Returns the number of elements in a listint_t list.
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The number of elements in the listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t counts= 0;

	while (h != NULL)
	{
		counts++;
		h = h->next;
	}

	return (counts);
}
