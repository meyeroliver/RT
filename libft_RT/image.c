
#include "rt.h"

static t_point	camera_point(t_camera camera)
{
	t_point	pnt;

	pnt.x = camera.x;
	pnt.y = camera.y;
	pnt.z = camera.z;
	pnt.ch = ' ';
	return (pnt);
}

static t_point	object_point(t_object *obj)
{
	t_point	pnt;

	pnt.x = obj->x;
	pnt.y = obj->y;
	pnt.z = obj->z;
	pnt.ch = 'x';
	return (pnt);
}

void	draw_image(t_scene *scene)
{
	int 		h;
	int 		w;
	t_point		pnt;
	float		dst;
	t_point		obt;
	t_object	*iter;
	t_point		*prnt;

	h = -1;
	iter = scene->object;
	while (++h < scene->plane.y)
	{
		w = -1;
		while (++w < scene->plane.x)
		{
			pnt.x = w;
			pnt.y = h;
			pnt.z = 0;
			pnt.ch = ' ';
			iter = scene->object;
			prnt = NULL;
			while (iter)
			{
				obt = object_point(iter);
				dst = dist_btwn_pnt_to_line(pnt,
					scalar_mult(sub_vector(pnt,
							camera_point(scene->camera)), 500),
					obt);
				if (dst < iter->r)
					prnt = (t_point*)ft_memdup((unsigned char*)&obt, sizeof(t_point));
				iter = iter->next;
			}
			//if (dst < scene->object->r)
			if (prnt)
			{
				ft_putchar(prnt->ch);
				free(prnt);
			}
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
