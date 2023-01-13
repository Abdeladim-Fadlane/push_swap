/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:30 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/13 11:19:55 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac ,char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list *new;
    if(ac <= 1)
    {
        printf("invalid arg");
        exit(1);
    }
    char **container = get_arg(av,ac);
    stock_arr(container,ac);
    int h = 0;
    int k;
    while(container[h])
    {
        k = ft_atoi(container[h]);
        new = ft_lstnew(k);
        add_back(&stack_a,new);
        h++; 
    }
    //==================================//
    
    // ft_ra(&stack_a);
    // ft_rra(&stack_a);
    while(stack_a)
    {
        push_b(&stack_a,&stack_b);
    }
    printf("\n=====================\n");
    while(stack_b)
    {
        push_a(&stack_b,&stack_a); 
        ft_rra(&stack_a);
    }
    
    // push(&stack_a,&stack_b);
    //push_a(&stack_b,&stack_a);
    printf("=========B============\n");
    printList(stack_b);
    printf("=========A============\n");
    printList(stack_a);
    //printList(stack_b);
    //system("leaks push_swap");
    //return (0);
}