/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:03:33 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/21 13:24:57 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include<unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

typedef	struct list
{
	int  data;
	struct list *next;
}t_list;

typedef struct class
{
	char **container;
    int *num;
}t_struct;

typedef struct object
{
	int				size;
	int				start;
	int				end;
	int				offset;
	int				mid;
	int				index;

}					t_object;

typedef struct object2
{
	int				len;
	int				count;
	int				size;
}					t_object2;
void    ft_ss(t_list **lst,t_list **lst1);
void    ft_rr(t_list **lst,t_list **lst2);
void    ft_rrr(t_list **lst,t_list **lst2);
char	*get_next_line(int fd);
char	*ft_strchr( char *p, int c);
char	*ft_strdup(char *s1);
long	ft_atoi(char *s);
int		ft_strlen(char *s);
int 	ft_lstsize(t_list *list);
char	**ft_split(char *s,char c);
char    **get_arg(char **av,int ac);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void    add_back(t_list **list,t_list *new);
void 	check_duplicate(int *array,int n);
int   	*sort_arr(int *arr,int length);
void    ft_sa(t_list **list);
void    ft_ra(t_list **list);
void    ft_rra(t_list **lst);
void	push_b(t_list **stack_a, t_list **stack_b);
int     *stock_arr(char **container ,int ac);
void	push_a(t_list **stack_b, t_list **stack_a);
void    ft_sb(t_list **lst);
void    ft_rb(t_list **list);
void    ft_rrb(t_list **lst);
void	sort_stack(t_list **lst,t_list **lst2,int *num);
int	    check_digit(char **ptr);
void    ft_error(void);
int	    check_limits(char **av);
void	hundred_sort(t_list **a, t_list **b, int *ar);
void	back_to_a(t_list **b, t_list **a, int *ar);
int		get_size(t_list *stack);
t_list  *ft_lstnew(int k);
t_list 	*ft_lstlast(t_list **list);
void	short_sort(t_list	**lst);
#endif
