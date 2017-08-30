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
#include "libft/libft.h"

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

// create an object struct that will work with parametric equation

typedef struct	s_sphere
{
	t_point		centre;
	char		pixel;
	float		r;
}				t_sphere;

void            file_handling(char  *filename);

#endif
