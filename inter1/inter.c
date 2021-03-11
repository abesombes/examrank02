/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:48:58 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/04 11:19:46 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_check_if_dup_char(char *str, char c, int index)
{
    int k;
    k = 0;
    while (str[k] && k < index)
    {  
        if (str[k] == c)
            break ;
        k++;
    }
    if (k < index)
        return (0);
    return (1);
}

int   main(int ac, char **av)
{
    int i;
    int j;
    char *str1;
    char *str2;

    i = -1;
    if (ac == 3)
    {
        str1 = av[1];
        str2 = av[2];
        while (str1[++i])
        {
            j = 0;
            while (str2[j])
            {
                if (str1[i] == str2[j])
                    break ;
                j++;
            }
            if (ft_check_if_dup_char(str1, str1[i], i))
                write(1, &str1[i], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}