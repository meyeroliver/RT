/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:36:29 by omeyer            #+#    #+#             */
/*   Updated: 2017/09/04 17:14:42 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rat_tracer()
{
	t_point	cnt;

	cnt.y = 0;
	//this while loop goes through the colomn pixel
	while (cnt.y < HEIGHT)
	{
		cnt.x = 0;
		//this while loop goes through the row pixel
		while(j < WIDTH)
		{
			//this while goes through each object in the scene
			//thinking of using a linked list of objects or an array of
			//linked lists, with each index holding a different type of
			//object.
			while (/*objects is still true*/)
			{
				while (/*while specific object is true*/)
				{
				}
			}
			cnt.x++;
		}
		cnt.y++;
	}
}
