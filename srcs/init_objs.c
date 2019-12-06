/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:35:27 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/08 16:37:12 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	init_sphere(t_pt c, double r, uint32_t color)
{
	t_sphere	ret;

	ret.c = c;
	ret.r = r;
	ret.color = color;
	return (ret);
}

t_plan		init_plan(t_pt pt, t_vec norme, uint32_t color)
{
	t_plan	ret;

	ret.pt = pt;
	ret.norme = norme;
	ret.color = color;
	return (ret);
}

t_cone		init_cone(t_vec dir, t_pt pit, float agl, uint32_t color)
{
	t_cone	ret;

	ret.dir = dir;
	ret.tip = pit;
	ret.agl = agl;
	ret.color = color;
	return (ret);
}

t_cylinder	init_cylinder(t_pt pt, t_vec dir, float r, uint32_t color)
{
	t_cylinder	ret;

	ret.dir = dir;
	ret.pt = pt;
	ret.r = r;
	ret.color = color;
	return (ret);
}

t_light		init_light(t_pt pos, uint32_t intensity)
{
	t_light	ret;

	ret.pos = pos;
	ret.intensity = intensity;
	return (ret);
}
