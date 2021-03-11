#include <unistd.h>

int ft_char_appears_before(char *s1, char *s2, char c, int max_i)
{
	int i;

	i = 0;
	if (s2)
	{
		while(s2[i] && i < max_i)
		{
			if (s2[i] == c)
				return (1);
			i++;
		}
		i = 0;
		while(s1[i])
		{
			if (s1[i] == c)
				return (1);
			i++;
		}
	}
	else if (s1)
	{
		while(s1[i] && i < max_i)
		{
			if (s1[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	char *s1;
	char *s2;
	int i;

	i = 0;
	s1 = av[1];
	s2 = av[2];
	if (ac == 3)
	{
		while(s1[i])
		{
			if (!ft_char_appears_before(s1, 0, s1[i], i))
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while(s2[i])
		{
			if (!ft_char_appears_before(s1, s2, s2[i], i))
				write(1, &s2[i], 1);
			i++;
		}	
	}
	write(1, "\n", 1);
}