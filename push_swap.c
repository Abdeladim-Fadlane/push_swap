/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/19 18:05:08 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    if(n != 1 && check_sort(num,n) == 1)
       ft_error();
    num = sort_arr(num,n); 
    return num;
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

void	short_sort(t_list	**lst)
{
	int b;
	int c;

	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if ((*lst)->data > b && b < c && (*lst)->data < c)
		ft_sa(lst);
	else if ((*lst)->data > b && b < c)
		ft_ra(lst);
	else if ((*lst)->data > b && b > c && (*lst)->data > c)
	{
		ft_ra(lst);
		ft_sa(lst);
	}
	else if ((*lst)->data < b && b > c && c > (*lst)->data)
	{ 
		ft_sa(lst);
		ft_ra(lst);
	}
	else if ((*lst)->data < b && b > c && (*lst)->data > c)
	{
		ft_ra(lst);
		ft_ra(lst);
	}
}