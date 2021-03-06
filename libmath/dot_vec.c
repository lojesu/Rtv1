/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:58:39 by reda-con          #+#    #+#             */
/*   Updated: 2019/10/08 17:59:27 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double		dot_vec(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
