/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:19 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/24 15:52:37 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	int				len;
	unsigned char	uc;

	uc = (unsigned char)c;
	len = (int)ft_strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == uc)
			return ((char *)str + (int)i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		finallen;
	int		i;
	char	*arr;

	i = 0;
	finallen = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(finallen + 1);
	if (arr == NULL)
		return (NULL);
	while (*s1)
	{
		arr[i] = (char)*s1++;
		i++;
	}
	while (*s2)
	{
		arr[i] = (char)*s2++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*p;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	p = malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (NULL);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
