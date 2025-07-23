/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:19 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/23 19:39:21 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*strchr(const char *str, int c)
{
	int				i;
	int				len;
	unsigned char	uc;

	uc = (unsigned char)c;
	len = (int)strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == uc)
			return ((char *)str + (int)i);
		i++;
	}
	return (NULL);
}

char	*strjoin(char const *s1, char const *s2)
{
	int		finallen;
	int		i;
	char	*arr;

	i = 0;
	/*if (!s2)
		return (strdup(s1));*/
	finallen = strlen(s1) + strlen(s2);
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


char	*strdup(const char *s)
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


char	*substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)strlen(s))
		return (strdup(""));
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


#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("zzzz.txt", O_CREAT | O_RDWR, 0777);
    //int total = find_total(fd);
    //printf("%d\n", total);
    char *c;
    
    c = get_next_line(fd);
    printf("%s", c);
    
    c = get_next_line(fd);
    printf("%s", c);
    c = get_next_line(fd);
    printf("%s", c);
    c = get_next_line(fd);
    printf("%s", c);
    c = get_next_line(fd);
    printf("%s", c);
    c = get_next_line(fd);
    printf("%s", c);
    c = get_next_line(fd);
    printf("%s", c);
    c = get_next_line(fd);
    printf("%s", c);
	c = get_next_line(fd);
    printf("%s", c);



	
}