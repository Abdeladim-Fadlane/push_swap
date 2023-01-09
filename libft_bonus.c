/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:06 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/09 14:49:25 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push_swap.h"

t_list  *ft_lstnew(int k)
{
    t_list *list ;
    list = (t_list *)malloc(sizeof(t_list));

    list->data = k;
    list->next = NULL;
    printf("%d\n" ,list->data);
    return(list);
    
}

void ft_lstlast(t_list **list)
{
    while((*list)->next)
        *list = (*list)->next;
}

void    add_back(t_list **list,t_list *new)
{
    if ((*list) == NULL)
        *list = new;
    else if ((*list))
    {
        ft_lstlast(list);
        (*list)->next = new;
    }
}