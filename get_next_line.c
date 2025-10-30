/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:22 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/25 17:25:38 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd)
{
	int		bytes;
	char	*buff_tmp;

	buff_tmp = malloc(BUFFER_SIZE + 1);
	if (!buff_tmp)
		return (NULL);
	bytes = read(fd, buff_tmp, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free (buff_tmp);
		return (NULL);
	}
	buff_tmp[bytes] = '\0';
	return (buff_tmp);
}

static int	find_newl(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\n')
		i++;
	i++;
	return (i);
}

static char	*get_rest_result(char **result, char **rest)
{
	*result = ft_strdup(*rest);
	free(*rest);
	*rest = NULL;
	return (*result);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*newrest;
	char		*result;
	char		*tmp;

	if (!rest)
		rest = read_file(fd);
	if (!rest)
		return (NULL);
	while (!ft_strchr(rest, '\n'))
	{
		newrest = read_file(fd);
		if (!newrest)
			return (get_rest_result(&result, &rest));
		tmp = ft_strjoin(rest, newrest);
		free(newrest);
		free(rest);
		rest = tmp;
	}
	result = ft_substr(rest, 0, find_newl(rest));
	tmp = ft_substr(rest, find_newl(rest), ft_strlen(rest) - find_newl(rest));
	free (rest);
	rest = tmp;
	return (result);
}
