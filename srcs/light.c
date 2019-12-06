/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:46:44 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/09 21:12:10 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	light_diffuse(t_pt inter, t_objs objs, t_ray ray, t_light light)
{
	t_vec		lightvector;
	t_vec		vec_normal;
	uint32_t	color;
	double		angle;

	color = 0;
	lightvector = unit_vec(vec(light.pos, inter));
	vec_normal = unit_vec(ray.normal);
	angle = dot_vec(lightvector, vec_normal);
	if (angle >= 0)
		return (0);
	return (objs.color.diffuse * fabs(angle) * light.intensity / 100.0);
}

static double	light_specular(t_pt inter, t_objs objs, t_ray ray,
								t_light light)
{
	t_vec	cam_dir;
	t_vec	reflection;
	t_vec	lightvector;
	double	angle;

	lightvector = unit_vec(vec(light.pos, inter));
	if (dot_vec(lightvector, ray.normal) == 0)
		return (0);
	cam_dir = mul_vec(lightvector, -1);
	reflection = unit_vec(sub_vec(lightvector,
				mul_vec(ray.normal, 2 * dot_vec(lightvector, ray.normal))));
	angle = dot_vec(cam_dir, reflection);
	return (objs.color.specular *
			color_mul(255, pow(fmax(angle, 0), 100)) * light.intensity / 100);
}

static uint8_t	in_shadow(t_ray ray, t_pt inter, t_objs objs)
{
	t_ray		s_ray;
	t_pt		pt;
	uint8_t		shadow;
	uint32_t	c;
	size_t		i;

	i = 0;
	shadow = 0;
	while (i < objs.nb_lights)
	{
		s_ray = init_ray(inter, unit_vec(vec(inter, objs.light[i].pos)), T_MAX);
		throw_ray(&s_ray, objs, &c);
		if (s_ray.t > 0.1)
			pt = move_pt(inter, mul_vec(s_ray.dir, s_ray.t));
		if (size_vec(vec(inter, pt)) < size_vec(vec(inter, objs.light[i].pos))
				&& s_ray.truc != ray.truc && s_ray.t > 0.1)
			shadow++;
		i++;
	}
	return (shadow);
}

uint32_t		ft_color(t_pt inter, t_objs objs, t_ray ray, uint32_t color)
{
	double		tmp;
	size_t		i;
	size_t		shadow;
	t_pt		tmp_spec_diff;

	i = 0;
	tmp_spec_diff = init_pt(0, 0, 0);
	tmp = objs.color.ambiant;
	if ((shadow = in_shadow(ray, inter, objs)) > 0)
		return (color_mul(color, tmp / shadow));
	while (i < objs.nb_lights)
	{
		tmp_spec_diff.x += light_specular(inter, objs, ray, objs.light[i]);
		tmp_spec_diff.y += light_diffuse(inter, objs, ray, objs.light[i]);
		i++;
	}
	color = color_add(color, tmp_spec_diff.x);
	color = color_mul(color, tmp + tmp_spec_diff.y);
	return (color);
}
