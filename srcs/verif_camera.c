/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:56:38 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/10 13:57:38 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void		verif_camera(char *line, t_cam *cam)
{
	char	**tab_p;
	char	**tab_v;
	char	**tab;
	t_pt	pt;
	t_vec	vec;

	if (line[3] != '(' || line[ft_strlen(line) - 1] != ')')
		error(4);
	line[ft_strlen(line) - 1] = '\0';
	tab = ft_strsplit(&line[4], '/');
	tab_p = ft_strsplit(tab[0], ',');
	tab_v = ft_strsplit(tab[1], ',');
	if (!tab[1] || tab[2] || !tab_p[2] || tab_p[3] || !tab_v[2] || tab_v[3])
		error(3);
	if (!ft_isnumber(tab_p[0]) || !ft_isnumber(tab_p[1])
			|| !ft_isnumber(tab_p[2]) || !ft_isnumber(tab_v[0])
			|| !ft_isnumber(tab_v[1]) || !ft_isnumber(tab_v[2]))
		error(3);
	pt = init_pt(ft_atoi(tab_p[0]), ft_atoi(tab_p[1]), ft_atoi(tab_p[2]));
	vec = init_vec(ft_atoi(tab_v[0]), ft_atoi(tab_v[1]), ft_atoi(tab_v[2]));
	*cam = init_cam(pt, unit_vec(vec));
	free_split(tab_p, tab_v, tab);
}
