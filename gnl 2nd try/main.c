/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:35:18 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 09:01:01 by abesombe         ###   ########.fr       */
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
		printf("\nline %i - [%s] - ret = %i", i, line, ret);
		free(line);
		line = NULL;
	}
	printf("\nline %i - [%s] - ret = %i", i, line, ret);
	free(line);
	line = NULL;
}
