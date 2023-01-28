/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:24:07 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/26 15:34:02 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last_node(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	rotate_stack_b(t_list **stack_b, t_object2 *object, int *arr)
{
	if (get_index2(*stack_b, arr[object->len]) <= object->size / 2)
		while ((*stack_b)->data != arr[object->len])
			ft_rb(stack_b);
	else
		while ((*stack_b)->data != arr[object->len])
			ft_rrb(stack_b);
}

void	resize(t_list **stack_a, t_object2 *object)
{
	ft_rra(stack_a);
	object->count--;
	object->len--;
}

void	push_and_retate(t_list **stack_a, t_list **stack_b, t_object2 *object)
{
	push_a(stack_b, stack_a);
	ft_ra(stack_a);
	object->count++;
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
			else if (object->count == 0
				|| (*stack_b)->data > get_last_node(*stack_a)->data)
				push_and_retate(stack_a, stack_b, object);
			else
				rotate_stack_b(stack_b, object, arr);
		}
		else
			resize(stack_a, object);
	}
}
