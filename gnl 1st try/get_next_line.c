/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:55:05 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/06 00:43:07 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_calloc(int nb_elem, int size_elem)
{
	char *s;
	int i;

	if (!(s = (char *)malloc(nb_elem * size_elem)))
		return (NULL);
	i = 0;
	while (i < nb_elem * size_elem)
	{
		s[i] = '\0';
		i++;			
	}
	return (s);
}

int 	ft_strlen(char *s)
{
	int i;
	
	i = -1;
	while (s[++i]);
	return (i);
}

char 	*ft_str_add(char *line, char c)
{
	char *new;
	int	len;
	int i;

	len = ft_strlen(line);
	if (!(new = (char *)ft_calloc(len + 2, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i] = c;
	if (line)
		free(line);
	return (new); 
}

int get_next_line(char **line)
{
	static char *s;
	char buf[1];
	//char *tmp;
	int ret;
	
	if (!line || (!s && !(s = (char*)ft_calloc(1, 1))))
		return (-1);
	while ((ret = read(0, buf, 1)) > 0)
	{
		*line = ft_str_add(*line, buf[0]);
		if (buf[0] == '\n')
			break;
	}
	return (0);
}

int main(void)
{
	char *line;
	int ret;
	int i;

	i = 0;
	while ((ret = get_next_line(&line)) > 0)
	{
		i++;
		printf("line %i: [%s] - %i", i, line, ret);
		free(line);
		line = 0;
	}
	printf("line %i: [%s] - %i", i, line, ret);
	free(line);
	line = 0;
}