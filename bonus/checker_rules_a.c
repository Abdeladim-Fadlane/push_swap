/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:34:42 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/26 15:33:47 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_list **lst)
{
	int	k;

	if (!(*lst))
		return ;
	k = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = k;
}

void	ft_ra(t_list **list)
{
	t_list	*ptr;
	t_list	*ptr1;

	if (!(*list))
		return ;
	ptr1 = (*list);
	if (ft_lstsize(*list) >= 2)
	{
		ptr = (*list)->next;
		while ((*list)->next != NULL)
			(*list) = (*list)->next;
		(*list)->next = ptr1;
		(*list)->next->next = NULL;
		(*list) = ptr;
	}
}

void	ft_rra(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr1;
	int		n;

	if (!(*lst))
		return ;
	ptr1 = (*lst);
	ptr = (*lst);
	n = 1;
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
	}
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*ptr;

	if (!(*stack_b))
		return ;
	if (ft_lstsize(*stack_b) < 1)
		return ;
	ptr = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = ptr;
}
