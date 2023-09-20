/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:42 by akdovlet          #+#    #+#             */
/*   Updated: 2023/09/20 17:28:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;		
	}
	return (i);
}

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*next;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	next = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!next)
		return (NULL);
	while (str[++i])
		next[j++] = str[i];
	next[j] = '\0';
	free(str);
	return (next);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*fusion;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	fusion = malloc(sizeof(char) * size);
	if (!fusion)
		return (NULL);
	while (s1[++i])
		fusion[i] = s1[i];
	while (s2[++j])
		fusion[i + j] = s2[j];
	fusion[i + j] = '\0';
	free(s1);
	return (fusion);
}
