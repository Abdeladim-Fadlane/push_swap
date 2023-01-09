/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:45:08 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/09 18:24:29 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == ' ');
}

int check_is_number(char *p)
{
    int i = 0;
    
    while(p[i])
    { 
        if(p[i] == '-' || p[i] == '+')
            i++;
        if(!(ft_isdigit(p[i])))
            return 0;
        i++;
    }
    return 1;
}


void    ft_check(char *p)
{
    if(!(check_is_number(p)))
    {
        printf("invalid");
        exit(1);
    } 
    return;
}