/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:22 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/24 01:19:23 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_file(int fd)
{
    char *buff_tmp;
    int bytes;
    
    buff_tmp = malloc(BUFFER_SIZE + 1);
    if(!buff_tmp)
        return (NULL);
    bytes = read(fd, buff_tmp, BUFFER_SIZE);
    if(bytes <= 0)
    {
        free (buff_tmp);
        return (NULL);
    }
    buff_tmp[bytes] = '\0';
    return (buff_tmp);
}

int find_newline(char *rest)
{
    int i;

    i = 0;
    while(rest[i] != '\n')
        i++;
    i++;
    return (i);
}

char *get_next_line(int fd)
{
    static char *rest;
    char *newrest;
    char *result;
    char *tmp;
    
    if(!rest)
        rest = read_file(fd);
    if(!rest)
        return (NULL);
    while (!strchr(rest, '\n'))
    {
        newrest = read_file(fd);
        if(!newrest)
        {
            if (*rest == '\0')
            {
                free(rest);
                rest = NULL;
                return NULL;
            }
            result = rest;
            rest = NULL;
            return (result);
        }
        tmp = strjoin(rest, newrest);
        free(newrest);
        free(rest);
        rest = tmp;
    }
    result = substr(rest, 0, find_newline(rest));
    tmp = substr(rest, find_newline(rest), strlen(rest) - find_newline(rest));
    free (rest);
    rest = tmp;
    return (result);    
}

