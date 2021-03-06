/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 07:54:12 by omeyer            #+#    #+#             */
/*   Updated: 2017/09/06 09:42:51 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	dist_btwn_to_points(t_camera cam, t_object obt)
{
	float distance;

	distance = sqrt(powf(cam.x - obt.x, 2) + powf(cam.y - obt.y, 2)
		   	+ powf(cam.z - obt.z, 2));
	return (distance);
}

float	hit_length(t_camera camera, t_object obt, float perp_dist)
{
	float	dis_btwn_cam_obt;
	float	small_dist;
	float	hit_length;

	dis_btwn_cam_obt = dist_btwn_to_points(camera, obt);
	small_dist = sqrt(powf(obt.r, 2) - powf(perp_dist, 2));
	hit_length = sqrt(powf(dis_btwn_cam_obt, 2) +
			powf(small_dist, 2)) - small_dist;
	return (hit_length);
}
