#include "shell.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.

 * @head: head of the linked list.
 * @sep: separator found (; | &).

 * Return: address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees a sep_list

 * @head: head of the linked list.

 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr == *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;

