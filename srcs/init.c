/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:30:58 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/10 14:40:28 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libmath.h"

t_pt		init_pt(double x, double y, double z)
{
	t_pt	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec		init_vec(double x, double y, double z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_ray		init_ray(t_pt origin, t_vec dir, double t)
{
	t_ray	ret;

	ret.origin = origin;
	ret.dir = dir;
	ret.t = t;
	return (ret);
}

int			init_sdl(t_sdl *ret)
{
	if (!(ret->pixels = malloc(4 * ((WIDTH + 1) * HEIGHT))))
		return (1);
	if (SDL_Init(SDL_INIT_VIDEO))
		return (1);
	if (!(ret->win = SDL_CreateWindow("Rt V1", 600, 400, WIDTH, HEIGHT, 0)))
		return (1);
	if (!(ret->ren = SDL_CreateRenderer(ret->win, -1, 8 | 4)))
		return (1);
	if (!(ret->text = SDL_CreateTexture(ret->ren, RGB, 1, WIDTH, HEIGHT)))
		return (1);
	return (0);
}

t_cam		init_cam(t_pt pos, t_vec dir)
{
	t_cam	ret;
	t_vec	up;
	t_vec	tmp_x;
	t_vec	tmp_y;
	t_vec	tmp_z;

	up = init_vec(0, 1, 0);
	ret.pos = pos;
	ret.vecdir = dir;
	ret.rvec = unit_vec(cross_product(up, dir));
	ret.uvec = unit_vec(cross_product(dir, ret.rvec));
	ret.vp_height = HEIGHT / 10240.0;
	ret.vp_width = WIDTH / 10240.0;
	ret.vp_dist = 0.1;
	ret.indentx = ret.vp_width / WIDTH;
	ret.indenty = ret.vp_height / HEIGHT;
	tmp_x = mul_vec(ret.rvec, ret.vp_width / 2.0);
	tmp_y = mul_vec(ret.uvec, ret.vp_height / 2.0);
	tmp_z = mul_vec(ret.vecdir, ret.vp_dist);
	ret.vpupleft = move_pt(ret.pos, sub_vec(add_vec(tmp_z, tmp_y), tmp_x));
	return (ret);
}
