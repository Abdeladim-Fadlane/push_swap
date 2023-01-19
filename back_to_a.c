/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:24:07 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/19 16:33:41 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_list	*get_last_elem(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	get_index(t_list *stack_a, int data)
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


void	back_to_a(t_list **stack_b, t_list **stack_a, int *arr)
{
	t_object2	*object;

	object = malloc(sizeof(t_object2));
	object->count = 0;
	object->len = get_size(*stack_b) - 1;

	while (*stack_b || object->len >= 0)
	{
		object->size = get_size(*stack_b);
		if (check_max(*stack_b, arr[object->len]))
		{
			if ((*stack_b)->data == arr[object->len])
			{
				push_a(stack_b, stack_a);
				object->len--;
			}
			else if (object->count == 0 || (*stack_b)->data > get_last_elem(*stack_a)->data)
			{
				push_a(stack_b, stack_a);
				ft_ra(stack_a);
				object->count++;
			}
			else
			{
				if (get_index(*stack_b, arr[object->len]) <= object->size / 2)
					while ((*stack_b)->data != arr[object->len])
						ft_rb(stack_b);
				else
					while ((*stack_b)->data != arr[object->len])
						ft_rrb(stack_b);
			}
		}
		else
		{
			ft_rra(stack_a);
			object->count--;
			object->len--;
		}
	}
	free(object);
}