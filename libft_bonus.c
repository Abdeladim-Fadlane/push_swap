/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:06 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/18 18:47:15 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push_swap.h"

t_list  *ft_lstnew(int k)
{
    t_list *list ;
    list = (t_list *)malloc(sizeof(t_list));

    list->data = k;
    list->next = NULL;
    return(list); 
}

t_list *ft_lstlast(t_list **list)
{
    t_list *tmp;

    tmp = (*list);
    while(tmp->next)
        tmp = tmp->next;
    return (tmp);
}

void    add_back(t_list **list,t_list *new)
{
    t_list *tmp;

    tmp = (*list);
    if ((*list) == NULL)
        *list = new;
    else if ((*list))
    {
        tmp = ft_lstlast(list);
        tmp->next = new;
    }
}

int ft_lstsize(t_list *list)
{
    int i = 0;
 
    while (list)
    {
        i++;
        list = list->next;
    }

    return i ;
}