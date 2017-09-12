/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 22:14:10 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 12:12:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static inline void	ft_set_mlx_hooks(t_mlx_data *mlx_data, void **params)
{
	mlx_hook(mlx_data->win, KEYPRESS, KEYPRESSMASK, &ft_handler_keys
		, params);
	mlx_hook(mlx_data->win, KEYRELEASE, KEYRELEASEMASK, &ft_handler_keys_release
		, params);
	mlx_hook(mlx_data->win, BUTTONPRESS, BUTTONPRESSMASK, &ft_handler_buttons
		, params);
	mlx_hook(mlx_data->win, MOTIONNOTIFY, 0, &ft_handler_mouse_motion
		, params);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_data;

	(void)argc;
	(void)argv;

	if (!(mlx_data.connector = mlx_init()))
		ft_error_exit(1, (char*[]){MLX_INIT_ERROR}, EXIT_FAILURE);
	if (!(mlx_data.win = mlx_new_window(mlx_data.connector, WINDOW_WIDTH
										, WINDOW_HEIGHT, WINDOW_NAME)))
		ft_error_exit(1, (char*[]){MLX_NEW_WIN_ERROR}, EXIT_FAILURE);
	mlx_data.frame = ft_get_image_frames(mlx_data.connector, NBR_IMAGE_FRAME);
/* 	t_vec	vertices[3] = {{50, 50, 0, 1}, {50, 150, 0, 1}, {150, 150, 0, 1}}; */
/* 	t_vec	vertices_test[3] = {{50, 50, 0, 1}, {50, 150, 0, 1}, {150, 150, 0, 1}}; */
/* 	t_vec	translation = {50, 50, 0, 0}; */
/* 	t_vec	scaling = {20, 20, 20, 0}; */
/* /\* //	t_vec	scaling = {1, 1, 1, 0}; *\/ */
/* 	(void)translation; */
/* 	(void)scaling; */

/* 	vertices[0] = ft_translation(vertices[0], translation); */
/* 	vertices[1] = ft_translation(vertices[1], translation); */
/* 	vertices[2] = ft_translation(vertices[2], translation); */
/* 	vertices[0] = ft_scaling(vertices[0], scaling); */
/* 	vertices[1] = ft_scaling(vertices[1], scaling); */
/* 	vertices[2] = ft_scaling(vertices[2], scaling); */

/* 	vertices_test[0] = ft_translation(vertices_test[0], translation); */
/* 	vertices_test[1] = ft_translation(vertices_test[1], translation); */
/* 	vertices_test[2] = ft_translation(vertices_test[2], translation); */
/* 	vertices_test[0] = ft_translation(vertices_test[0], translation); */
/* 	vertices_test[1] = ft_translation(vertices_test[1], translation); */
/* 	vertices_test[2] = ft_translation(vertices_test[2], translation); */
/* 	vertices_test[0] = ft_translation(vertices_test[0], translation); */
/* 	vertices_test[1] = ft_translation(vertices_test[1], translation); */
/* 	vertices_test[2] = ft_translation(vertices_test[2], translation); */

/* 	vertices_test[0] = ft_scaling(vertices_test[0], scaling); */
/* 	vertices_test[1] = ft_scaling(vertices_test[1], scaling); */
/* 	vertices_test[2] = ft_scaling(vertices_test[2], scaling); */

/* 	vertices[0] = ft_perspective_transformation(vertices[0]); */
/* 	vertices[1] = ft_perspective_transformation(vertices[1]); */
/* 	vertices[2] = ft_perspective_transformation(vertices[2]); */

/* 	vertices_test[0] = ft_perspective_transformation(vertices_test[0]); */
/* 	vertices_test[1] = ft_perspective_transformation(vertices_test[1]); */
/* 	vertices_test[2] = ft_perspective_transformation(vertices_test[2]); */
	t_vec		vs[] = {{100, 100, 10, 1}, {100, 1000, 10, 1}, {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 200, 1}, {WINDOW_WIDTH - 100, 100, 10, 1}, {WINDOW_WIDTH - 100, 1000, 10, 1}, {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 200, 1}};
	t_vec		vs_t[6];
	t_polygone	polygones[2] = {{vs, vs_t, NULL, 3, 0xFF0000, {0}}, {vs + 3, vs_t + 3, NULL, 3, 0x0000FF, {0}}};
	t_obj		obj_test = (t_obj){vs, vs_t, polygones, NULL, 2, 6, 0};
	t_vec	translation = {500, 10, 1.0f, 0};
	t_vec	scaling = {10.0f, 10.0f, 10.0f, 0};
/* //	t_vec	scaling = {1, 1, 1, 0}; */
	(void)translation;
	(void)scaling;

/* 	ft_draw_polygone(&(t_polygone){vertices, NULL, NULL, 3, 0xF000F0}, &mlx_data); */
/* 	ft_draw_polygone(&(t_polygone){vertices_test, NULL, NULL, 3, 0xF000F0}, &mlx_data); */
/* 	ft_obj_translation(&obj_test, translation); */
/* 	ft_obj_scaling(&obj_test, scaling); */
//	sleep(3);
	(void)ft_set_mlx_hooks;
	ft_obj_scaling(&obj_test, scaling);
//	ft_obj_perspective_transformation(&obj_test);

	ft_draw_obj(&obj_test, &mlx_data);
	mlx_put_image_to_window(mlx_data.connector, mlx_data.win
							, mlx_data.frame->frame, 0, 0);
	printf("test\n");
	ft_set_mlx_hooks(&mlx_data, (void*[]){&mlx_data, &obj_test});
	mlx_loop(mlx_data.connector);


//	return (0);
}
