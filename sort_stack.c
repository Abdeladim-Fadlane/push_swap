/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:15 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/14 17:16:50 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_list	**lst)
{
	int b;
	int c;

	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if ((*lst)->data > b && b < c && (*lst)->data < c)
		ft_sa(lst);
	else if ((*lst)->data > b && b < c)
		ft_ra(lst);
	else if ((*lst)->data > b && b > c && (*lst)->data > c)
	{
		ft_ra(lst);
		ft_sa(lst);
	}
	else if ((*lst)->data < b && b > c && c > (*lst)->data)
	{ 
		ft_sa(lst);
		ft_ra(lst);
	}
	else if ((*lst)->data < b && b > c && (*lst)->data > c)
	{
		ft_ra(lst);
		ft_ra(lst);
	}
}

void	sort_stack(t_list **lst)
{
	if(ft_lstsize(*lst) == 2 && (*lst)->data > (*lst)->next->data)
		ft_sa(lst);
	else if(ft_lstsize(*lst) == 3)
		short_sort(lst);
	// else if(ft_lstsize(*lst) == 5)
	// {
	// }
	// return ; 
}

