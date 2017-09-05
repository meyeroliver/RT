
#include "rt.h"

static void	add_object(t_object **head, t_object *obj)
{
	t_object *temp;

	if (!(*head))
		(*head) = obj;
	else
	{
		temp = (*head);
		while (temp->next)
			temp = temp->next;
		temp->next = obj;
	}
}

static int	save_sphere(char *line, t_scene *scene)
{
	char 	**split;
	t_object *obj;

	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2] || !split[3])
		return (0);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (0);
	ft_strcpy(obj->name, "SPHERE");
	obj->x = (float)ft_atoi(split[0]);
	obj->y = (float)ft_atoi(split[1]);
	obj->z = (float)ft_atoi(split[2]);
	obj->r = (float)ft_atoi(split[3]);
	obj->next = NULL;
	obj->h = 0;
	add_object(&(scene->object), obj);
	ft_freestrsplit(split);
	return (1);
}

int			save_object(char *line, t_scene *scene, char selector)
{
	if (selector == 'S')
		return (save_sphere(line, scene));
	return (0);
}
