/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:30 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/19 18:11:05 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int main(int ac ,char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    t_struct *object = malloc(sizeof(t_struct));
    int h = 0;
    if(ac == 1)
        exit(1);
    object->container = get_arg(av,ac);
    if(!check_digit(object->container) || check_limits(av))
        ft_error();
    while(object->container[h])
    {
        add_back(&stack_a,ft_lstnew(ft_atoi(object->container[h])));
        h++; 
    }
    object->num = stock_arr(object->container,ft_lstsize((stack_a)));
    sort_stack(&stack_a ,&stack_b,object->num);
   
    //system("leaks push_swap");
}



void printList(t_list *start) 
{ 
    t_list *temp = start;
    while (temp!=NULL) 
    { 
        printf("%d\n", temp->data); 
        temp = temp->next; 
    } 
}
