/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:52:47 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/31 12:17:04 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point  sub_vector(t_point v1, t_point v2)
{
	t_point     new_v;

	new_v.x = v1.x - v2.x;
	new_v.y = v1.y - v2.y;
	new_v.z = v1.z - v2.z;
	return (new_v);
}

t_point  cross_product(t_point v1, t_point v2)
{
	t_point     new_v;

	new_v.x = (v1.y * v2.z) - (v2.y * v1.z);
	new_v.y = -((v1.x * v2.z) - (v2.x * v1.z));
	new_v.z = (v1.x * v2.y) - (v2.x * v1.y);
	return (new_v);
}

float    magnitude(t_point v1)
{
	float   magnitude;

	magnitude = sqrt(powf(v1.x, 2) + powf(v1.y, 2) + powf(v1.z, 2));
	return (magnitude);
}

t_point  scalar_mult(t_point v1, float k)
{
	v1.x = v1.x * k;
	v1.y = v1.y * k;
	v1.z = v1.z * k;
	return (v1);
}

float    dist_btwn_pnt_to_line(t_point v1, t_point v2, t_point v0)
{
	float   dist;
	float   numerator;
	float   denominator;

	denominator = magnitude(sub_vector(v1, v2));
	numerator = magnitude(cross_product(sub_vector(v2, v1),
				sub_vector(v1, v0)));
	dist = numerator / denominator;
	return (dist);
}
