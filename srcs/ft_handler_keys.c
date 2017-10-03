/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:05:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 10:40:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_keycode_f	*ft_get_keycodes_f(void)
{
	static t_keycode_f	keycodes_f[] = {
		{ft_handler_esc, KEY_ESCAPE, 0},
		{ft_handler_q, KEY_Q, 0},
		{ft_handler_a, KEY_A, 0},
		{ft_handler_s, KEY_S, 0},
		{ft_handler_d, KEY_D, 0},
		{ft_handler_w, KEY_W, 0},
		{ft_handler_r, KEY_R, 0},
		{ft_handler_pad_plus, KEY_PAD_ADD, 0},
		{ft_handler_pad_minus, KEY_PAD_SUB, 0}};

	if (sizeof(keycodes_f) / sizeof(t_keycode_f) != NBR_KEY_HOOKS)
		ft_error_exit(1, (char*[]){INVALID_KEYS_HOOKS_NBR}, EXIT_FAILURE);
	return (keycodes_f);
}

int					ft_handler_keys_release(int keycode
									, void __attribute__((unused)) *param)
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_keycodes_f();
	while (i < NBR_KEY_HOOKS)
	{
		if (keycodes_f[i].keycode == keycode)
		{
			keycodes_f[i].used = 0;
			break ;
		}
		i++;
	}
	return (0);
}

int					ft_handler_keys(int keycode, void *param)
{
	static t_keycode_f	*keycodes_f = NULL;
	uint32_t			i;

	i = 0;
	if (!keycodes_f)
		keycodes_f = ft_get_keycodes_f();
	while (i < NBR_KEY_HOOKS)
	{
		if (keycodes_f[i].keycode == keycode)
		{
			keycodes_f[i].used = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < NBR_KEY_HOOKS)
	{
		if (keycodes_f[i].used)
			keycodes_f[i].f(param);
		i++;
	}
	return (0);
}
