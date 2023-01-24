/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:57:10 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/21 14:03:33 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    ft_ss(t_list **lst ,t_list **lst2)
{
    ft_sa(lst);
    ft_sb(lst2);
    write(1,"ss\n",3);
}

void    ft_rr(t_list **lst,t_list **lst2)
{
    ft_ra(lst);
    ft_rb(lst2);
    write(1,"rr\n",3);
}

void    ft_rrr(t_list **lst,t_list **lst2)
{
    ft_rra(lst);
    ft_rrb(lst2);
    write(1,"rrr\n",4);
}

void    ft_error(void)
{
    write(1,"Error.\n",7);
    exit(1);
}

int    *sort_arr(int *arr,int len)
{
    int i = 0;
    int j;
    int temp;
    while(i < len)
    { 
        j = i + 1;
        while (j < len)
        {     
           if(arr[i] > arr[j])
           {    
               temp = arr[i];    
               arr[i] = arr[j];    
               arr[j] = temp;    
           }
           j++;
        } 
        i++ ;  
    } 
    return arr;
}