#include "sort.h"
/**
 * @brief 
 * 
 * @param list 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL;

	if (!list || !*list)
		return;
	aux = *list;
	aux = aux->next;
	while (aux)
	{
		while (aux->n < aux->prev->n)
		{
			aux->prev->next = aux->next;
			if (aux->next)
				aux->next->prev = aux->prev;
			aux->next = aux->prev;
			if (aux->prev->prev)
			{
				aux->prev = aux->prev->prev;
				aux->next->prev = aux;
				aux->prev->next = aux;
			}
			else
			{
				aux->prev = NULL;
				aux->next->prev = aux;
				*list = aux;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		aux = aux->next;
	}
}