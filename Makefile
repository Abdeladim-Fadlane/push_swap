# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 14:58:32 by afadlane          #+#    #+#              #
#    Updated: 2023/01/21 13:59:04 by afadlane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
CFLAGS = -Wall -Werror -Wextra  #-fsanitize=address

SRC = 	push_swap.c  ft_split.c libft_utils.c libft_bonus.c  \
		check_push_swap.c rules.c rules_a.c rules_b.c main.c  \
		sort_stack.c push_to_a.c back_to_a.c

SRC2 = 	bonus/checker_push_swap.c bonus/checker_ft_split.c bonus/checker_libft_utils.c \
		bonus/checker_check_push_swap.c bonus/checker_rules.c bonus/checker_rules_a.c   \
	 	bonus/get_next_line.c bonus/checker_libft_bonus.c bonus/checker_rules_b.c   \
		bonus/checker_main.c          \
		
		
cc = gcc
#OBJ = ${SRC:.c=.o}
#OBJ2 = ${SRC2:.c=.o}

all :${NAME}

bonus : ${NAME2}

${NAME}: ${SRC} 
	 	${cc} ${CFLAGS} ${SRC} -o ${NAME}

${NAME2}: ${SRC2}
	 	${cc} ${CFLAGS} ${SRC2} -o ${NAME2}

clean :
		rm -f ${OBJ} ${OBJ2}

fclean : clean
		rm -f ${NAME} ${NAME2}

nor:
	norminette

re : fclean all 

