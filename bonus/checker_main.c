/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:30 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/21 16:28:54 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_if_sort(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i] && s2[i] == s1[i])
	    i++;
	return (s2[i] - s1[i]);
}
void	ft_rules(char *tmp, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(tmp, "sa\n") == 0)
		ft_sa(stack_a);
	else if (ft_strcmp(tmp, "pa\n") == 0)
		push_a(stack_b, stack_a);
	else if (ft_strcmp(tmp, "ra\n") == 0)
		ft_ra(stack_a);
	else if (ft_strcmp(tmp, "rra\n") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(tmp, "sb\n") == 0)
		ft_sb(stack_b);
	else if (ft_strcmp(tmp, "pb\n") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(tmp, "rb\n") == 0)
		ft_rb(stack_b);
	else if (ft_strcmp(tmp, "rrb\n") == 0)
		ft_rrb(stack_b);
	else if (ft_strcmp(tmp, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(tmp, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(tmp, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else
		ft_error();
}

int main(int ac ,char **av)
{
    t_list *stack_a;
    t_list *stack_b = NULL;
    char	*ptr;
    t_struct *object = malloc(sizeof(t_struct));
    int h = 0;
    if(ac == 1)
        exit(0);
    object->container = get_arg(av,ac);
    if(!check_digit(object->container) || check_limits(av))
        ft_error();
    while(object->container[h])
    {
        add_back(&stack_a,ft_lstnew(ft_atoi(object->container[h])));
        h++; 
    }
    object->num = stock_arr(object->container,ft_lstsize((stack_a)));
    while (1)
	{
		ptr = get_next_line(0);
		if (ptr == NULL)
        {
            break ;
        }
		ft_rules(ptr, &stack_a, &stack_b);
		free(ptr);
	}
	if (check_if_sort(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
