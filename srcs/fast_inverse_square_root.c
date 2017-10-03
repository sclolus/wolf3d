/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_inverse_square_root.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:25:17 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 14:26:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** I did not create this algorithm: I'm not a being made of pure madness
*/

inline float	fast_inverse_square_root(const float nbr)
{
	long		i;
	float		x2;
	float		y;
	const float	threehalfs = 1.5F;

	x2 = nbr * 0.5F;
	y = nbr;
	i = *(long *)(void*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}
