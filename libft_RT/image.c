
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

	h = -1;
	ft_putnbr(scene->plane.y);
	ft_putchar(' ');
	ft_putnbr(scene->plane.x);
	ft_putchar('\n');
	while (++h < scene->plane.y)
	{
		w = -1;
		while (++w < scene->plane.x)
		{
			pnt.x = w;
			pnt.y = h;
			pnt.z = 0;
			pnt.ch = ' ';
			obt = object_point(scene->object);
			dst = dist_btwn_pnt_to_line(pnt,
					scalar_mult(sub_vector(pnt,
							camera_point(scene->camera)), 500),
					obt);
			if (dst < scene->object->r)
				ft_putchar(obt.ch);
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
