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

typedef	struct	s_point
{
	float		x;
	float		y;
	float		z;
	float		dst;
	char		ch;
}				t_point;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

// create an object struct that will work with parametric equation

/*typedef struct	s_sphere
{
	t_pofloat		centre;
	char		pixel;
	float		r;
}				t_sphere;*/

typedef struct		s_plane
{
	float			x;
	float			y;
	float			z;
	float			a;
	float			b;
	float			c;
	char			ch;
	struct s_color	color;
}					t_plane;

typedef struct		s_object
{
	char			name[20];
	float			x;
	float			y;
	float			z;
	float			r;
	float			h;
	char			ch;
	struct s_color	color;
	struct s_object	*next;
}					t_object;

typedef struct		s_light
{
	float			x;
	float			y;
	float			z;
	float			r;
	char			ch;
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
int					save_object(char *line, t_scene *scene, char selector);
void				draw_image(t_scene *scene);
t_point				sub_vector(t_point v1, t_point v2);
t_point				cross_product(t_point v1, t_point v2);
float				magnitude(t_point v1);
t_point				scalar_mult(t_point v1, float k);
float				dist_btwn_pnt_to_line(t_point v1, t_point v2, t_point v0);
void				free_all_mem(t_scene *scene);

#endif
