/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:57:10 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/21 14:01:19 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    ft_ss(t_list **lst,t_list **lst1)
{
    ft_sa(lst);
    ft_sb(lst1);
}

void    ft_rr(t_list **lst,t_list **lst2)
{
    if(lst == NULL || lst2 == NULL)
        return ;
    ft_ra(lst);
    ft_rb(lst2);
}

void    ft_rrr(t_list **lst,t_list **lst2)
{
    ft_rra(lst);
    ft_rrb(lst2);
}

void    ft_error(void)
{
    write(1,"Error.\n",7);
    exit(1);
}