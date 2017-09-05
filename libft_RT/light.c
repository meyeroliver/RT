
#include "rt.h"

void	add_light(t_light **head, t_light *light)
{
	t_light *temp;

	if (!(*head))
		(*head) = light;
	else
	{
		temp = (*head);
		while (temp->next)
			temp = temp->next;
		temp->next = light;
	}
}
