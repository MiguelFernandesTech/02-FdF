# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 08:48:29 by migmarti          #+#    #+#              #
#    Updated: 2023/03/04 12:18:58 by migmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
EXECUTABLE = fdf
CC = cc
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRCS = ./fdf.c ./draw.c ./read_file.c ./utils.c
MINI = ./minilibx-linux/libmlx.a -L -lmlx -lXext -lX11 -lm
AR = ar rcs

OBJ = $(SRCS:.c=.o)

all: $(NAME)
	$(CC) $(NAME) $(LIBFT) $(MINI) -o $(EXECUTABLE)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean: oclean
	$(RM) $(EXECUTALBE)

oclean: $(OBJ)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

run: all oclean
	./$(EXECUTABLE) "42.fdf"

