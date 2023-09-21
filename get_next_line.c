/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:20:49 by akdovlet          #+#    #+#             */
/*   Updated: 2023/09/21 19:36:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init(char *buffer, int fd)
{
	char	*tmp;
	int		n;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	n = 1;
	while (!ft_newline(buffer) && n)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n <= 0)
			break;
		tmp[n] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*ft_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_init(buffer, fd);
	if (!buffer)
		return (free(buffer), NULL);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

// int main()
// {
// 	int			fd;
// 	int			i;
// 	char	*dest = NULL;

// 	i = 0;
// 	fd = open("stjoan", O_RDONLY);
// 	while (i < 13)
// 	{
// 		dest = get_next_line(fd);
// 		printf("%s", dest);
// 		i++;
// 		free(dest);
// 	}
// 	close(fd);
// }
