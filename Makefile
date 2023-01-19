# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 14:58:32 by afadlane          #+#    #+#              #
#    Updated: 2023/01/19 18:33:18 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra  #-fsanitize=address
SRC = 	push_swap.c  ft_split.c libft_utils.c libft_bonus.c  \
		check_push_swap.c rules.c rules_a.c rules_b.c main.c \
		sort_stack.c push_to_a.c back_to_a.c
cc = gcc
#OBJ = ${SRC:.c=.o}

all :${NAME}
	
${NAME}: ${SRC} 
	 	${cc} ${CFLAGS} ${SRC} -o ${NAME}
clean :
		rm -f ${OBJ}
fclean : clean
		rm -f ${NAME}
nor:
	norminette
re : fclean all 

