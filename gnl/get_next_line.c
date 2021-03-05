/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:00:50 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/05 15:31:49 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_has_newline(char *str)
{
    while (*str)
        if (*str++ == '\n')
            return (1);
    return (0);
}

void ft_copy_paste_buf_into_line(t_fi *fi, char **line)
{
    int i;

    i = 0;
    while (fi->buf[fi->pos] != '\n')
    {
        *line[i] = fi->buf[fi->pos];
        i++;
        fi->pos++;
    }
}

int get_next_line(char **line)
{
    static t_fi    fi;
    
    fi.fd = 0;
    fi.pos = 0;
    if (ft_has_newline(fi.buf + fi.pos))
        ft_copy_paste_buf_into_line(&fi, line);
        
    while ((fi.bytes_read = read(fi.fd, fi.buf, BS)) > 0)
    {
        
    }
    return (1);
}
