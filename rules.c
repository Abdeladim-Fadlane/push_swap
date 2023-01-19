/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:57:10 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/19 18:09:28 by afadlane         ###   ########.fr       */
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