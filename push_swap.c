/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/17 09:58:32 by afadlane         ###   ########.fr       */
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
int check_sort(int *num,int k)
{
    int i = 1;
    int n = num[0];
    while(i < k)
    {
        if(n > num[i])
        {
            return 0;
            break;
        }
        n = num[i];
        i++;
    }
    return (1);
}
int    *stock_arr(char **container ,int n)
{
    int  j = 0;
    int k ;
    int *num = malloc(sizeof(int) * n);
    if(!num)
        return(0);
    while(container[j])
    {
        k = ft_atoi(container[j]);
        num[j] = k;
        j++; 
    }
    check_duplicate(num,n);
    if(check_sort(num,n) == 1)
       ft_error();
    num = sort_arr(num,n); 
    return num;
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
        i++;  
    }
    container = ft_split(buff,32);
    free(buff);
    return(container);
}