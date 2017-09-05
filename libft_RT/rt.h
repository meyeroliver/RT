/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:20:51 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/26 16:11:24 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
#define RT_H
#define MAX 2147483647

//#include <sdl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"

typedef struct	s_camera
{
	float		x;
	float		y;
	float		z;
}				t_camera;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

// create an object struct that will work with parametric equation

/*typedef struct	s_sphere
{
	t_point		centre;
	char		pixel;
	float		r;
}				t_sphere;*/

typedef struct		s_plane
{
	int				x;
	int				y;
	int				z;
	int				a;
	int				b;
	int				c;
	struct s_color	color;
}					t_plane;

typedef struct		s_object
{
	char			*name;
	int				x;
	int				y;
	int				z;
	int				r;
	int				h;
	char			ch;
	struct s_color	color;
}					t_object;

typedef struct		s_light
{
	int				x;
	int				y;
	int				z;
	int				r;
	struct s_color	color;
	struct s_light	*next;
}					t_light;

typedef struct		s_scene
{
	struct s_camera	camera;
	struct s_plane	plane;
	struct s_light	*light;
	struct s_object	*object;
}					t_scene;

//void            file_handling(char  *filename);
int					file_okay(char *filename, t_scene *scene);
void				add_light(t_light **head, t_light *light);

#endif
