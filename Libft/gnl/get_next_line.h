/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:07:31 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 10:52:59 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_buff_line(int fd, char *line);
char	*ft_strchrgnl(const char *s, int c);
size_t	ft_strlengnl(const char *s);
char	*ft_strjoingnl(char *s1, char *s2);
char	*copy_stash(char *read);
char	*find_send(char *line);
char	*execute(char *read, char *line, int i);

#endif
