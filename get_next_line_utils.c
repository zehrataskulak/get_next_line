/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:19 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/22 23:06:19 by zzehra           ###   ########.fr       */
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


char *read_file(int fd)
{
    char *buff_tmp;
    int bytes;
    
    buff_tmp = malloc(BUFFER_SIZE + 1);
    if(!buff_tmp)
        return (NULL);
    bytes = read(fd, buff_tmp, BUFFER_SIZE);
    if(bytes < 0)
    {
        free (buff_tmp);
        return (NULL);
    }
    buff_tmp[bytes] = '\0';
    return (buff_tmp);
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
    printf("%s\n", c);
    
    /*c = get_next_line(fd);
    printf("%s\n", c);
    c = get_next_line(fd);
    printf("%s\n", c);
    c = get_next_line(fd);
    printf("%s\n", c);
    c = get_next_line(fd);
    printf("%s\n", c);
    c = get_next_line(fd);
    printf("%s\n", c);
    c = get_next_line(fd);
    printf("%s\n", c);
    c = get_next_line(fd);
    printf("%s\n", c);*/
   
    
}