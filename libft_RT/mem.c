
#include "rt.h"

static void	free_light(t_light **head)
{
	t_light *iter;
	t_light	*piter;

	if (!(*head))
		return ;
	iter = (*head);
	while (iter)
	{
		piter = iter;
		iter = iter->next;
		free(piter);
	}
}

static void	free_objects(t_object **head)
{
	t_object	*iter;
	t_object	*piter;

	if (!(*head))
		return ;
	iter = (*head);
	while (iter)
	{
		piter = iter;
		iter = iter->next;
		free(piter);
	}
}

void	free_all_mem(t_scene *scene)
{
	free_light(&(scene->light));
	free_objects(&(scene->object));
}
