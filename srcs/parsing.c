/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:31:26 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/10 15:46:29 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

static void	malloc_objs(t_objs *objs)
{
	if (!(objs->light = (t_light*)malloc(sizeof(t_light) * 32)))
		error(2);
	if (!(objs->spheres = (t_sphere*)malloc(sizeof(t_sphere) * 32)))
		error(2);
	if (!(objs->plans = (t_plan*)malloc(sizeof(t_plan) * 32)))
		error(2);
	if (!(objs->cones = (t_cone*)malloc(sizeof(t_cone) * 32)))
		error(2);
	if (!(objs->cylinders = (t_cylinder*)malloc(sizeof(t_cylinder) * 32)))
		error(2);
}

static void	init_objs(t_objs *objs, t_cam *cam)
{
	*cam = init_cam(init_pt(0.0, 0.0, 0.0), init_vec(0.0, 0.0, 1.0));
	objs->nb_lights = 0;
	objs->nb_spheres = 0;
	objs->nb_plans = 0;
	objs->nb_cones = 0;
	objs->nb_cylinders = 0;
	objs->color.ambiant = 0.0;
	objs->color.diffuse = DIFFUSE;
	objs->color.specular = SPECULAR;
}

void		verif_figure(char *line, t_objs *objs, t_cam *cam)
{
	if (!ft_strncmp(line, "sphere", 5))
		verif_sphere(line, objs);
	else if (!ft_strncmp(line, "plan", 3))
		verif_plan(line, objs);
	else if (!ft_strncmp(line, "cone", 3))
		verif_cone(line, objs);
	else if (!ft_strncmp(line, "cylinder", 7))
		verif_cylinder(line, objs);
	else if (!ft_strncmp(line, "cam", 2))
		verif_camera(line, cam);
	else if (!ft_strncmp(line, "light", 4))
		verif_light(line, objs);
	else if (!ft_strncmp(line, "ambiant=", 7))
		verif_ambiant(line, objs);
	else if (!ft_strncmp(line, "diffuse=", 7))
		verif_diffuse(line, objs);
	else if (!ft_strncmp(line, "specular=", 8))
		verif_specular(line, objs);
	else if (ft_strcmp(line, ""))
		error(4);
}

void		parsing(int argc, char **argv, t_cam *cam, t_objs *objs)
{
	char	*line;
	int		fd;
	int		gnl;

	if (argc != 2)
		error(1);
	init_objs(objs, cam);
	malloc_objs(objs);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error(2);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		verif_figure(line, objs, cam);
		free(line);
	}
	if (gnl == -1)
		error(2);
	if (close(fd) == -1)
		error(2);
}
