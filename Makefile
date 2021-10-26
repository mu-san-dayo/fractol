NAME = fractol
UNAME = $(shell uname)

SRCS_DIR = srcs
SRCS += $(SRCS_DIR)/comp.c
SRCS += $(SRCS_DIR)/error.c
SRCS += $(SRCS_DIR)/key.c
SRCS += $(SRCS_DIR)/window.c
SRCS += $(SRCS_DIR)/draw.c
SRCS += $(SRCS_DIR)/main.c
SRCS += $(SRCS_DIR)/mandelbrot.c
SRCS += $(SRCS_DIR)/julia.c
SRCS += $(SRCS_DIR)/burningship.c
ifeq ($(UNAME), Linux)
SRCS += $(SRCS_DIR)/update_c_linux.c
else
SRCS += $(SRCS_DIR)/update_c_mac.c
endif

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)
INCLUDE = -I./includes -I./$(LIBFT_DIR)
CC = gcc -Wall -Wextra -Werror
RM = rm -f


ifeq ($(UNAME), Linux)
# ------------------- Linux -------------------
LIBS = -lXext -lX11 -L $(LIBFT_DIR) -lft libmlx_Linux.a
else
# ------------------- MacOS -------------------
LIBS = libmlx.dylib -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft
endif


ifeq ($(UNAME), Linux)
# ------------------- Linux -------------------
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(INCLUDE) $(OBJS) -L. -L.minilibx-linux -lmlx_Linux $(LIBS) -lm -o $(NAME)

bonus: $(NAME)
else
# ------------------- MacOS -------------------
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(INCLUDE) $(OBJS) $(LIBS) -lm -o $(NAME)

bonus: $(NAME)
endif

$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR)
.c.o:
	$(CC) $(INCLUDE) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR)	clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR)	fclean
	$(RM) $(NAME)
re: fclean all


.PHONY: all clean fclean re .c.o
