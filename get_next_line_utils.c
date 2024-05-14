/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:16:30 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/14 13:59:53 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_newline(char *pile)
{
	size_t	index;

	index = 0;
	if (!pile || *pile == '\0')
		return (0);
	while (pile[index] != '\0' && pile[index] != '\n')
		index++;
	if (pile[index] == '\n')
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c;
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s != a)
		s++;
	if (*s == a)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
