/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:16:19 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/09 16:55:25 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_newline(char *str)
{

}
static char	*read_line(char *stash)
{
	char	*line;
	int		index;

	if (!stash)
		return (NULL);
	index = 0;
	while (stash[index] != '\0' || stash[index] != '\n')
		index++;
	line = malloc(sizeof(char) * index + 1);
	if (line == NULL)
		return (NULL);
	index = 0;
	while (stash[index] != '\0' || stash[index] != '\n')
	{
		line[index] = stash[index];
		index++;
	}
	if (stash[index] != '\n')
	{
		line[index] = stash[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

void	freedom(char *buffer1, char *buffer2)
{
	free(buffer1);
	free(buffer2);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*read_content;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_content = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_content == NULL)
		return (NULL);
	while (bytes_read != 0 && ft_strchr(stash, '\n') == 0)
	{
		bytes_read = read(fd, read_content, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			freedom(read_content, stash);
			return (NULL);
		}
		read_content[bytes_read] = '\0';
		stash = ft_strjoin(stash, read_content);
	}
	bytes_read = find_newline(stash);
	read_content = read_line(stash);
	stash = ft_substring
	return (read_content);
}
