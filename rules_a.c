/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:34:42 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/13 11:36:09 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    ft_sa(t_list **lst)
{
    int k;
   
    k = (*lst)->data;
    (*lst)->data = (*lst)->next->data;
    (*lst)->next->data = k;
    write(1,"sa\n",3);
}

void    ft_ra(t_list **list)
{
    t_list *ptr;
    t_list *ptr1;
    ptr1 = (*list);
    ptr = (*list)->next;
    if(ft_lstsize(*list) >= 2)
    {
        while((*list)->next != NULL)
            (*list) = (*list)->next;
        (*list)->next = ptr1;
        (*list)->next->next = NULL;
        (*list) = ptr;
    }
    write(1,"ra\n",3);
}

void    ft_rra(t_list **lst)
{
    t_list *ptr;
    t_list *ptr1;
    ptr1 = (*lst);
    ptr = (*lst);
    int n = 1;
    if(ft_lstsize(*lst) >= 2)
    {
        while(n < ft_lstsize(*lst))
        {
            ptr = ptr->next;
            n++;
        }
        while((*lst)->next != NULL)
            (*lst) = (*lst)->next;
        ptr->next = NULL;
        (*lst)->next = ptr1;
    }
    write(1,"rra\n",4);
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*ptr;

	if (*stack_b == NULL)
		return ;
	ptr = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = ptr;
    write(1,"pb\n",3);
}