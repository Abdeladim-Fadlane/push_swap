/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:33:20 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/13 11:38:26 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void    ft_ss(t_list **lst)
{
    ft_sa(lst);
    ft_sb(lst);
    write(1,"ss\n",3);
}

void    ft_rr(t_list **lst)
{
    ft_ra(lst);
    ft_rb(lst);
    write(1,"rr\n",3);
}

void    ft_rrr(t_list **lst)
{
    ft_rra(lst);
    ft_rrb(lst);
    write(1,"rrr\n",4);
}
