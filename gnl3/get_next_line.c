/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:32:47 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 16:03:32 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s, char c)
{
    char *new_s;
    int i;

    if (!s)
        return (NULL);
    if (!(new_s = (char *)malloc(ft_strlen(s) + 2)))
        return (NULL);
    i = -1;
    while (s && s[++i])
        new_s[i] = s[i];
    new_s[i++] = c;
    new_s[i] = '\0';
    return (new_s);
}   

int get_next_line(char **line)
{
    char buf[2];
    char *str;
    char *tmp;

    buf[1] = 0;
    if (!line || !(str = (char *)malloc(1)))
        return (-1);
    str[0] = 0;
    while (read(0, buf, 1) > 0)
    {
        tmp = str;
        if (buf[0] == '\n')
        {
            *line = str;
            return (1);
        }
        if (!(str = ft_strjoin(str, buf[0])))
        {
            free(tmp);
            return (-1);
        }
        free(tmp);
    }
    *line = str;
    return (0);
}