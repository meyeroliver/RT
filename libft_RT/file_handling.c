/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 07:36:17 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/29 15:21:50 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char		selector(char *line)
{
	static char	selector = ' ';

	if (ft_strstr(line, "Camera"))
		selector = 'C';
	if (ft_strstr(line, "Image_plane"))
		selector = 'I';
	if (ft_strstr(line, "Sphere"))
		selector = 'S';
	if (ft_strstr(line, "Light_source"))
		selector = 'L';
	return (selector);
}

static t_point	**pop_plane(char **split, t_point **image_plane)
{
	int			i;
	int			j;
	t_point		temp;

	i = 0;
	while (i < ft_atoi(split[1]))
	{
		j = 0;
		while (j < ft_atoi(split[0]))
		{
			temp.x = j;
			temp.y = i;
			temp.z = 0;
			image_plane[i][j] = temp;
			j++;
		}
		i++;
	}
	return (image_plane);
}

static t_point	sub_vector(t_point v1, t_point v2)
{
	t_point		new_v;

	new_v.x = v1.x - v2.x;
	new_v.y = v1.y - v2.y;
	new_v.z = v1.z - v2.z;
	return (new_v);
}

static t_point	cross_product(t_point v1, t_point v2)
{
	t_point     new_v;

	new_v.x = (v1.y * v2.z) - (v2.y * v1.z);
	new_v.y = -((v1.x * v2.z) - (v2.x * v1.z));
	new_v.z = (v1.x * v2.y) - (v2.x * v1.y);
	return (new_v);
}

static float	magnitude(t_point v1)
{
	float	magnitude;

	magnitude = sqrt(powf(v1.x, 2) + powf(v1.y, 2) + powf(v1.z, 2));
	return (magnitude);
}
static t_point	scalar_mult(t_point v1, float k)
{
	v1.x = v1.x * k;
	v1.y = v1.y * k;
	v1.z = v1.z * k;
	return (v1);
}
static float	dist_btwn_pnt_to_line(t_point v1, t_point v2, t_point v0)
{
	float	dist;
	float	numerator;
	float	denominator;

	denominator = magnitude(sub_vector(v1, v2));
	numerator = magnitude(cross_product(sub_vector(v2, v1),
				sub_vector(v1, v0)));
	dist = numerator / denominator;
	return (dist);
}

void			file_handling(char	*filename)
{
	int			fd;
	char		**split;
	t_point		*camera;
	t_sphere	*sphere;
	t_sphere	*light;
	t_point     p1;
	t_point		**image_plane;
	int			i = 0;
	int			j = 0;
	int			plane_w;
	int			plane_h;
	char		*line;
	int			skip_cam = 0;
	int			skip_plane = 0;
	int			skip_sphere = 0;
	int         skip_light = 0;

	//we need to create a function that will malloc	for the scene
	//	 printf("\n awe-%s", filename);
	if (!(camera = (t_point *)malloc(sizeof(t_point))))
		return ;
	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return ;
	if (!(light = (t_sphere *)malloc(sizeof(t_sphere))))
		return ;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(filename);
		ft_putstr(" does not exist. Please insert a valid filname\n");
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (selector(line) == 'C')
		{
			if (skip_cam > 0)
			{
				split = ft_strsplit(line, ' ');
				camera->x = (float)ft_atoi(split[0]);
				camera->y = (float)ft_atoi(split[1]);
				camera->z = (float)ft_atoi(split[2]);
			}
			skip_cam++;
		}
		else if (selector(line) == 'I')
		{
			if (skip_plane > 0)
			{
				split = ft_strsplit(line, ' ');
				plane_h = ft_atoi(split[1]);
				plane_w = ft_atoi(split[0]);
				if(!(image_plane=(t_point **)malloc(sizeof(t_point *)*ft_atoi(split[1]))))                                                                              	return ;
				while (i < ft_atoi(split[0]))
				{
					if (!(image_plane[i]=(t_point *)malloc(sizeof(t_point)* ft_atoi(split[0]))))
						return ;
					i++;
				}
				image_plane = pop_plane(split, image_plane);
			}
			skip_plane++;
		}/*
		if (selector(line) == 'S')
		{
			if (skip_sphere > 0)
			{
				split = ft_strsplit(line, ' ');
				sphere->centre.x = (float)ft_atoi(split[0]);
				sphere->centre.y = (float)ft_atoi(split[1]);
				sphere->centre.z = (float)ft_atoi(split[2]);
				sphere->r = (float)ft_atoi(split[3]);
				sphere->pixel = split[4][0];
			}
			skip_sphere++;
		}*/
		if (selector(line) == 'L')
		{
			if (skip_light > 0)
			{
				split = ft_strsplit(line, ' ');
				light->centre.x = (float)ft_atoi(split[0]);
				light->centre.y = (float)ft_atoi(split[1]);
				light->centre.z = (float)ft_atoi(split[2]);
				light->r = (float)ft_atoi(split[3]);
				light->pixel = split[4][0];
			}
			skip_light++;
		}
		else if (selector(line) == 'S')
		{
			if (skip_sphere> 0)
			{
				split = ft_strsplit(line, ' ');
				sphere->centre.x = (float)ft_atoi(split[0]);
				sphere->centre.y = (float)ft_atoi(split[1]);
				sphere->centre.z = (float)ft_atoi(split[2]);
				sphere->r = (float)ft_atoi(split[3]);
				sphere->pixel = split[4][0];
			}
			skip_sphere++;
		}			
	}
	//FAKE RAY-TRACER
	i = 0;
	while (i < plane_h)
	{
		j = 0;
		while (j < plane_w)
		{
			p1 = image_plane[i][j];
			if (dist_btwn_pnt_to_line(p1,
						scalar_mult(sub_vector(p1, *camera), 500),
						sphere->centre) < sphere->r)
			{
				printf("%c", sphere->pixel);
			}
			else if (dist_btwn_pnt_to_line(p1, 
						scalar_mult(sub_vector(p1, *camera), 500), 
						light->centre) < light->r)
			{
				printf("%c", light->pixel);
			}
			else 
			{
				printf("0");
			}

			j++;
		}
		i++;
		printf("\n");
	}

	if (close(fd) == -1)
	{
		ft_putstr(filename);
		ft_putstr(" did not close correctly\n");
	}
}

