/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:45:08 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/10 10:21:07 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_free(char **ptr)
{
    int i = 0;
    while(ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}

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
}

void duplicate(int *array, int n)
{
    int i = 0;
    int j ;
    while (i < n)
    {   j = i + 1;
        while( j < n)
        {
            if (array[i] == array[j])
            {
                printf("There are duplicates.\n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void    sort_arr(int *arr,int length)
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
}