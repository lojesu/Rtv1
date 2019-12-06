/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:39:45 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/09 10:41:35 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libmath.h"

double		check_sphere(t_sphere sphere, t_ray ray)
{
	double	b;
	double	c;

	b = 2 * dot_vec(ray.dir, vec(sphere.c, ray.origin));
	c = dot_vec(vec(sphere.c, ray.origin), vec(sphere.c, ray.origin))
		- sphere.r * sphere.r;
	return (equation_2_deg(1, b, c));
}

double		check_plan(t_plan plan, t_ray ray)
{
	float	i;
	float	j;

	j = dot_vec(plan.norme, vec(plan.pt, ray.origin));
	i = dot_vec(plan.norme, ray.dir);
	if (fabs(i) > 0.000001)
		return ((-(j / i) > 0) ? -(j / i) : 0);
	return (0);
}

double		check_cone(t_cone cone, t_ray ray)
{
	t_vec		j;
	float		a;
	float		b;
	float		c;

	cone.dir = unit_vec(cone.dir);
	j = vec(cone.tip, ray.origin);
	a = dot_vec(ray.dir, cone.dir);
	a = a * a - pow(cos(deg_to_rad(cone.agl)), 2);
	b = 2 * (dot_vec(ray.dir, cone.dir) * dot_vec(j, cone.dir)
			- dot_vec(ray.dir, j) * pow(cos(deg_to_rad(cone.agl)), 2));
	c = dot_vec(j, cone.dir);
	c = c * c - dot_vec(j, j) * pow(cos(deg_to_rad(cone.agl)), 2);
	return (equation_2_deg(a, b, c));
}

double		check_cylinder(t_cylinder cyl, t_ray ray)
{
	t_vec	j;
	float	a;
	float	b;
	float	c;

	cyl.dir = unit_vec(cyl.dir);
	j = vec(cyl.pt, ray.origin);
	a = dot_vec(ray.dir, cyl.dir);
	a = dot_vec(ray.dir, ray.dir) - a * a;
	b = 2 * (dot_vec(ray.dir, j) - dot_vec(ray.dir, cyl.dir)
		* dot_vec(cyl.dir, j));
	c = dot_vec(j, cyl.dir);
	c = dot_vec(j, j) - c * c - pow(cyl.r, 2);
	return (equation_2_deg(a, b, c));
}
