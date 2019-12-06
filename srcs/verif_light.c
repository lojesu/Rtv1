/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:25:28 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/10 16:47:09 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void		verif_ambiant(char *line, t_objs *objs)
{
	if (!ft_isnumber(&line[8]))
		error(3);
	objs->color.ambiant = ft_atoi(&line[8]) / 100.0;
	if (objs->color.ambiant > 2.0 || objs->color.ambiant < 0.0)
		error(5);
}

void		verif_diffuse(char *line, t_objs *objs)
{
	if (!ft_isnumber(&line[8]))
		error(3);
	objs->color.diffuse = ft_atoi(&line[8]) / 100.0;
	if (objs->color.diffuse > 2.0 || objs->color.diffuse < 0.0)
		error(6);
}

void		verif_specular(char *line, t_objs *objs)
{
	if (!ft_isnumber(&line[9]))
		error(3);
	objs->color.specular = ft_atoi(&line[9]) / 100.0;
	if (objs->color.specular > 2.0 || objs->color.specular < 0.0)
		error(7);
}

void		verif_light(char *line, t_objs *objs)
{
	char	**tab;
	char	**tab_p;
	t_pt	pt;

	if (line[5] != '(' || line[ft_strlen(line) - 1] != ')')
		error(4);
	line[ft_strlen(line) - 1] = '\0';
	tab = ft_strsplit(&line[6], '/');
	tab_p = ft_strsplit(tab[0], ',');
	if (!tab[1] || tab[2] || !tab_p[2] || tab_p[3])
		error(3);
	if (!ft_isnumber(tab[1]) || !ft_isnumber(tab_p[0])
			|| !ft_isnumber(tab_p[1]) || !ft_isnumber(tab_p[2]))
		error(3);
	if (ft_atoi(tab[1]) > 200 || ft_atoi(tab[1]) < 0)
		error(10);
	pt = init_pt(ft_atoi(tab_p[0]), ft_atoi(tab_p[1]), ft_atoi(tab_p[2]));
	objs->light[objs->nb_lights] = init_light(pt, ft_atoi(tab[1]));
	objs->nb_lights++;
	if (objs->nb_lights == 32)
		error(8);
	ft_tabdel_char(&tab);
	ft_tabdel_char(&tab_p);
}
