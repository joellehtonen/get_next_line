/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:46:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/14 15:48:51 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*write_line(char *pile)
{
	char	*line;
	size_t	index;

	index = 0;
	if (!pile || *pile == '\0')
		return (NULL);
	index = find_newline(pile);
	line = malloc(sizeof(char) * (index + 1));
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

static char	*create_new_pile(char *pile)
{
	size_t	index_a;
	size_t	index_b;
	size_t	len;
	char	*new_pile;

	if (!pile || !*pile)
	{
		free(pile);
		return (NULL);
	}
	len = ft_strlen(pile);
	index_a = find_newline(pile);
	index_b = 0;
	new_pile = malloc(sizeof(char) * (len - index_a + 1));
	if (!new_pile)
		return (NULL);
	while (pile[index_a] != '\0')
		new_pile[index_b++] = pile[index_a++];
	new_pile[index_b] = '\0';
	free(pile);
	return (new_pile);
}

static char	*add_to_pile(char *pile, const char *text)
{
	size_t	index_a;
	size_t	index_b;
	size_t	len;
	char	*bigger_pile;

	index_a = 0;
	index_b = 0;
	if (text == NULL || *text == '\0')
		return (pile);
	len = ft_strlen(pile) + ft_strlen(text);
	bigger_pile = malloc(sizeof(char) * (len + 1));
	if (!bigger_pile)
		return (free(bigger_pile), NULL);
	while (pile != NULL && pile[index_a] != '\0')
	{
		bigger_pile[index_a] = pile[index_a];
		index_a++;
	}
	while (text[index_b] != '\0')
		bigger_pile[index_a++] = text[index_b++];
	bigger_pile[index_a] = '\0';
	free(pile);
	return (bigger_pile);
}

char	*get_next_line(int fd)
{
	static char	*pile[MAX_FD];
	char		*line;
	char		text[BUFFER_SIZE + 1];
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(pile[fd], '\n'))
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(pile[fd]);
			pile[fd] = NULL;
			return (NULL);
		}
		text[bytes_read] = '\0';
		pile[fd] = add_to_pile(pile[fd], text);
	}
	line = write_line(pile[fd]);
	pile[fd] = create_new_pile(pile[fd]);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;

	i = 1;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		printf("Line %d: %s", i, line);
		i++;
		free(line);
	}
	return (0);
}*/
