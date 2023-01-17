/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:45:08 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/16 18:58:34 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	limits(char *arg)
{
	return (ft_atoi(arg) < INT_MIN || ft_atoi(arg) > INT_MAX);
}

int	check_limits(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (limits(av[i]))
			return (1);
		i++;
	}
	return (0);
}
int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == ' ');
}

int	isit_int(char *ptr)
{
	int	i;

	i = 0;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	while (ptr[i])
	{
		if (!ft_isdigit(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (!isit_int(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}

void check_duplicate(int *array, int n)
{
    int i = 0;
    int j ;
    while (i < n)
    {   j = i + 1;
        while( j < n)
        {
            if (array[i] == array[j])
                ft_error();
            j++;
        }
        i++;
    }
}

int    *sort_arr(int *arr,int length)
{
    int i = 0;
    int j;
    int temp;
    while(i < length)
    { 
        j = i + 1;
        while (j < length)
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