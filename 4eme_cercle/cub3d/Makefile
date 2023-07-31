NAME		=	cub3d
CC			=	gcc
################### CC			=	gcc -g3 -fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lm -lbsd
OBJDIR 		= 	obj

SRC			=	src/main.c \
				\
				src/game_logic/frames.c \
				src/game_logic/game_loop.c \
				src/game_logic/inputs_keyboard.c \
				src/game_logic/inputs_mouse.c \
				src/game_logic/player_actions.c \
				src/game_logic/player_movement.c \
				\
				src/render/render_minimap.c \
				src/render/render_floor_ceiling_untextured.c \
				src/render/render_floor_ceiling.c \
				src/render/render_sprites_subs.c \
				src/render/render_sprites.c \
				src/render/render_walls.c \
				src/render/render_walls_subs.c \
				src/render/render_vgiraudo.c \
				src/render/render_hud_debug.c \
				src/render/render_hud.c \
				src/render/render_gun.c \
				src/render/render_viseur.c \
				\
				src/map_parsing/map_open.c \
				src/map_parsing/map_handle_infos.c \
				src/map_parsing/map_handle_desc.c \
				src/map_parsing/map_open_utils_set_strsss.c \
				src/map_parsing/map_parsing_check.c \
				src/map_parsing/map_utils_set_color_ceil_and_floor.c \
				\
				src/init_textures.c \
				src/init_player.c \
				src/init_config.c \
				src/init_enemies.c \
				\
				src/utils.c \
				src/mlx_utils_str.c \
				src/mlx_utils.c \
				src/ft_str_rgb_to_int.c \
				src/free_exit_utils.c \
				src/free_exit.c \
				\
				src/new/free_exit_suite.c \


# OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

$(OBJDIR)/%.o: %.c | $(OBJDIR)
		@ $(CC) $(CFLAGS) -c $<    -o $@



all:		$(MLX) $(LFT) $(NAME)
			@echo [make all]...

$(NAME):	$(OBJ)
			@echo [make $(NAME)]...
			@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo [make mlx]...
			@make -s -C mlx

$(LFT):
			@echo [make lft]...
			@make -s -C libft



$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/src
	mkdir -p $(OBJDIR)/src/game_logic
	mkdir -p $(OBJDIR)/src/render
	mkdir -p $(OBJDIR)/src/map_parsing
	mkdir -p $(OBJDIR)/src/todo
	mkdir -p $(OBJDIR)/src/new

bonus : 	all
			@echo [make bonus]...
clean:
			@echo [make clean]...
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj

fclean:		clean
			@echo [make fclean]...
			@make -s $@ -C libft
			@rm -rf $(NAME)

re:			fclean all
			@echo [make re]...

.PHONY:		all bonus clean fclean re
