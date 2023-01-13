/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:33 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/13 11:10:08 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_AWAP
#define PUSH_AWAP

#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include<unistd.h>


typedef	struct list
{
	int  data;
	struct list *next;
}t_list;

int		ft_atoi(char *s);
void	ft_free(char **ptr);
char	**ft_split(char *s,char c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
t_list  *ft_lstnew(int k);
void    add_back(t_list **list,t_list *new);
t_list 	*ft_lstlast(t_list **list);
void    ft_check(char  *i);
void 	duplicate(int *array,int n);
void    sort_arr(int *arr,int length);
int 	ft_lstsize(t_list *list);
void    ft_sa(t_list **list);
void    ft_ra(t_list **list);
void	printList(t_list *start);
void    ft_rra(t_list **lst);
void	push_b(t_list **stack_a, t_list **stack_b);
void    stock_arr(char **container ,int ac);
char    **get_arg(char **av,int ac);
void	push_a(t_list **stack_b, t_list **stack_a);
void    ft_sb(t_list **lst);
void    ft_rb(t_list **list);
void    ft_rr(t_list **lst);
void    ft_rrb(t_list **lst);
void    ft_rrr(t_list **lst);
#endif
