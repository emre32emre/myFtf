NAME = fdf.a
SRCS = dert.c
OBJS := $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
MINILIBX_DIRECTORY = ./minilibx/
CC = gcc

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS)
	@make -C $(MINILIBX_DIRECTORY)
	@echo "minilibx derleniyor"
	@cp $(MINILIBX_DIRECTORY)/libmlx.a .
	@ar -rcs $(NAME) *.o
	@echo "kütüphane dosyaları oluştu ve ana dizine kopyalandı"

clean :
	@$(MAKE) -C $(MINILIBX_DIRECTORY) clean
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)
	@rm -rf libmlx.a

run :
	@gcc $(FLAGS) dert.c libmlx.a -framework OpenGL -framework AppKit -o exe.exe && ./exe.exe
	

