/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:55:05 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/04 23:19:35 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_flags
{
	int         i;
	int         len;
	int         width;
	int         has_precision;
	int         negative;
	int			zero_count;
	int         precision;
	int         displayed;
	va_list     arg;
}               t_flags;

void    ft_putchar_n(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->displayed++;
}

void    ft_init_flags(t_flags *flags)
{
	flags->i = 0;
	flags->displayed = 0;
	flags->len = 0;
	flags->width = 0;
	flags->has_precision = 0;
	flags->negative = 0;
	flags->precision = 0;
	flags->displayed = 0;	
	flags->zero_count = 0;
}

void    ft_print_until(const char *str, char c, t_flags *flags)
{
	while (str[flags->i] && str[flags->i] != c)
	{
		ft_putchar_n(str[flags->i], flags);
		flags->i++;
	}
}

int		ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void    ft_discover_flags(const char *str, t_flags *flags)
{
	flags->i++;
	if (ft_is_num(str[flags->i]))
	{
		while (ft_is_num(str[flags->i]))
		{
			flags->width = flags->width * 10 + str[flags->i] - 48.0;
			flags->i++;
		}
	}
	if (str[flags->i] == '.')
	{
		flags->has_precision = 1;
		flags->i++;
		while (ft_is_num(str[flags->i]))
		{
			flags->precision = flags->precision * 10 + str[flags->i] - 48.0;
			flags->i++;
		}
	}
//	printf("\nwidth: [%i] - precision: [%i]", flags->width, flags->precision);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long nb, int base_len, char *base, t_flags *flags)
{
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base_len, base, flags);
		ft_putnbr_base(nb % base_len, base_len, base, flags);
	}
	else 
		ft_putchar_n(base[nb], flags);
}

void	ft_putstr(char *s, int len, t_flags *flags)
{
	int j;
	
	j = 0;
	while (s[j] && j < len)
		ft_putchar_n(s[j++], flags);
}

void	ft_print_x_chars(int nb, char c, t_flags **flags)
{
	while (nb > 0)
	{
		ft_putchar_n(c, *flags);
		nb--;
	}
}

void 	ft_print_s(t_flags *flags)
{
	char *s;

	flags->i++;
	s = va_arg(flags->arg, char *);
	if (!s)
		s = "(null)";
	flags->len = ft_strlen(s);
	if (flags->has_precision && flags->precision < flags->len)
		flags->len = flags->precision;
	ft_print_x_chars(flags->width - flags->precision, ' ', &flags);
	ft_putstr(s, flags->len, flags);
}

int		ft_longlen_base(long nb, int base_len)
{
	int i;

	i = 0;
	while (nb >= base_len)
	{
		nb = nb / base_len;
		i++;
	}
	i++;
	return (i);
}

void	ft_print_x(t_flags *flags)
{
	unsigned int nb;

	flags->i++;
	nb = va_arg(flags->arg, unsigned int);
	flags->len = ft_longlen_base(nb, 16);
	if (flags->has_precision && nb == 0)
		flags->len = 0;
	if (flags->has_precision && flags->precision > flags->len)
		flags->zero_count = flags->precision - flags->len;
	ft_print_x_chars(flags->width - flags->len - flags->zero_count, ' ', &flags);
	ft_print_x_chars(flags->zero_count, '0', &flags);
	if (flags->has_precision && nb == 0)
		return ;
	ft_putnbr_base(nb, 16, "0123456789abcdef", flags);
}

int     ft_printf(const char *str, ...)
{
	t_flags flags;
	
	ft_init_flags(&flags);
	va_start(flags.arg, str);
	while (str[flags.i])
	{
		ft_print_until(str, '%', &flags);
		if (str[flags.i])
		{
			ft_discover_flags(str, &flags);
			if (str[flags.i] == 's')
				ft_print_s(&flags);
			/*else if (str[flags.i] == 'd')
				ft_print_d(&flags);*/
			else if (str[flags.i] == 'x')
				ft_print_x(&flags);
		}
	}
	va_end(flags.arg);
	return (flags.displayed);
}

int     main(void)
{
	//printf(" - i: %i", ft_printf("test"));
	ft_printf("MINE: hello [%10.x]", 0);
	printf("\nREAL: hello [%10.x]", 0);
	return (0);
}