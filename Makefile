# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 14:58:32 by afadlane          #+#    #+#              #
#    Updated: 2023/01/13 11:42:54 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra  -fsanitize=address
SRC = 	push_swap.c  ft_split.c libft_utils.c libft_bonus.c  \
		check_push_swap.c rules.c rules_a.c rules_b.c main.c
cc = gcc
OBJ = ${SRC:.c=.o}

all :${NAME}
	
${NAME}: ${OBJ}
	 	${cc} ${CFLAGS} ${OBJ} -o ${NAME}
clean :
		rm -f ${OBJ}
fclean : clean
		rm -f ${NAME}
nor:
	norminette
re : fclean all

