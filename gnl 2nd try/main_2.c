/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:35:18 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 13:42:10 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	int ret;
	int i;
	char *line;
	
	i = 0;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("\nline %i - [%s] - ret = %i\n", i, line, ret);
		free(line);
		line = NULL;
	}
	printf("\nline %i - [%s] - ret = %i\n", i, line, ret);
	free(line);
	line = NULL;
}
