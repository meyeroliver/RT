
#include "rt.h"

static int	save_camera(char *line, t_scene *scene)
{
	char	**split;

	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (0);
	scene->camera.x = (float)ft_atoi(split[0]);
	scene->camera.y = (float)ft_atoi(split[1]);
	scene->camera.z = (float)ft_atoi(split[2]);
	ft_freestrsplit(split);
	return (1);
}

static int	save_plane(char	*line, t_scene *scene)
{
	char **split;

	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (0);
	scene->plane.x = (float)ft_atoi(split[0]);
	scene->plane.y = (float)ft_atoi(split[1]);
	scene->plane.ch = split[2][0];
	ft_freestrsplit(split);
	if (scene->plane.x == 0 || scene->plane.y == 0)
		return (0);
	return (1);
}

static int	save_light(char *line, t_scene *scene)
{
	char 	**split;
	t_light	*light;	

	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	if (!split[0] || !split[1] || !split[2] || !split[3] || !split[4] || split[5])
		return (0);
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	light->x = (float)ft_atoi(split[0]);
	light->y = (float)ft_atoi(split[1]);
	light->z = (float)ft_atoi(split[2]);
	light->r = (float)ft_atoi(split[3]);
	light->ch = split[4][0];
	light->next = NULL;
	add_light(&(scene->light), light);
	ft_freestrsplit(split);
	return (1);
}

static int	process_line(char *line, t_scene *scene)
{
	static char	selector = ' ';
	char		t_selector;

	if (selector != ' ')
	{
		t_selector = selector;
		selector = ' ';
		if (t_selector == 'C')
			return (save_camera(line, scene));
		else if (t_selector == 'I')
			return (save_plane(line, scene));
		else if (t_selector == 'L')
			return (save_light(line, scene));
		else
			return (save_object(line, scene, t_selector));
	}
	else
	{
		if (ft_strstr(line, "Camera"))
			selector = 'C';
		else if (ft_strstr(line, "Image_plane"))
			selector = 'I';
		else if (ft_strstr(line, "Sphere"))
			selector = 'S';
		else if (ft_strstr(line, "Cylinder"))
			selector = 'Y';
		else if (ft_strstr(line, "Cone"))
			selector = 'N';
		else if (ft_strstr(line, "Light_source"))
			selector = 'L';
	}
	return (1);
}

int			file_okay(char *filename, t_scene *scene)
{
	int 	fd;
	char	*line;
	int		ret;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	ret = 1;
	line = NULL;
	while (get_next_line(fd, &line) > 0 && ret)
		ret = process_line(line, scene);
	if (line)
		free(line);
	return (ret);
}
