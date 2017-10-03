NAME= wolf3d
SRC= srcs/main.c \
	srcs/ft_get_image_frames.c \
	srcs/ft_handler_esc.c \
	srcs/ft_handler_keys.c \
	srcs/ft_plot_pixel.c \
	srcs/ft_get_world_map.c \
	srcs/ft_raycasting.c \
	srcs/ft_handler_a.c \
	srcs/ft_handler_q.c \
	srcs/ft_handler_d.c \
	srcs/ft_handler_s.c \
	srcs/ft_handler_w.c \
	srcs/ft_handler_time.c \
	srcs/ft_apply_skybox.c \
	srcs/ft_get_textures.c \
	srcs/rain/ft_raindrops.c \
	srcs/rain/ft_get_rain_factor.c \
	srcs/rain/ft_get_rain_bool.c \
	srcs/ft_handler_pad_minus.c \
	srcs/ft_handler_pad_plus.c \
	srcs/ft_handler_r.c \
	srcs/ft_shade_color.c \
	srcs/ft_shade_image.c \
	srcs/fast_inverse_square_root.c \
	srcs/ft_get_current_block_type.c
#	srcs/ft_draw_polygone.c \
#	srcs/ft_multiply_vertex_matrix.c \
#	srcs/ft_multiply_scalar_vertex.c \
#	srcs/ft_translation.c \
#	srcs/ft_scaling.c \
#	srcs/ft_perspective_transformation.c \
#	srcs/ft_draw_obj.c \
#	srcs/ft_obj_translation.c \
#	srcs/ft_obj_scaling.c \
#	srcs/ft_obj_perspective_transformation.c \
# 	srcs/ft_handler_right.c \
# 	srcs/ft_handler_left.c \
# 	srcs/ft_handler_up.c \
# 	srcs/ft_handler_down.c \
# 	srcs/ft_handler_pad_up.c \
# 	srcs/ft_handler_pad_down.c \
# 	srcs/ft_handler_q.c \
# 	srcs/ft_handler_e.c \
# 	srcs/ft_handler_a.c \
# 	srcs/ft_handler_d.c \
# 	srcs/ft_handler_s.c \
# 	srcs/ft_handler_w.c \
# 	srcs/quaternions/ft_get_conjugate_quat.c \
# 	srcs/quaternions/ft_get_quat_magnitude.c \
# 	srcs/quaternions/ft_multiply_quat.c \
# 	srcs/quaternions/ft_normalize_quat.c \
# 	srcs/quaternions/ft_quat_rotate_points.c \

HDRS= includes/wolf3d.h
OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Ofast -Weverything -Wall -Werror -Wextra  #-g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt
MLX_PATH=./minilibx_macos/
LIBFT_PATH=./libft/
FLAGS= -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes -I$(MLX_PATH) -framework OpenGL -framework AppKit

all: submodule $(NAME)

submodule:
	@make -C minilibx_macos
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)
%.o : %.c $(HDRS)
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -I$(MLX_PATH) -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
