/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:55:05 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/04 16:44:20 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_data
{
    void       *data;
    char        conv_spec;
    int         width;
    int         precision;
    int         displayed;
}               t_data;

void    ft_putchar_n(char c, t_data *data)
{
    write(1, &c, 1);
    data->displayed++;
}

long long ft_putnbr(char *str, t_data *data)
{
    (void)str;
    (void)data;
    return (0);
}


void    ft_parse(const char *str, t_data *data, va_list *va)
{
    int i;

    i = -1;
    while (str[++i])
    {
        while (str[i] && str[i] != '%')
            i++;
        if (str[i] == '%')
            i++;
        if (str[i] == 's')
        {
            data->conv_spec = 's';
            data->data = va_arg(*va, char *);
        }
        else if (str[i] == 'd')
        {
            data->conv_spec = 'd';
            data->data = (void *)va_arg(*va, long long);
        }
        else if (str[i] == 'x')
        {
            data->conv_spec = 'x';
            data->data = (void *)va_arg(*va, long long);
        }
        printf("conv_spec = %c et data = %lli", data->conv_spec, (long long)data->data);
        ft_display(data);
    }
}

int		ft_printf(const char *str, ...)
{
    va_list va;
    t_data  data;

    va_start(va, str);
    ft_parse(str, &data, &va);
    va_end(va);
    return (data.displayed);
}

int main(int ac, char **av)
{
    (void)ac;
    printf("\ndisplayed: %i", ft_printf(av[1], atoi(av[2])));
    return (0);
}