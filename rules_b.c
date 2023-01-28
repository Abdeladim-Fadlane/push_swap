/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:37:24 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/26 15:34:40 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list **lst)
{
	int	k;

	if (!(lst))
		return ;
	k = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = k;
	write(1, "sb\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

	if (!stack_a)
		return ;
	ptr = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = ptr;
	write(1, "pb\n", 3);
}

void	ft_rb(t_list **list)
{
	t_list	*ptr;
	t_list	*ptr1;

	ptr1 = (*list);
	if (!(list))
		return ;
	if (ft_lstsize(*list) >= 2)
	{
		ptr = (*list)->next;
		while ((*list)->next != NULL)
			(*list) = (*list)->next;
		(*list)->next = ptr1;
		(*list)->next->next = NULL;
		(*list) = ptr;
		write(1, "rb\n", 3);
	}
}

void	ft_rrb(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr1;
	int		n;

	ptr1 = (*lst);
	ptr = (*lst);
	n = 1;
	if (!(lst))
		return ;
	if (ft_lstsize(*lst) >= 2)
	{
		while (n < ft_lstsize(*lst) - 1)
		{
			ptr = ptr->next;
			n++;
		}
		while ((*lst)->next != NULL)
			(*lst) = (*lst)->next;
		ptr->next = NULL;
		(*lst)->next = ptr1;
		write(1, "rrb\n", 4);
	}
}
