/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mouse_motion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:14:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 05:23:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_handler_mouse_motion(int x, int y, void *param)
{
	if (x)
	{
		(void)param;
		printf("moved to x: %d, y: %d\n", x, y);
		return (1);
	}
	return (0);
}
