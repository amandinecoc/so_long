/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:22:32 by amandine          #+#    #+#             */
/*   Updated: 2025/12/04 07:26:58 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
int		check_n_in_remaining_line(char **line, char *buffer);
int		check_n_in_next_line(char **line, char *buffer, int fd, int len_buf);
int		fill_remain_in_buffer(int i, char **tmp, char *buffer, char **line);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_bzero_gnl(void *s, int n);

#endif