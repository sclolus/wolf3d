/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 21:54:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/12 12:16:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "events.h"
# include "key_codes_macos.h"
# include "mlx.h"
# include <stdio.h> //
# include <math.h>
# include <unistd.h> //

typedef void* t_mlx_win;
typedef void* t_mlx_img;
typedef void* t_mlx_ptr;

# define WINDOW_NAME "fdf"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define MOVE_COEFF 10.0f

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec;

typedef struct	s_transformation_matrix
{
	float	coeffs[4][4];
}				t_matrix4;

typedef struct	s_keycode_f
{
	void	(*f)();
	int		keycode;
	int32_t	used;
}				t_keycode_f;

typedef enum	e_frame_state
{
	ERR = 0,
	USED = 1,
	TO_CLEAR = 2,
	AVAILABLE = 3,
	CLEARING = 4,
}				t_frame_state;

typedef struct	s_image_frame
{
	t_mlx_img		frame;
	void			*buffer;
	t_frame_state	state;
	int32_t			bits_per_pixel;
	int32_t			size_line;
	int32_t			endian;
}				t_image_frame;

typedef struct	s_mlx_data
{
	t_mlx_ptr			connector;
	t_mlx_win			win;
	t_image_frame		*frame;
}				t_mlx_data;

typedef struct	s_quat
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_quat;

typedef struct	s_float2
{
	float	x;
	float	y;
}				t_float2;

typedef struct	s_polygone
{
	t_vec		*vertices;
	t_vec		*result_vertices;
	t_vec		*texture_vertices;
	uint64_t	nbr_vec;
	int			color;
	char		pad[4];
}				t_polygone;

typedef struct	s_obj
{
	t_vec		*vertices;
	t_vec		*result_vertices;
	t_polygone	*polygones;
	void		*texture_buffer;
	uint64_t	nbr_poly; //
	uint64_t	nbr_vs; //
	uint64_t	flags;
}				t_obj;

/*
** Image handling
*/

# define NBR_IMAGE_FRAME 8

t_image_frame	*ft_get_image_frames(t_mlx_ptr connector, uint32_t nbr_frames);

/*
** Rasterizing
*/

void		ft_plot_pixel(const uint32_t x, const uint32_t y, int *image, const int color);
void		ft_draw_obj(t_obj *obj, t_mlx_data *mlx_data);
void		ft_draw_polygone(t_polygone *polygone, t_mlx_data *mlx_data);
float		ft_cross_product(const t_float2 a, const t_float2 b);
void		ft_get_min_max_coords(t_polygone *polygone, uint32_t *max_coords
								, uint32_t *min_coords);
float		ft_min_float(const float a, const float b);
float		ft_max_float(const float a, const float b);

/*
** Rasterizing
*/

# define N_DISTANCE -1.0f
# define F_DISTANCE 1.0f

t_vec		ft_translation(t_vec vertex, const t_vec translation);
t_vec		ft_scaling(t_vec vertex, const t_vec scaling);
t_vec		ft_perspective_transformation(t_vec vertex);

void		ft_obj_translation(t_obj *obj, t_vec translation);
void		ft_obj_scaling(t_obj *obj, t_vec scaling);
void		ft_obj_perspective_transformation(t_obj *obj);

/*
** Matrices
*/

t_vec		ft_multiply_vertex_matrix(t_vec vertex, t_matrix4 matrix);
t_vec		ft_multiply_scalar_vertex(t_vec vertex, float scalar);


/*
** Key handling
*/

# define NBR_KEY_HOOKS 5
# define FUCK_NORME " number provided in macro expansion"
# define INVALID_KEYS_HOOKS_NBR "Invalid keys_hooks" FUCK_NORME

# define NORETURN __attribute__((noreturn)) void

int							ft_handler_keys(int keycode, void *param);
int							ft_handler_keys_release(int keycode
										, void * __attribute__((unused))param);
NORETURN					ft_handler_esc(void * __attribute__((unused))param);
void						ft_handler_w(void *param);
void						ft_handler_a(void *param);
void						ft_handler_s(void *param);
void						ft_handler_d(void *param);
/* void						ft_handler_right(void *param); */
/* void						ft_handler_left(void *param); */
/* void						ft_handler_down(void *param); */
/* void						ft_handler_up(void *param); */
/* void						ft_handler_page_up(void *param); */
/* void						ft_handler_page_down(void *param); */
/* void						ft_handler_pad_down(void *param); */
/* void						ft_handler_pad_up(void *param); */
/* void						ft_handler_r(void *param); */
/* void						ft_handler_m(void *param); */
/* void						ft_handler_q(void *param); */
/* void						ft_handler_e(void *param); */
/* void						ft_handler_w(void *param); */
/* void						ft_handler_s(void *param); */
/* void						ft_handler_d(void *param); */
/* void						ft_handler_a(void *param); */
/* void						ft_handler_t(void *param); */
/* void						ft_handler_p(void *param); */
/* void						ft_handler_2(void *param); */
/* void						ft_handler_1(void *param); */
/* void						ft_handler_5(void *param); */
/* void						ft_handler_6(void *param); */
/* void						ft_handler_7(void *param); */
/* void						ft_handler_4(void *param); */
/* void						ft_handler_3(void *param); */

/*
** Button handling
*/

# define NBR_BUTTON_HOOKS 0
# define INVALID_BUTTONS_HOOKS_NBR "Invalid buttons_hooks" FUCK_NORME

int							ft_handler_buttons(int keycode, int x, int y
													, void *param);
/*
** Mouse motion handling
*/

int							ft_handler_mouse_motion(int x, int y, void *param);

/*
** Error handling
*/

# define INVALID_MEM_CAPACITY "Invalid capacity given to ft_create_mem_block()"
# define MLX_INIT_ERROR "mlx_init() failed"
# define MLX_NEW_WIN_ERROR "mlx_new_window() failed"
# define MLX_NEW_IMG_ERROR "mlx_new_image() failed"
# define MLX_IMG_FRAMES_ERROR "malloc() failed to alloc image frames"
# define OPEN_FILE_FAILED ": open() failed"

#endif
