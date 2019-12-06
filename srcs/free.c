/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:08:51 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/10 17:12:49 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "rtv1.h"
#include "libft.h"

void	free_split(char **tab1, char **tab2, char **tab3)
{
	ft_tabdel_char(&tab1);
	ft_tabdel_char(&tab2);
	ft_tabdel_char(&tab3);
}

void	free_sdl(t_sdl sdl)
{
	if (sdl.text)
		SDL_DestroyTexture(sdl.text);
	if (sdl.win)
		SDL_DestroyWindow(sdl.win);
	if (sdl.pixels)
		free(sdl.pixels);
	SDL_Quit();
}

void	end(int escape, t_sdl sdl, t_objs objs)
{
	free_sdl(sdl);
	if (objs.spheres)
		free(objs.spheres);
	if (objs.plans)
		free(objs.plans);
	if (objs.cones)
		free(objs.cones);
	if (objs.cylinders)
		free(objs.cylinders);
	if (objs.light)
		free(objs.light);
	exit(escape);
}
