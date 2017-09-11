/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:45:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/11 05:22:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_keycode_f	*ft_get_buttoncodes_f(void)
{
	static t_keycode_f	keycodes_f[] = {
		{NULL, 0, 0}
/* 		{ft_handler_button5, BUTTON5, 0}, */
/* 		{ft_handler_button5, 6, 0}, */
/* 		{ft_handler_button4, BUTTON4, 0} */};

	if (sizeof(keycodes_f) / sizeof(t_keycode_f) != NBR_BUTTON_HOOKS)
		ft_error_exit(1, (char*[]){INVALID_BUTTONS_HOOKS_NBR}, EXIT_FAILURE);
	return (keycodes_f);
}

int					ft_handler_buttons(int keycode, int x, int y, void *param)
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_buttoncodes_f();
	while (i < NBR_BUTTON_HOOKS)
	{
		if (keycodes_f[i].keycode == keycode)
		{
			keycodes_f[i].f(x, y, param);
			break ;
		}
		i++;
		if (i == NBR_BUTTON_HOOKS)
			break ;
	}
	return (0);
}
