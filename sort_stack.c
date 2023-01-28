/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:15 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/26 15:34:46 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_min(t_list *lst)
{
	int	x;
	int	index;
	int	i;

	x = lst->data;
	index = 0;
	i = 1;
	while (lst)
	{
		if (x > lst->data)
		{
			x = lst->data;
			index = i;
		}
		i++;
		lst = lst->next;
	}
	return (index);
}

int	get_min(t_list *lst)
{
	int	x;

	x = lst->data;
	while (lst)
	{
		if (x > lst->data)
			x = lst->data;
		lst = lst->next;
	}
	return (x);
}

void	top_elememt(t_list **lst)
{
	int	x;
	int	y;

	x = get_min(*lst);
	y = get_index_min(*lst);
	if (y < ft_lstsize(*lst) / 2)
	{
		while (x != (*lst)->data)
			ft_ra(lst);
	}
	else if (y >= ft_lstsize(*lst) / 2)
	{
		while ((*lst)->data != x)
			ft_rra(lst);
	}
}

void	five_sort(t_list **lst, t_list **lst2)
{
	while (ft_lstsize(*lst) > 3)
	{
		top_elememt(lst);
		push_b(lst, lst2);
	}
	short_sort(lst);
	while (*lst2)
		push_a(lst2, lst);
}

void	sort_stack(t_list **lst, t_list **lst2, int *num)
{
	if (ft_lstsize(*lst) == 2 && (*lst)->data > (*lst)->next->data)
		ft_sa(lst);
	else if (ft_lstsize(*lst) == 3)
		short_sort(lst);
	else if (ft_lstsize(*lst) >= 4 && ft_lstsize(*lst) <= 16)
		five_sort(lst, lst2);
	else if (ft_lstsize(*lst) > 16)
	{
		hundred_sort(lst, lst2, num);
		back_to_a(lst2, lst, num);
	}
}
