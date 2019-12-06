/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:42:31 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/10 17:12:17 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void		raytracing(t_objs objs, t_cam cam, t_sdl sdl)
{
	t_pt		pix;
	t_pt		indent;
	t_pt		inter;
	t_ray		ray;
	uint32_t	color;

	pix = init_pt(0, 0, 42);
	while (pix.y <= HEIGHT)
	{
		pix.x = 0;
		while (pix.x <= WIDTH)
		{
			indent = move_pt(cam.vpupleft,
				sub_vec(mul_vec(cam.rvec, cam.indentx * pix.x),
				mul_vec(cam.uvec, cam.indenty * pix.y)));
			ray = init_ray(cam.pos, unit_vec(vec(cam.pos, indent)), T_MAX);
			throw_ray(&ray, objs, &color);
			inter = move_pt(cam.pos, mul_vec(ray.dir, ray.t));
			if (ray.t > 0)
				color = ft_color(inter, objs, ray, color);
			sdl.pixels[(int)(pix.x + (pix.y * WIDTH))] = color;
			pix.x++;
		}
		pix.y++;
	}
}

int			main(int argc, char **argv)
{
	t_sdl		sdl;
	t_objs		objs;
	t_cam		cam;
	int			loop;

	loop = 0;
	ft_putendl("***Loading***");
	parsing(argc, argv, &cam, &objs);
	if ((init_sdl(&sdl)))
		free_sdl(sdl);
	raytracing(objs, cam, sdl);
	ft_putendl("***Loaded!***");
	SDL_UpdateTexture(sdl.text, 0, sdl.pixels, WIDTH * 4);
	SDL_RenderCopy(sdl.ren, sdl.text, 0, 0);
	SDL_RenderPresent(sdl.ren);
	while (!loop)
	{
		SDL_PollEvent(&sdl.ev);
		if (sdl.ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE
			|| sdl.ev.window.event == SDL_WINDOWEVENT_CLOSE)
			++loop;
	}
	end(0, sdl, objs);
	return (0);
}
