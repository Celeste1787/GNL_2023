/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:59 by akdovlet          #+#    #+#             */
/*   Updated: 2023/09/22 13:51:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_newline(char *str);
char	*ft_next_line(char *str);
char	*get_next_line(int fd);
char	*ft_line(char *str);
char	*ft_init(char *buffer, int fd);

#endif
