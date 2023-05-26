/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:06:08 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/07 14:09:30 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff_line(int fd, char *line)
{
	int		ret;
	char	*buff;

	ret = 1;
	if (!line)
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	while (!ft_strchrgnl(line, '\n') && ret > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buff);
			return (0);
		}
		buff[ret] = '\0';
		line = ft_strjoingnl(line, buff);
		free(buff);
	}
	return (line);
}

char	*execute(char *read, char *line, int i)
{
	while (read[i] && read[i] != '\n')
	{
		line[i] = read[i];
		i++;
	}
	if (read[i] == '\n')
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*copy_stash(char *read)
{
	int		i;
	char	*line;

	i = 0;
	if (!read[i])
		return (NULL);
	while (read[i] && read[i] != '\n')
		i++;
	while (read[i] && read[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	return (execute(read, line, i));
}

char	*find_send(char *line)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * (ft_strlengnl(line) -i + 1));
	if (!dst)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		dst[j++] = line[i++];
	dst[j] = '\0';
	free (line);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free (buff);
		return (NULL);
	}
	buff = read_buff_line(fd, buff);
	if (!buff)
		return (NULL);
	line = copy_stash(buff);
	buff = find_send(buff);
	return (line);
}
