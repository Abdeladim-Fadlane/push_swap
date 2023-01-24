/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/21 15:57:50 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"



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
    return num;
}

char    **get_arg(char **av,int ac)
{
    int  i = 1;
    char **container;
    char *buff = ft_strdup("");
    while(i < ac)
    {
        if ((av[i][0] == ' '  || av[i][0] == '\0') && !(av[i][1] >= '0' && av[i][1] <= '9'))
		    ft_error();
        buff = ft_strjoin(buff,av[i]);
        buff = ft_strjoin(buff," ");
        i++;  
    }

    container = ft_split(buff,32);
    free(buff);
    return(container);
}
