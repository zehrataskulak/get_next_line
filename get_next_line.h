/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:39:24 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/23 19:01:34 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
size_t	strlen(const char *str);
char	*strchr(const char *str, int c);
char	*strjoin(char const *s1, char const *s2);



char	*strdup(const char *s);
char	*substr(const char *s, unsigned int start, size_t len);



char *read_file(int fd);

//char *read_line(int fd, char *buff);


#endif