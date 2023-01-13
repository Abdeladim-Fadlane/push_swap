/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/12 14:00:36 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printList(t_list *start) 
{ 
    t_list *temp = start;
    while (temp!=NULL) 
    { 
        printf("%d\n", temp->data); 
        temp = temp->next; 
    } 
}

void    stock_arr(char **container ,int ac)
{
    int  j = 0;
    int k ;
    int *num = malloc(sizeof(int ) * ac);
    while(container[j])
    {
        k = ft_atoi(container[j]);
        num[j] = k;
        j++; 
    }
    duplicate(num,ac - 1);
    free(num);
}

char    **get_arg(char **av,int ac)
{
    int  i = 1;
    char **container;
    char *buff = ft_strdup("");
    while(i < ac)
    {
        buff = ft_strjoin(buff,av[i]);
        buff = ft_strjoin(buff," ");
        ft_check(buff);
        i++;  
    }
    container = ft_split(buff,32);
    free(buff);
    return(container);
}
