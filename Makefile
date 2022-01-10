# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gborne <gborne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 18:17:20 by gborne            #+#    #+#              #
#    Updated: 2022/01/09 18:22:19 by gborne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=	ft_printf.c ft_utils.c

OBJ				=	${SRC:.c=.o}

NAME			=	libftprintf.a

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror

.c.o			:
				@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}			:	${OBJ}
				@ar rc libftprintf.a ${OBJ}
				@ranlib libftprintf.a

mandatory		:	${OBJ} libft
				@ar rc libftprintf.a ${OBJ}
				@ranlib libftprintf.a

clean			:
				@rm -f ${OBJ}

all				:	${NAME} clean

fclean			:	clean
				@rm -f libftprintf.a
				@rm -f libftprintf.h.gch

re				: 	fclean all
				@rm -f ${OBJ}

.PHONY			: 	mandatory clean all fclean re
