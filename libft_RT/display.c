/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:26:07 by omeyer            #+#    #+#             */
/*   Updated: 2017/09/01 16:35:54 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


/*
 * this function is going to take in th e index of the of the the
 * Image_plane 
void	d_point(void *mlx, void *win, t_node **head, int colour)
{
	t_node	*temp;

	temp = *head;
	while (temp != NULL)
	{
		mlx_pixel_put(mlx, win, (int)temp->data.x, 
				(int)temp->data.y, colour);
		temp = temp->next;
	}
}
*/

t_2d_vector	set_axis(t_point point)
{
	t_2d_vector axis;

	axis.x = point.x + (WIDTH) / 2;
	axis.y = (HEIGHT - point.y) / 2;
	return (axis);
}

void	display(char *filename)
{
	void		*mlx;
	void		*win;
//	t_2d_vector axis;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Ray_Tracer");
	file_handling(filename, mlx, win);
	mlx_loop(mlx);
}
