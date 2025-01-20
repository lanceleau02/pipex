# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 09:45:27 by laprieur          #+#    #+#              #
#    Updated: 2023/04/19 09:59:15 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_NAME	:=	pipex

#-------------------------------#
#          INGREDIENTS          #
#-------------------------------#

LIBFT			:=	libft/libft.a

MANDATORY		:=	mandatory/main.c		\
					mandatory/parsing.c		\
					mandatory/pipex.c		\
					mandatory/pipex_utils.c	\

MANDATORY_OBJS	:=	$(MANDATORY:%.c=.build/%.o)
DEPS			:=	$(MANDATORY_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -Ofast
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

$(MANDATORY_NAME): $(LIBFT) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LDFLAGS) -o $(MANDATORY_NAME)
	$(info CREATED $(MANDATORY_NAME))

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

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------#
#          SPEC          #
#------------------------#

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
