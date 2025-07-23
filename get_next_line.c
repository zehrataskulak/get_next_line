/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:44:22 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/23 19:38:32 by ztaskula         ###   ########.fr       */
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



/*char *get_next_line1(int fd)

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
}*/

/*char *function(char *buff, char *line, char *tmp, int nlen)
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
}*/

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
    //if(strchr(rest, '\n') || !read_file(fd))
    //{
        result = substr(rest, 0, find_newline(rest));
        tmp = substr(rest, find_newline(rest), strlen(rest) - find_newline(rest));
        free (rest);
        rest = tmp;
    //}
    return (result);    
}

