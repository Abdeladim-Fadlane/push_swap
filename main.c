/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:30 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/28 10:04:23 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_struct	*object;
	int			h;

	object = malloc(sizeof(t_struct));
	h = 0;
	object->container = get_arg(av, ac);
	if (!check_digit(object->container) || check_limits(av))
		ft_error();
	while (object->container[h])
	{
		add_back(&stack_a, ft_lstnew(ft_atoi(object->container[h])));
		h++;
	}
	object->num = stock_arr(object->container, ft_lstsize((stack_a)));
	sort_stack(&stack_a, &stack_b, object->num);
}

int	get_index2(t_list *stack_a, int data)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->data == data)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	check_max(t_list *stack, int len)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr)
	{
		if (len == ptr->data)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	check_duplicate(int *array, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[i] == array[j])
				ft_error();
			j++;
		}
		i++;
	}
}
