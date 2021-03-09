/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:34:34 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 09:00:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return(i);
}

char *ft_calloc(int nb_elem, int size_elem)
{
	char *p;
	int len;
	int i;

	len = nb_elem * size_elem;
	if (!(p = (char *)malloc(len * sizeof(char))))
	i = 0;
	while (i < len)
		p[i++] = '\0';
	return (p);
}

int ft_str_pos(char *str, char c)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *ft_str_add_char(char *str, char c)
{
	char *s;
	int i;

	if (!(s = (char *)ft_calloc(1, (ft_strlen(str) + 2))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	free(str);
	s[i] = c;
	return (s);
}

char *ft_sub_str(char *str, int begin, int len)
{
	char *s;

	if (!(s = (char *)ft_calloc(1, len + 1)))
		return (NULL);
	while (str[begin] && begin < len)
	{
		s[begin] = str[begin];
		begin++;
	}
	return (s);	
}

int get_next_line(char **line)
{
	static char *s;
	char buf[1];
	char *tmp;
	int pos;
	
	if ((!line) || (!s && !(s = ft_calloc(1, 1))))
		return (-1);
	while (read(0, buf, 1) > 0)
	{
		s = ft_str_add_char(s, buf[0]);
		if (buf[0] == '\n')
			break;
	}
	if ((pos = ft_str_pos(s, '\n')) >= 0)
	{
		*line = ft_sub_str(s, 0, pos);	
		tmp = s;
		s = ft_sub_str(s, pos + 1, ft_str_pos(s, '\0'));
		free(tmp);
		return (1);
	}	
	*line = ft_sub_str(s, 0, '\0');
	free(s);
	return (0);
}