/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:23:40 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/04 11:55:04 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_char_appears_before(char *str1, char *str2, char c, int index)
{
    int i;
    int j;

    if (str2)
    {
        i = -1;
        while (str1[++i])
            if (str1[i] == c)
                return (1) ;
        j = -1;
        while (str2[++j] && j < index)
            if (str2[j] == c)
                return (1);
    } 
    else 
    {
        i = -1;
        while (str1[++i] && i < index)
            if (str1[i] == c)
                return (1) ;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i;

    if (ac == 3)
    {
        i = -1;
        while (av[1][++i])
            if (!ft_char_appears_before(av[1], NULL, av[1][i], i))
                write(1, &av[1][i], 1);
        i = -1;
        while (av[2][++i])
            if (!ft_char_appears_before(av[1], av[2], av[2][i], i))
                write(1, &av[2][i], 1);
    }
    write(1, "\n", 1);
}