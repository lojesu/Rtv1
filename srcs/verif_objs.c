/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:31:21 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/10 17:14:12 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void		verif_sphere(char *line, t_objs *objs)
{
	char	**tab;
	char	**tab_p;
	char	**r;
	int		color;
	t_pt	pt;

	if (line[6] != '(' || line[ft_strlen(line) - 1] != ')')
		error(4);
	line[ft_strlen(line) - 1] = '\0';
	tab = ft_strsplit(&line[7], '/');
	tab_p = ft_strsplit(tab[0], ',');
	r = ft_strsplit(tab[1], ',');
	if (!tab[2] || tab[3] || !tab_p[2] || tab_p[3] || !r[0] || r[1])
		error(3);
	if (!ft_isnumber(r[0]) || !ft_isnumber(tab_p[0]) || ft_atoi(r[0]) < 0
			|| !ft_isnumber(tab_p[1]) || !ft_isnumber(tab_p[2]))
		error(3);
	pt = init_pt(ft_atoi(tab_p[0]), ft_atoi(tab_p[1]), ft_atoi(tab_p[2]));
	verif_color(tab[2]);
	color = convert_color(tab[2]);
	objs->spheres[objs->nb_spheres] = init_sphere(pt, ft_atoi(r[0]), color);
	objs->nb_spheres++;
	if (objs->nb_spheres == 32)
		error(8);
	free_split(tab, tab_p, r);
}

void		verif_plan(char *line, t_objs *objs)
{
	char	**tab;
	char	**tab_n;
	char	**tab_p;
	t_pt	pt;
	t_vec	n;

	if (line[4] != '(' || line[ft_strlen(line) - 1] != ')')
		error(4);
	line[ft_strlen(line) - 1] = '\0';
	tab = ft_strsplit(&line[5], '/');
	tab_n = ft_strsplit(tab[1], ',');
	tab_p = ft_strsplit(tab[0], ',');
	if (!tab[2] || tab[3] || !tab_n[2] || tab_n[3] || !tab_p[2] || tab_p[3])
		error(3);
	if (!ft_isnumber(tab_n[0]) || !ft_isnumber(tab_n[1])
			|| !ft_isnumber(tab_n[2]) || !ft_isnumber(tab_p[0])
			|| !ft_isnumber(tab_p[1]) || !ft_isnumber(tab_p[2]))
		error(3);
	pt = init_pt(ft_atoi(tab_p[0]), ft_atoi(tab_p[1]), ft_atoi(tab_p[2]));
	n = init_vec(ft_atoi(tab_n[0]), ft_atoi(tab_n[1]), ft_atoi(tab_n[2]));
	verif_color(tab[2]);
	objs->plans[objs->nb_plans] = init_plan(pt, n, convert_color(tab[2]));
	objs->nb_plans++;
	(objs->nb_plans == 32) ? error(8) : free_split(tab, tab_p, tab_n);
}

static void	verif_number(char **tab, char **tab_v, char **tab_p)
{
	if (!ft_isnumber(tab_v[0]) || !ft_isnumber(tab_v[1])
			|| !ft_isnumber(tab_v[2]) || !ft_isnumber(tab_p[0])
			|| !ft_isnumber(tab_p[1]) || !ft_isnumber(tab_p[2])
			|| !ft_isnumber(tab[2]))
		error(3);
}

void		verif_cone(char *line, t_objs *objs)
{
	char	**tab;
	char	**tab_p;
	char	**tab_v;
	t_pt	pt;
	t_vec	vec;

	if (line[4] != '(' || line[ft_strlen(line) - 1] != ')')
		error(4);
	line[ft_strlen(line) - 1] = '\0';
	tab = ft_strsplit(&line[5], '/');
	tab_p = ft_strsplit(tab[0], ',');
	tab_v = ft_strsplit(tab[1], ',');
	if (!tab[3] || tab[4] || !tab_v[2] || tab_v[3] || !tab_p[2] || tab_p[3])
		error(3);
	verif_number(tab, tab_v, tab_p);
	pt = init_pt(ft_atoi(tab_p[0]), ft_atoi(tab_p[1]), ft_atoi(tab_p[2]));
	vec = init_vec(ft_atoi(tab_v[0]), ft_atoi(tab_v[1]), ft_atoi(tab_v[2]));
	vec = unit_vec(vec);
	verif_color(tab[3]);
	(ft_atoi(tab[2]) > 0 && ft_atoi(tab[2]) < 90)
		? objs->cones[objs->nb_cones] =
		init_cone(vec, pt, ft_atoi(tab[2]), convert_color(tab[3])) : error(3);
	objs->nb_cones++;
	(objs->nb_cones == 32) ? error(8) : free_split(tab, tab_p, tab_v);
}

void		verif_cylinder(char *line, t_objs *objs)
{
	char	**tab;
	char	**tab_v;
	char	**tab_p;
	t_vec	vec;
	t_pt	pt;

	if (line[8] != '(' || line[ft_strlen(line) - 1] != ')')
		error(4);
	line[ft_strlen(line) - 1] = '\0';
	tab = ft_strsplit(&line[9], '/');
	tab_p = ft_strsplit(tab[0], ',');
	tab_v = ft_strsplit(tab[1], ',');
	if (!tab[3] || tab[4] || !tab_v[2] || tab_v[3] || !tab_p[2] || tab_p[3])
		error(3);
	verif_number(tab, tab_v, tab_p);
	vec = init_vec(ft_atoi(tab_v[0]), ft_atoi(tab_v[1]), ft_atoi(tab_v[2]));
	pt = init_pt(ft_atoi(tab_p[0]), ft_atoi(tab_p[1]), ft_atoi(tab_p[2]));
	verif_color(tab[3]);
	(ft_atoi(tab[2]) > 0) ? objs->cylinders[objs->nb_cylinders] =
	init_cylinder(pt, vec, ft_atoi(tab[2]), convert_color(tab[3])) : error(3);
	objs->nb_cylinders++;
	if (objs->nb_cylinders == 32)
		error(8);
	free_split(tab, tab_p, tab_v);
}
