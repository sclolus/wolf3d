/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 21:54:49 by sclolus           #+#    #+#             */
/*   Updated: 2017/10/03 11:02:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "events.h"
# include "key_codes_macos.h"
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <unistd.h>

typedef void* t_mlx_win;
typedef void* t_mlx_img;
typedef void* t_mlx_ptr;

# define WINDOW_NAME "wolf3d"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define BASE_DISTANCE 0.001f

# define MOVE_COEFF 0.1f
# define ROTATION_COEFF (float)M_PI / WINDOW_WIDTH * 90 / 2

# define FOV 90.0f
# define ABS(x) (x < 0 ? -x : x)
# define SMALLER(x, y) (x > y ? y : x)
# define ROUND(x) (x >= 0.0f ? (int64_t)(x + 0.5f) : (int64_t)(x - 0.5f))
# define FLOORING_DU_TURFU(_x) ((float)ROUND(_x))

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

typedef enum	e_block_type
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
	t_block_type	type;
	int				blocking;
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
** Color handling
*/

typedef struct	s_rgb
{
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
	uint8_t	a;
}				t_rgb;

typedef union	u_color
{
	t_rgb	component;
	int		color;
}				t_color;

int				ft_shade_color(int color, float shading);
void			ft_shade_image(int *image, uint32_t width
						, uint32_t height, float shading);

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

t_map			*ft_get_world_map(t_mlx_data *data);
t_texture		*ft_get_textures(t_mlx_data *data);

/*
** Rendering
*/

void			ft_plot_pixel(const uint32_t x, const uint32_t y
						, int *image, const int color);
void			ft_raycasting(t_mlx_data *data, t_player *player);
void			ft_apply_skybox(t_mlx_data *data, t_player *player, t_map *map);

/*
** Rain
*/

# define BASE_RAIN_LIMIT 100
# define BASE_RAIN_UPPER_LIMIT 12000
# define BASE_RAIN_FACTOR 5000
# define BASE_RAIN_MODIFIER_FACTOR 100
# define SKYBOX_SHADING_FACTOR (0.999f)

void			ft_raindrops(t_mlx_data *data);

uint64_t		*ft_get_rain_factor(void);
bool			*ft_get_rain_bool(void);
void			ft_handler_r(void *param);
void			ft_handler_pad_minus(void *param);
void			ft_handler_pad_plus(void *param);

int				ft_handler_time(void *param);

/*
** Key handling
*/

# define NBR_KEY_HOOKS 9
# define FUCK_NORME " number provided in macro expansion"
# define INVALID_KEYS_HOOKS_NBR "Invalid keys_hooks" FUCK_NORME

# define NORETURN __attribute__((noreturn)) void

int				ft_handler_keys(int keycode, void *param);
int				ft_handler_keys_release(int keycode
					, void * __attribute__((unused))param);
NORETURN		ft_handler_esc(void * __attribute__((unused))param);
void			ft_handler_w(void *param);
void			ft_handler_a(void *param);
void			ft_handler_s(void *param);
void			ft_handler_d(void *param);
void			ft_handler_q(void *param);

/*
** Button handling
*/

# define NBR_BUTTON_HOOKS 0
# define INVALID_BUTTONS_HOOKS_NBR "Invalid buttons_hooks" FUCK_NORME

int				ft_handler_buttons(int keycode, int x, int y
													, void *param);
/*
** Mouse motion handling
*/

int				ft_handler_mouse_motion(int x, int y, void *param);

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
