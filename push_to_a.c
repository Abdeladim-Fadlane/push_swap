/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:13:54 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/19 18:08:57 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
void	expand_range(t_object *object)
{
	object->start -= object->offset;
	object->end += object->offset;
	if (object->start < 0)
		object->start = 0;
	if (object->end > object->size)
		object->end = object->size;
}

int	get_size(t_list *stack)
{
	int		count;
	t_list	*ptr;

	count = 0;
	if (stack == NULL)
		return (0);
	ptr = stack;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}
int	check_index(t_list **stack_a, int *ar, int start, int end)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = *stack_a;
	while (ptr)
	{
		if (ptr->data >= ar[start] && ptr->data <= ar[end])
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	inisilisation(t_object *object, t_list **stack_a)
{
	object->size = get_size(*stack_a) - 1;
	if (get_size(*stack_a) <= 100)
		object->offset = get_size(*stack_a) / 8;
	else
		object->offset = get_size(*stack_a) / 18;
	object->mid = object->size / 2;
	object->start = object->mid - object->offset;
	object->end = object->mid + object->offset;
}


void	hundred_sort(t_list **stack_a, t_list **stack_b, int *ar)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	inisilisation(object, stack_a);
	while (*stack_a)
	{
		object->index = check_index(stack_a, ar, object->start, object->end);
		if (object->index < get_size(*stack_a))
		{
			if (object->index <= get_size(*stack_a) / 2)
			{
				while (!((*stack_a)->data >= ar[object->start] && (*stack_a)->data <= ar[object->end]))
					ft_ra(stack_a);
			}
			push_b(stack_a, stack_b);
			if ((*stack_b)->data < ar[object->mid])
				ft_rb(stack_b);
		}
		else
			expand_range(object);
	}
}