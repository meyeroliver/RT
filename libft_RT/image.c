
#include "rt.h"

static t_point	camera_point(t_camera camera)
{
	t_point	pnt;

	pnt.x = camera.x;
	pnt.y = camera.y;
	pnt.z = camera.z;
	pnt.ch = ' '; // the camera shouldnt have a "color"
	return (pnt);
}

static t_point	object_point(t_object *obj)
{
	t_point pnt;

	pnt.x = obj->x;
	pnt.y = obj->y;
	pnt.z = obj->z;
	pnt.dst = 0;
	pnt.ch = obj->ch;
	return (pnt);
}

static t_point	object_plane(float x, float y, char ch)
{
	t_point pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = 0;
	pnt.dst = 0;
	ch = ' ';
	pnt.ch = ch;

	return (pnt);
}

static t_point	*point_hit(t_object *head, t_point pnt, t_scene *scene)
{
	t_point		*prnt;
	t_object	*iter;
	t_point		obt;
	float		min_length;
	float		length;

	iter = head;
	prnt = NULL;
	min_length = MAX;
	while (iter)
	{
		obt = object_point(iter);
		obt.dst = dist_btwn_pnt_to_line(pnt,
				scalar_mult(sub_vector(pnt,
						camera_point(scene->camera)), MAX),
				obt);
		///////////////////////////////////////////////////////////////
		length = hit_length(scene->camera, *iter, obt.dst);
		if (length <  min_length)
		{
			///////////////////////////////////////////////////////////////
			if (obt.dst < iter->r)
			{
				if (!prnt)
					prnt = (t_point*)ft_memdup((unsigned char*)&obt, sizeof(t_point));
				else if (obt.dst < prnt->dst)
				{
					free(prnt);
					prnt = (t_point*)ft_memdup((unsigned char*)&obt, sizeof(t_point));
				}
			}
			min_length = length;
		}
		iter = iter->next;
	}
	/////////////////////////////////////////////////////////////////////
	//this is where the color calculations must occur
	/////////////////////////////////////////////////////////////////////
	return (prnt);
}

void	draw_image(t_scene *scene)
{
	int 		h;
	int 		w;
	t_point		pnt;
	t_point		*prnt;

	h = -1;
	while (++h < scene->plane.y)
	{
		w = -1;
		while (++w < scene->plane.x)
		{
			pnt = object_plane(w, h, scene->plane.ch);
			prnt = point_hit(scene->object, pnt, scene);
			if (prnt)
			{
				ft_putchar(prnt->ch);
				free(prnt);
			}
			else
				ft_putchar(pnt.ch);
		}
		ft_putchar('\n');
	}
}
