
#include "rt.h"

static int	save_camera(char *line, t_scene *scene)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (0);
	scene->camera.x = ft_atoi(split[0]);
	scene->camera.y = ft_atoi(split[1]);
	scene->camera.z = ft_atoi(split[2]);
	ft_freestrsplit(split);
	return (1);
}

static int	save_plane(char	*line, t_scene *scene)
{
	char **split;

	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || split[2])
		return (0);
	scene->plane.x = ft_atoi(split[0]);
	scene->plane.y = ft_atoi(split[1]);
	ft_freestrsplit(split);
	return (1);
}

static int	save_light(char *line, t_scene *scene)
{
	char 	**split;
	t_light	*light;	

	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2] || !split[3] || split[4])
		return (0);
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	light->x = ft_atoi(split[0]);
	light->y = ft_atoi(split[1]);
	light->z = ft_atoi(split[2]);
	light->r = ft_atoi(split[3]);
	light->next = NULL;
	add_light(&(scene->light), light);
	return (1);
}

static int	process_line(char *line, t_scene *scene)
{
	static char	selector = ' ';

	if (selector != ' ')
	{
		if (selector == 'C')
			return (save_camera(line, scene));
		else if (selector == 'I')
			return (save_plane(line, scene));
		else if (selector == 'L')
			return (save_light(line, scene));
		selector = ' ';
	}
	else
	{
		if (ft_strstr(line, "Camera"))
			selector = 'C';
		else if (ft_strstr(line, "Image_Plane"))
			selector = 'I';
		else if (ft_strstr(line, "SPHERE"))
			selector = 'S';
		else if (ft_strstr(line, "CYLINDER"))
			selector = 'Y';
		else if (ft_strstr(line, "CONE"))
			selector = 'N';
		else if (ft_strstr(line, "Ligh_source"))
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
	return (ret);
}
