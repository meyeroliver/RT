#ifndef SDL_H
# define SDL_H
#define PI (3.141592653589793)
#define MAX 2147483647

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <SDL.h>
#include <math.h>

/*typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

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

typedef struct	s_sphere
{
	t_point		centre;
	char		pixel;
	float		r;
}				t_sphere;

void 	file handling(char  *filename);
*/

int		abs(int n);
void	swap(int *n1, int *n2);

#endif
