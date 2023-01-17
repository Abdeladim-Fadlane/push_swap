/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:00:15 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/17 18:47:09 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	hundred_sort(t_list **lst,t_list **lst2,int *num,int size);
void	short_sort(t_list	**lst)
{
	int b;
	int c;

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

void	sort_stack(t_list **lst,t_list **lst2,int *num,int n)
{
	// if(ft_lstsize(*lst) == 2)
	// 	ft_sa(lst);
	// else if(ft_lstsize(*lst) == 3)
	// 	short_sort(lst);
	// else if(ft_lstsize(*lst)  == 4 ||  ft_lstsize(*lst) == 5)
	// {
	// 	five_sort(lst,lst2);
	// }
	// else if(ft_lstsize(*lst) == 10)
	// {
		hundred_sort(lst,lst2,num,n);
	//}
}

int get_index_min(t_list *lst)
{
    int x = lst->data;
    int index = 0;
    int i = 1;
    while(lst)
    {
        if(x > lst->data)
        {
            x = lst->data;
            index = i;
        }
        i++;
        lst = lst->next;
    }
    return index;
}
int get_min(t_list *lst)
{
    int x = lst->data;
    while(lst)
    {
        if(x > lst->data)
            x = lst->data;
        lst = lst->next;
    }
    return x;
}
void	top_elememt(t_list **lst)
{
	int x ; 
	int y ;
	x = get_min(*lst);
	y = get_index_min(*lst);
	
	if(y < ft_lstsize(*lst) / 2)
	{
		while(x != (*lst)->data)
			ft_ra(lst);
	}
	else if(y >= ft_lstsize(*lst) / 2)
	{
		while( (*lst)->data != x )
			ft_rra(lst);
	}
}

void	five_sort(t_list **lst,t_list **lst2)
{
	while(ft_lstsize(*lst) > 3)
	{
		top_elememt(lst);
		push_b(lst,lst2);
	}
	short_sort(lst);
	while(*lst2)
		push_a(lst2,lst);
}


int	get_index(t_list **lst, int *ar, int start, int end)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->data >= ar[start] && tmp->data <= ar[end])
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}


void	hundred_sort(t_list **a, t_list **b, int *ar,int size)
{
	int mid = size  / 2 - 1;
	int offset = size / 8;
	int start = mid -  offset;
	int end = mid +  offset;
	int index ;

	(void)b;
	while (*a)
	{	
		index = get_index(a, ar, start, end);
		while(index >= 0)
		{
			if(index < ft_lstsize(*a) / 2)
			{
				while (!((*a)->data >= ar[start] && (*a)->data <= ar[end]))
					ft_ra(a);
			}
			else if(index >= ft_lstsize(*a) / 2)
			{
				while (!((*a)->data >= ar[start] && (*a)->data <= ar[end]))
					ft_rra(a);	
			}
			push_b(a, b);
			if ((*b)->data < ar[mid])
				ft_rb(b);
			index = get_index(a, ar, start, end);
			//printf("i = %d",index);
			//break;
		}
		
		if(start < 0)
			start = 0;
		if(end > size)
			end = size;
		start -= offset;
		end += offset;
		}
}
///
///















// void	hundred_sort(t_list **ptr,t_list **lst2,int *num,int size)
// {
// 	int mid = size / 2;
// 	int start = mid - size / 8;
// 	int end = mid + size / 8;
// 	while(ptr)
// 	{
// 		int y = get_index((*ptr),num,start,end);

		
// 		while(start <= end)
// 		{
// 			if ((*ptr)->data >= num[start] && (*ptr)->data <= num[end])
// 			{
// 				top_elememt2((ptr),num[start],y);
// 				push_b(ptr,lst2);
// 			}
// 			start++;
// 		}
// 		start--;
// 		if(start == end)
// 		{
// 			start = start - size / 8;
// 		    end = end + size / 8 ;	
// 		}
// 		if(start < 0)
// 			start = 0;
// 		if(end > size)
// 			end = size;
// 	}
// }
