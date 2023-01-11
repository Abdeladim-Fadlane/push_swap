/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/11 16:20:52 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"push_swap.h"

void printList(t_list *start) 
{ 
    t_list *temp = start;
    while (temp!=NULL) 
    { 

        printf("%d\n", temp->data); 
        temp = temp->next; 
    } 
}

int main(int ac ,char **av)
{
    int i = 1;
    int size = ac - 1;   
    char *p = malloc(ac);
    char **container ;
    char *buff ;
    t_list *stack_a;
    t_list *new;
    int k;
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
    int  j = 0;
    int *num = malloc(sizeof(int ) * ac); 
    while(container[j])
    {
        k = ft_atoi(container[j]);
        num[j] = k;
        j++; 
    }
    duplicate(num,ac - 1);
    int h = 0;
    while(container[h])
    {
        k = ft_atoi(container[h]);
        new = ft_lstnew(k);
        add_back(&stack_a,new);
        h++; 
    }
    t_list *stack_b;
    ft_sa(&stack_a);
    ft_ra(&stack_a);
    ft_rra(&stack_a);
    push_b(&stack_a,&stack_b);
    // push_b(&stack_a,&stack_b);
    printList(stack_a);
    //system("leaks push_swap");
    return (0);
}