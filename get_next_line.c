/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:16:19 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/10 14:55:14 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_newline(char *pile)
{
	int	index;

	index = 0;
	while (pile[index] != '\0' && pile[index] != '\n')
		index++;
	if (pile[index] == '\n')
		index++;
	return (index);
}

static char	*read_line(char *pile)
{
	char	*line;
	int		index;

	if (!pile || *pile == '\0')
		return (NULL);
	index = find_newline(pile);
	line = malloc(sizeof(char) * index + 1);
	if (line == NULL)
		return (NULL);
	index = 0;
	while (pile[index] != '\0' && pile[index] != '\n')
	{
		line[index] = pile[index];
		index++;
	}
	if (pile[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*pile;
	char		*text;
	int			bytes_read;

	bytes_read = 1;
	pile = NULL;
	text = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	text = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (text == NULL)
	{
		free(text);
		return (NULL);
	}
	while (bytes_read != 0 && ft_strchr(pile, '\n') == 0)
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(text);
			free(pile);
			return (NULL);
		}
		text[bytes_read] = '\0';
		pile = ft_strjoin(pile, text);
	}
	free(text);
	text = read_line(pile);
	bytes_read = find_newline(pile);
	pile = ft_substr(pile, bytes_read, (ft_strlen(pile) - bytes_read));
	return (text);
}
