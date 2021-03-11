#include <unistd.h>
#include <stdio.h>

int ft_char_appears_before(char *s1, char c, int max_i)
{
	int i;

	i = 0;
	while(s1[i] && i < max_i)
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s && s[i++]);
	return (i);
}

int main(int ac, char **av)
{
	char *s1;
	char *s2;
	int i;
	int j;

	i = 0;
	s1 = av[1];
	s2 = av[2];
	if (ac == 3)
	{
		while(s1[i])
		{
			j = 0;
			while(s2[j] && s1[i] != s2[j])
				j++;
			if (j < ft_strlen(s2) - 1 && !ft_char_appears_before(s1, s1[i], i))
				write(1, &s1[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}