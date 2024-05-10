/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:16:30 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/10 15:06:53 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	int		index;
	int		len;
	char	*pointer;

	index = 0;
	len = ft_strlen((char *)s1);
	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		pointer[index] = s1[index];
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	index;
	size_t	s_len;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	s_len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	pointer = malloc(sizeof(char) * ((s_len) + 1));
	if (pointer == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		pointer[index] = *s1;
		s1++;
		index++;
	}
	while (*s2 != '\0')
	{
		pointer[index] = *s2;
		s2++;
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	index;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if ((start + len) > s_len)
		len = s_len - start;
	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	index = 0;
	while (s[start] != '\0' && len > 0)
	{
		pointer[index++] = s[start++];
		len--;
	}
	pointer[index] = '\0';
	return (pointer);
}
