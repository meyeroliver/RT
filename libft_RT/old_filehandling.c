13 #include "rt.h"
	14
15 static char     selector(char *line)
	16 {
		17     static char selector = ' ';
		18
			19     if (ft_strstr(line, "Camera"))
			20         selector = 'C';
		21     if (ft_strstr(line, "Image_plane"))
			22         selector = 'I';
		23     if (ft_strstr(line, "Sphere"))
			24         selector = 'S';
		25     if (ft_strstr(line, "Light_source"))
			26         selector = 'L';
		27     return (selector);
		28 }
	29
30 static t_point  **pop_plane(char **split, t_point **image_plane)
	31 {
		32     int         i;
		33     int         j;
		34     t_point     temp;
		35
			36     i = 0;
		37     while (i < ft_atoi(split[1]))
			38     {
				39         j = 0;
				40         while (j < ft_atoi(split[0]))
					41         {
						42             temp.x = j;
						43             temp.y = i;
						44             temp.z = 0;
						45             image_plane[i][j] = temp;
						46             j++;
						47         }
						48         i++;
						49     }
						50     return (image_plane);
						51 }
	52
53 static t_point  sub_vector(t_point v1, t_point v2)
	54 {
		55     t_point     new_v;
		56
			57     new_v.x = v1.x - v2.x;
		58     new_v.y = v1.y - v2.y;
		59     new_v.z = v1.z - v2.z;
		60     return (new_v);
		61 }
	62
63 static t_point  cross_product(t_point v1, t_point v2)
	64 {
		65     t_point     new_v;
		66
			67     new_v.x = (v1.y * v2.z) - (v2.y * v1.z);
		68     new_v.y = -((v1.x * v2.z) - (v2.x * v1.z));
		69     new_v.z = (v1.x * v2.y) - (v2.x * v1.y);
		70     return (new_v);
		71 }
	72
73 static float    magnitude(t_point v1)
	74 {
		75     float   magnitude;
		76
			77     magnitude = sqrt(powf(v1.x, 2) + powf(v1.y, 2) + powf(v1.z, 2));
		78     return (magnitude);
		79 }
80 static t_point  scalar_mult(t_point v1, float k)
	81 {
		82     v1.x = v1.x * k;
		83     v1.y = v1.y * k;
		84     v1.z = v1.z * k;
		85     return (v1);
		86 }
87 static float    dist_btwn_pnt_to_line(t_point v1, t_point v2, t_point v0)
	88 {
		89     float   dist;
		90     float   numerator;
		91     float   denominator;
		92
			93     denominator = magnitude(sub_vector(v1, v2));
		94     numerator = magnitude(cross_product(sub_vector(v2, v1),
					95                 sub_vector(v1, v0)));
		96     dist = numerator / denominator;
		97     return (dist);
		98 }
	99
100 void            file_handling(char  *filename, void *mlx, void *win)
	101 {
		102     int         fd;
		103     char        **split;
		104     t_point     *camera;
		105     t_sphere    *sphere;
		106     t_sphere    *light;
		107     t_point     p1;
		108     t_point     **image_plane;
		109     int         i = 0;
		110     int         j = 0;
		111     t_2d_vector shift;
		112     int         plane_w;
		113     int         plane_h;
		114     char        *line;
		115     int         skip_cam = 0;
		116     int         skip_plane = 0;
		117     int         skip_sphere = 0;
		118     int         skip_light = 0;
		119
			120     //we need to create a function that will malloc for the scene
			121     //   printf("\n awe-%s", filename);
		122     if (!(camera = (t_point *)malloc(sizeof(t_point))))
			123         return ;
		124     if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
			125         return ;
		126     if (!(light = (t_sphere *)malloc(sizeof(t_sphere))))
			127         return ;
		128     fd = open(filename, O_RDONLY);
		129     if (fd == -1)
			130     {
				131         ft_putstr(filename);
				132         ft_putstr(" does not exist. Please insert a valid filname\n");
				133     }
				134     while (get_next_line(fd, &line) > 0)
					135     {
						136         if (selector(line) == 'C')
							137         {
								138             if (skip_cam > 0)
									139             {
										140                 split = ft_strsplit(line, ' ');
										141                 camera->x = (float)ft_atoi(split[0]);
										142                 camera->y = (float)ft_atoi(split[1]);
										143                 camera->z = (float)ft_atoi(split[2]);
										144             }
										145             skip_cam++;
										146         }
										147         else if (selector(line) == 'I')
											148         {
												149             if (skip_plane > 0)
													150             {
														151                 split = ft_strsplit(line, ' ');
														152                 plane_h = ft_atoi(split[1]);
														153                 plane_w = ft_atoi(split[0]);
														154                 if(!(image_plane=(t_point **)malloc(sizeof(t_point *)*ft_atoi(split[1]))))                                                                                  return ;
														155                 while (i < ft_atoi(split[0]))
															156                 {
																157                     if (!(image_plane[i]=(t_point *)malloc(sizeof(t_point)* ft_atoi(split[0]))))
																	158                         return ;
																159                     i++;
																160                 }
																161                 image_plane = pop_plane(split, image_plane);
																162             }
																163             skip_plane++;
																164         }
																165
																	166         if (selector(line) == 'L')
																	167         {
																		168             if (skip_light > 0)
																			169             {
																				170                 split = ft_strsplit(line, ' ');
																				171                 light->centre.x = (float)ft_atoi(split[0]);
																				172                 light->centre.y = (float)ft_atoi(split[1]);
																				173                 light->centre.z = (float)ft_atoi(split[2]);
																				174                 light->r = (float)ft_atoi(split[3]);
																				175                 light->color = ft_atoi(split[4]);
																				176             }
																				177             skip_light++;
																				178         }
																				179         else if (selector(line) == 'S')
																					180         {
																						181             if (skip_sphere> 0)
																							182             {
																								183                 split = ft_strsplit(line, ' ');
																								184                 sphere->centre.x = (float)ft_atoi(split[0]);
																								185                 sphere->centre.y = (float)ft_atoi(split[1]);
																								186                 sphere->centre.z = (float)ft_atoi(split[2]);
																								187                 sphere->r = (float)ft_atoi(split[3]);
																								188                 sphere->color = ft_atoi(split[4]);
																								189             }
																								190             skip_sphere++;
																								191         }
																								192         free(line);
																								193     }
																								194     //FAKE RAY-TRACER
																									195 /*  i = 0;
																											196     while (i < plane_h)
																											197     {
																											198         j = 0;
																											199         while (j < plane_w)
																											200         {
																											201             shift.x = j;
																											202             shift.y = i;
																											203             shift = set_axis(image_plane[i][j]);
																											204             p1 = image_plane[i][j];
																											205             if (dist_btwn_pnt_to_line(p1,
																											206                         scalar_mult(sub_vector(p1, *camera), 500),
																											207                         sphere->centre) < sphere->r)
																											208             {
																											209                  mlx_pixel_put(mlx, win, shift.x, shift.y, sphere->color);
																											210             }
																											211             else if (dist_btwn_pnt_to_line(p1,
																											212                         scalar_mult(sub_vector(p1, *camera), 500),
																											213                         light->centre) < light->r)
																											214             {
																											215                 mlx_pixel_put(mlx, win, shift.x, shift.y, light->color);
																											216             }
																											217             else
																											218             {
																											219                 mlx_pixel_put(mlx, win, shift.x, shift.y, BLACK);
																											220             }
																											221
																											222             j++;
																											223         }
																											224         i++;
																											225         printf("\n");
																											226     }*/
																								227
																									228     if (close(fd) == -1)
																									229     {
																										230         ft_putstr(filename);
																										231         ft_putstr(" did not close correctly\n");
																										232     }
																										233 }
