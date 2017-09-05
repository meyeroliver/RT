/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 07:33:05 by omeyer            #+#    #+#             */
/*   Updated: 2017/08/26 09:53:47 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	initialize_scene(t_scene *scene)
{
	scene->camera.x = 0;
	scene->camera.y = 0;
	scene->camera.z = 0;
	scene->light = NULL;
	scene->object = NULL;
	scene->plane.x = 0;
	scene->plane.y = 0;
	scene->plane.z = 0;
	scene->plane.a = 0;
	scene->plane.b = 0;
	scene->plane.c = 0;
	scene->plane.color.r = 0;
	scene->plane.color.g = 0;
	scene->plane.color.b = 0;
}

int			main(int argc, char **argv)
{
	t_scene	scene;

	initialize_scene(&scene);
	if (argc - 1 != 1)
	{
		ft_putendl("usage: ./ray_tracing <map>");
		return (0);
	}
	if (!file_okay(argv[1], &scene))
	{
		ft_putendl("Usage: ./ray_tracing <map>\nInvalid file");
		return (0);
	}
	ft_putendl(scene.object->name);
	//file_handling(argv[1], &scene);
	draw_image(scene);
	return (0);
}
