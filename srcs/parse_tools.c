/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:44:17 by lojesu            #+#    #+#             */
/*   Updated: 2019/10/10 13:53:25 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>

void		error(uint8_t mod)
{
	if (mod == 1)
		ft_putendl("wrong numbers of arguments");
	else if (mod == 2)
		ft_putendl("an unexpected error occured");
	else if (mod == 3)
		ft_putendl("write corectly numbers for the coordinates of the figures");
	else if (mod == 4)
		ft_putendl("there is a problem with the syntax");
	else if (mod == 5)
		ft_putendl("your ambiant number is too big or too weak");
	else if (mod == 6)
		ft_putendl("your diffuse number is too big or too weak");
	else if (mod == 7)
		ft_putendl("your specular number is too big or too weak");
	else if (mod == 8)
		ft_putendl("too many figures, you can do only 32 by geometric shapes");
	else if (mod == 9)
		ft_putendl("there is a problem with the file");
	else if (mod == 10)
		ft_putendl("your light intensity is too big or too weak");
	exit(0);
}

int			convert_color(char *color)
{
	int		i;
	int		ret;
	int		val;

	i = ft_strlen(color) - 1;
	ret = 0;
	while (i >= 2)
	{
		val = color[i] - 48;
		if (val > 15)
			val = val - 39;
		ret = ret + val * pow(16, ft_strlen(color) - 1 - i);
		i--;
	}
	return (ret);
}

void		verif_color(char *color)
{
	size_t	i;

	i = 2;
	if (ft_strlen(color) != 8)
		error(3);
	if (color[0] != '0' || color[1] != 'x')
		error(3);
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && (color[i] < 'a' || color[i] > 'f'))
			error(3);
		i++;
	}
}
