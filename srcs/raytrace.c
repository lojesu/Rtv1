/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:30:38 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/09 17:50:00 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		throw_ray_cone(t_ray *ray, t_objs objs, uint32_t *color)
{
	size_t	i;
	double	t_min;

	i = 0;
	while (i < objs.nb_cones)
	{
		t_min = check_cone(objs.cones[i], *ray);
		if (t_min < ray->t && t_min > 0.4)
		{
			ray->t = t_min;
			ray->normal = normal_cone(objs.cones[i], *ray);
			ray->truc = 64 + i;
			*color = objs.cones[i].color;
		}
		++i;
	}
}

void		throw_ray_cylinder(t_ray *ray, t_objs objs, uint32_t *color)
{
	size_t	i;
	double	t_min;

	i = 0;
	while (i < objs.nb_cylinders)
	{
		t_min = check_cylinder(objs.cylinders[i], *ray);
		if (t_min < ray->t && t_min > 0.1)
		{
			ray->t = t_min;
			ray->normal = normal_cylinder(objs.cylinders[i], *ray);
			ray->truc = 96 + i;
			*color = objs.cylinders[i].color;
		}
		++i;
	}
}

void		throw_ray_sphere(t_ray *ray, t_objs objs, uint32_t *color)
{
	size_t	i;
	double	t_min;

	i = 0;
	*color = 0;
	while (i < objs.nb_spheres)
	{
		t_min = check_sphere(objs.spheres[i], *ray);
		if (t_min < ray->t && t_min > 0.1)
		{
			ray->t = t_min;
			ray->normal = normal_sphere(objs.spheres[i], *ray);
			ray->truc = 0 + i;
			*color = objs.spheres[i].color;
		}
		i++;
	}
}

void		throw_ray_plan(t_ray *ray, t_objs objs, uint32_t *color)
{
	size_t	i;
	double	t_min;

	i = 0;
	while (i < objs.nb_plans)
	{
		t_min = check_plan(objs.plans[i], *ray);
		if (t_min < ray->t && t_min > 0.1)
		{
			ray->t = t_min;
			ray->normal = normal_plan(objs.plans[i], *ray);
			ray->truc = 32 + i;
			*color = objs.plans[i].color;
		}
		++i;
	}
}

void		throw_ray(t_ray *ray, t_objs objs, uint32_t *color)
{
	ray->truc = 0;
	throw_ray_sphere(ray, objs, color);
	throw_ray_plan(ray, objs, color);
	throw_ray_cone(ray, objs, color);
	throw_ray_cylinder(ray, objs, color);
	if (ray->t >= T_MAX)
		ray->t = 0;
}
