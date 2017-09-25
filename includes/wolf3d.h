/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 21:54:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/25 09:47:14 by sclolus          ###   ########.fr       */
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
# include <stdbool.h>
# include <unistd.h> //

typedef void* t_mlx_win;
typedef void* t_mlx_img;
typedef void* t_mlx_ptr;

# define WINDOW_NAME "wolf3d"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define BASE_DISTANCE 0.002f

# define MOVE_COEFF 0.1f
# define ROTATION_COEFF (float)M_PI / WINDOW_WIDTH * 90

# define FOV 90.0f
# define ABS(x) (x < 0 ? -x: x)

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec;

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

typedef enum		e_block_type
{
	AIR = 0,
	NORMAL,
	SUPPORTED_BLOCK_TYPES,
}				t_block_type;

typedef struct	s_pos
{
	float	x;
	float	y;
}				t_pos;

typedef struct	s_block
{
/* 	t_pos			pos; */
/* 	float			height; */
/* 	float			width; */
/* 	float			depth; */
	t_block_type	type;
	int				blocking; // bool
/* 	void			*texture; */
}				t_block;

typedef struct	s_skybox
{
	void		*skybox;
	int			width;
	int			height;
}				t_skybox;

typedef struct	s_map
{
	uint64_t		width;
	uint64_t		height;
	t_block			*buffer;
	t_skybox		skybox;
}				t_map;

typedef struct	s_texture
{
	void		*texture;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_player
{
	t_pos	pos;
	float	angle;
}				t_player;

/*
** Image handling
*/

# define NBR_IMAGE_FRAME 8

t_image_frame	*ft_get_image_frames(t_mlx_ptr connector, uint32_t nbr_frames);

/*
** World
*/

# define TEXTURE_DIR "textures/"
# define SKYBOX_FILENAME TEXTURE_DIR "skybox.xpm"
# define BLOCK_FILENAME TEXTURE_DIR "block.xpm"

t_map		*ft_get_world_map(t_mlx_data *data);
t_texture	*ft_get_textures(t_mlx_data *data);

/*
** Rendering
*/

void		ft_plot_pixel(const uint32_t x, const uint32_t y, int *image, const int color);
void		ft_raycasting(t_mlx_data *data, t_player *player);
void		ft_apply_skybox(t_mlx_data *data, t_player *player, t_map *map);

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
# define ERROR_LOAD_SKYBOX "failed to load skybox file"
# define ERROR_LOAD_BLOCK "failed to load block texture file"

#endif
