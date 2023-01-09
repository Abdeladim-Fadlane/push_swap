/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/09 18:37:20 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push_swap.h"
// void ft_free(char **ptr)
// {
//     int i = 0;
//     while(ptr[i])
//     {
//         free(ptr[i]);
//         i++;
//     }
//     free(ptr);
// }
int main(int ac ,char **av)
{
    int i = 1;
    int size = ac - 1;   
    char *p = NULL ;
    char **container ;
    int k;
    //int *num = NULL; 
    int  j = 0;
    //int a = 0;
    char *buff ;
    if(ac <= 1)
    {
        printf("invalid");
        exit(1);
    }
    while(size > 0)
    {
        p = av[i];
        buff = ft_strjoin(buff,p);
        buff = ft_strjoin(buff," ");
        ft_check(buff);
        container = ft_split(buff,32);
        size--;
        i++;  
    }
    while(container[j])
    {
         k = ft_atoi(container[j]);
         //num[j] = k;
         ft_lstnew(k);
         j++;   
    }
    
    
    
    // for(int f = 0;f < 10  ;f++)
    // {
    //     printf("s[%d] = %s\n",f,container[f]);
    // }
    //printf("%s",buff);
    return (0);
}