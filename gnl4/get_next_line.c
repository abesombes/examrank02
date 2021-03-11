#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s && s[++i]);
	return (i);
}

char *ft_strjoin(char *str, char c)
{
	char *new;
	int i;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(ft_strlen(str) + 2)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	return (new);
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