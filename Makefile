# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 09:45:27 by laprieur          #+#    #+#              #
#    Updated: 2023/03/15 15:25:52 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_NAME	:=	pipex
BONUS_NAME		:=	pipex_bonus

#-------------------------------#
#          INGREDIENTS          #
#-------------------------------#

LIBFT			:=	libft/libft.a

MANDATORY		:=	mandatory/main.c		\
					mandatory/parsing.c		\
					mandatory/pipex.c		\
					mandatory/pipex_utils.c	\

BONUS			:=	bonus/main.c			\

MANDATORY_OBJS	:=	$(MANDATORY:%.c=.build/%.o)
BONUS_OBJS		:=	$(BONUS:%.c=.build/%.o)
DEPS			:=	$(MANDATORY_OBJS:%.o=%.d) $(BONUS_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -g -Ofast
CPPFLAGS		:=	-MP -MMD -Iinclude -Ilibft/include
LDFLAGS			:=	-Llibft -lft

#----------------------------#
#          UTENSILS          #
#----------------------------#

MAKEFLAGS		+= --silent --no-print-directory

#---------------------------#
#          RECIPES          #
#---------------------------#

all: $(MANDATORY_NAME)

bonus: $(BONUS_NAME)

$(MANDATORY_NAME): $(LIBFT) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LDFLAGS) -o $(MANDATORY_NAME)
	$(info CREATED $(MANDATORY_NAME))

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)
	$(info CREATED $(BONUS_NAME))

$(LIBFT):
	$(MAKE) -C libft

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(MAKE) -C libft clean
	rm -rf .build

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(MANDATORY_NAME)
	rm -rf $(BONUS_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------#
#          SPEC          #
#------------------------#

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
