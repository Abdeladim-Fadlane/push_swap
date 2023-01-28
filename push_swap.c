/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/26 15:34:25 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *num, int k)
{
	int	i;
	int	n;

	i = 1;
	n = num[0];
	while (i < k)
	{
		if (n > num[i])
		{
			return (0);
			break ;
		}
		n = num[i];
		i++;
	}
	return (1);
}

int	*stock_arr(char **container, int n)
{
	int	j;
	int	k;
	int	*num;

	j = 0;
	num = malloc(sizeof(int) * n);
	if (!num)
		return (0);
	while (container[j])
	{
		k = ft_atoi(container[j]);
		num[j] = k;
		j++;
	}
	check_duplicate(num, n);
	if (check_sort(num, n) == 1)
		exit(0);
	num = sort_arr(num, n);
	return (num);
}

char	**get_arg(char **av, int ac)
{
	int		i;
	char	**container;
	char	*buff;

	i = 1;
	buff = ft_strdup("");
	while (i < ac)
	{
		if ((av[i][0] == ' ' || av[i][0] == '\0') && !(av[i][1] >= '0'
				&& av[i][1] <= '9'))
			ft_error();
		buff = ft_strjoin(buff, av[i]);
		buff = ft_strjoin(buff, " ");
		i++;
	}
	container = ft_split(buff, 32);
	free(buff);
	return (container);
}

void	short_sort(t_list **lst)
{
	int	b;
	int	c;

	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if ((*lst)->data > b && b < c && (*lst)->data < c)
		ft_sa(lst);
	else if ((*lst)->data > b && b < c)
		ft_ra(lst);
	else if ((*lst)->data > b && b > c && (*lst)->data > c)
	{
		ft_ra(lst);
		ft_sa(lst);
	}
	else if ((*lst)->data < b && b > c && c > (*lst)->data)
	{
		ft_sa(lst);
		ft_ra(lst);
	}
	else if ((*lst)->data < b && b > c && (*lst)->data > c)
	{
		ft_ra(lst);
		ft_ra(lst);
	}
}
