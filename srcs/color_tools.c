/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:58:51 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/09 21:12:23 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	color_add(uint32_t color, uint32_t add)
{
	int		r;
	int		g;
	int		b;

	r = (color >> 16 & 0xFF);
	g = (color >> 8 & 0xFF);
	b = (color & 0xFF);
	r += add;
	g += add;
	b += add;
	r > 255 ? r = 255 : r;
	g > 255 ? g = 255 : g;
	b > 255 ? b = 255 : b;
	r < 0 ? r = 0 : r;
	g < 0 ? g = 0 : g;
	b < 0 ? b = 0 : b;
	return ((r << 16) | (g << 8) | b);
}

uint32_t	color_mul(uint32_t color, double add)
{
	int		r;
	int		g;
	int		b;

	r = (color >> 16 & 0xFF);
	g = (color >> 8 & 0xFF);
	b = (color & 0xFF);
	r *= add;
	g *= add;
	b *= add;
	r > 255 ? r = 255 : r;
	g > 255 ? g = 255 : g;
	b > 255 ? b = 255 : b;
	r < 0 ? r = 0 : r;
	g < 0 ? g = 0 : g;
	b < 0 ? b = 0 : b;
	return ((r << 16) | (g << 8) | b);
}
