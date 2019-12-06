/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:30:27 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/09 13:51:56 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		normal_cone(t_cone cone, t_ray ray)
{
	t_pt	i;
	t_vec	si;
	double	dist_sp;
	double	cos_t;
	t_pt	p;

	i = move_pt(ray.origin, mul_vec(ray.dir, ray.t));
	si = vec(cone.tip, i);
	cos_t = (dot_vec(cone.dir, si) / (size_vec(cone.dir) * size_vec(si)));
	if (cos_t == 0)
		return (vec(cone.tip, ray.origin));
	dist_sp = size_vec(si) * cos_t;
	p = move_pt(cone.tip, mul_vec(unit_vec(cone.dir), dist_sp));
	return (vec(p, i));
}

t_vec		normal_cylinder(t_cylinder cyl, t_ray ray)
{
	t_pt	i;
	t_vec	si;
	double	dist_sp;
	double	cos_t;
	t_pt	p;

	i = move_pt(ray.origin, mul_vec(ray.dir, ray.t));
	si = vec(cyl.pt, i);
	cos_t = dot_vec(cyl.dir, si) / (size_vec(cyl.dir) * size_vec(si));
	dist_sp = size_vec(si) * cos_t;
	p = move_pt(cyl.pt, mul_vec(unit_vec(cyl.dir), dist_sp));
	return (vec(p, i));
}

t_vec		normal_sphere(t_sphere sphere, t_ray ray)
{
	return (vec(sphere.c, move_pt(ray.origin, mul_vec(ray.dir, ray.t))));
}

t_vec		normal_plan(t_plan plan, t_ray ray)
{
	double	tmp;
	t_vec	unit;

	tmp = dot_vec(ray.dir, plan.norme);
	unit = unit_vec(plan.norme);
	return ((tmp < 0) ? unit : mul_vec(unit, -1));
}
