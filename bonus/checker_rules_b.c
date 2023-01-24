/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:37:24 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/21 16:18:29 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    ft_sb(t_list **lst)
{
    int k;
    if (!(lst))
		return ;
    if(ft_lstsize(*lst) >= 2)
    {
        k = (*lst)->data;
        (*lst)->data = (*lst)->next->data;
        (*lst)->next->data = k ;
    }

}
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

	if (!(stack_a))
		return ;
	ptr = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = ptr;
}

void    ft_rb(t_list **list)
{
  
    t_list *ptr;
    t_list *ptr1;
    ptr1 = (*list);
     if (!(list))
		return ;
    
    if(ft_lstsize(*list) >= 2)
    {   ptr = (*list)->next;
        while((*list)->next != NULL)
            (*list) = (*list)->next;
        (*list)->next = ptr1;
        (*list)->next->next = NULL;
        (*list) = ptr;
    }
}

void    ft_rrb(t_list **lst)
{
    t_list *ptr;
    t_list *ptr1;
    ptr1 = (*lst);
    ptr = (*lst);
    if (!(lst))
		return ;
    int n = 1;
    if(ft_lstsize(*lst) >= 2)
    {
        while(n < ft_lstsize(*lst) - 1)
        {
            ptr = ptr->next;
            n++;
        }
        while((*lst)->next != NULL)
            (*lst) = (*lst)->next;
        ptr->next = NULL;
        (*lst)->next = ptr1;
    } 
    
}