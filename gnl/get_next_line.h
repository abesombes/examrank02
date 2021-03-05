/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:54:45 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/05 15:29:53 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BS
# define BS 1
#endif

# define GNL_ERROR -1
# define GNL_FINISHED 0
# define GNL_OK 1

# define READ_ERROR -1
# define READ_FINISHED 0

typedef struct  s_fi
{
                char *buf;
                int pos;
                int fd;
                int bytes_read;
}               t_fi;

int	get_next_line(char **line);

#endif