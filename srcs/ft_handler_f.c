/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:59:51 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 16:04:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool	*ft_get_fps_bool(void)
{
	static bool	fps_bool = 0;

	return (&fps_bool);
}

void	ft_handler_f(void *param)
{
	(void)param;
	*ft_get_fps_bool() ^= 1;
}

