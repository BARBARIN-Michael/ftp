# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/12/23 20:29:54 by mbarbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

DIR_LIB = ./Libs

INC  =   -I $(DIR_LIB)/libft/Include/
LIB  =   -L $(DIR_LIB)/libft/ -lft
INC +=   -I $(DIR_LIB)/libftprintf/Include/
LIB +=   -L $(DIR_LIB)/libftprintf/  -lftprintf
INC +=   -I $(DIR_LIB)/libftstream/Include/
LIB +=   -L $(DIR_LIB)/libftstream/  -lftstream

CFLAGS += -Wall -Wextra -Werror

SRCS = src/main.c \
	   src/ft_env.c

INC_FILES = include/ft_env.h									\

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c $(INC_FILES)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(DIR_LIB)/libftprintf/libftprintf.a:
	$(MAKE) -C $(DIR_LIB)/libftprintf

$(DIR_LIB)/libft/libft.a:
	$(MAKE) -C $(DIR_LIB)/libft

$(DIR_LIB)/libft/libftstream.a:
	$(MAKE) -C $(DIR_LIB)/libftstream

$(NAME): $(DIR_LIB)/libftprintf/libftprintf.a $(DIR_LIB)/libftstream/libftstream.a $(DIR_LIB)/libft.a $(OBJS)
	$(CC) -O3 -o $@ $(OBJS) $(LIB)


clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_PATH)/libft.a $(PRINTF_PATH)/libftprintf.a $(MLX_PATH)/libmlx.a
