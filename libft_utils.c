/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:57:26 by afadlane          #+#    #+#             */
/*   Updated: 2023/01/16 09:10:08 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if(!s2)
		return s1;
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	free(s1);
	p[i] = 0;
	return (p);
}


char	*ft_strdup(char *s1)
{
	char	*p = "";
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

long	ft_atoi(char *str)
{
	long			i;
	long			res;
	unsigned long long			sn;

	if(!str)
		return 0;
	i = 0;
	res = 0;
	sn = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sn = sn * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sn);
}