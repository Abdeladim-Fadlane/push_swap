/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:30 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/17 18:38:11 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
void    ft_error(void)
{
    write(1,"Error.\n",7);
        exit(1);
}

int main(int ac ,char **av)
{
    t_list *stack_a;
    t_list *new;
    char **container;
    int h = 0;
    container = get_arg(av,ac);
    if(ac == 1 || !check_digit(container) )
        ft_error();
    while(container[h])
    {
        new = ft_lstnew(ft_atoi(container[h]));
        add_back(&stack_a,new);
        h++; 
    }
    int *num  ;
    num = stock_arr(container,ft_lstsize((stack_a)));
    // for(int y = 0;y <  (ft_lstsize((stack_a))) ; y++)
    // {
    //     printf("%d\n",num[y]);
    // }
    //printf("%d--",ft_lstsize((stack_a)));
    t_list *stack_b;
    sort_stack(&stack_a ,&stack_b,num,ft_lstsize((stack_a)) );  
    printList(stack_b);
    //top_elememt2(&stack_a , 1 , 4);
    // printf("=======================\n");
    printList(stack_b);
    //system("leaks push_swap");
}