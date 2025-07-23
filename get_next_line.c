/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:22 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/22 23:04:49 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line1(int fd)

{
    static char *buff;
    int i;
    char *line;
    char *buff_t;
    int j;
    
    j = 0;
    i = 0;
    if (buff)
        line = buff;
    buff = read_file(fd);
    if (!buff)
    return (NULL);
    if (!line)
	    line = strdup("");
    if (strchr(buff, '\n'))
    {
        while(buff[i] != '\n')
            i++;
        buff_t = malloc(i + 1);
        if (!buff_t)
            return (NULL);
        while (j < i)
        {
            buff_t[j] = buff[j];
            j++;
        }
        buff_t[j] = '\0';
        line = strjoin(line, buff_t);
    }
    else
    {
        while (!strchr(buff, '\n') && !strchr(buff, '\0'))
        {
            line = strjoin(line, buff);
            buff = read_file(fd);
        }
    }
    
    
    return (line);
}

char *function(char *buff, char *line, char *tmp, int nlen)
{
    int i;

    i = 0;
    
    while(buff[nlen] != '\n')
        nlen++;
    //tmp = malloc(nlen + 1);
    //if (!tmp)
    //    return (NULL);
    while(i < nlen)
    {
        line[i] = buff[i];
        i++;
    }
    line[i] = '\0';
    tmp = strchr(buff, '\n');
    return (line);
}

char *get_next_line(int fd)
{
    char *line;
    char *buff;
    int nlen;
    static char *tmp;

    nlen = 0;
    line = NULL;
    if(tmp)
        buff = tmp;
    if (!buff)
        buff = read_file(fd);
    if(!line)
        line = strdup("");
    if (buff && strchr(buff, '\n'))
        return (function(buff, line, tmp, nlen));
    else if(buff && strchr(buff, '\0'))
    {
        line = strjoin(tmp, buff);
    }
    return (line);
    
}