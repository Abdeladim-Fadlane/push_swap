/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:33:20 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/11 18:24:37 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    ft_sa(t_list **lst)
{
    int k;
   
    k = (*lst)->data;
    (*lst)->data = (*lst)->next->data;
    (*lst)->next->data = k;
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
}

void    push_b(t_list **stack_a,t_list **stack_b)
{   
    if((*stack_b) != NULL)
    {
        (*stack_b)->next = (*stack_a);
    }else
    {
        (*stack_b) = (*stack_a);
        (*stack_a) = (*stack_a)->next;
        (*stack_b)->next = NULL;
    }
    return ;
}