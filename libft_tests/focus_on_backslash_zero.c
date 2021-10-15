/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focuson_backslash_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:04:01 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/16 00:29:01 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	focus_on_backslash_zero(char *string, size_t limit)
{
	int	i;

	// size_t	limit_copy;
	// i = 0;
	// limit_copy = limit;
	// printf("String before :\n");
	// while (limit_copy--)
	// {
	// 	printf("[%d]: %c\n", i, string[i]);
	// 	i++;
	// }

	i = -1;
	printf("String after :\n");
	while (limit--)
	{
		if (string[++i] == 0)
			string[i] = '_';
		printf("[%d]: %c\n", i, string[i]);
	}
	return (0);
}
