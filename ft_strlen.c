/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:26:58 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/13 13:29:11 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlen() function calculates the length of the string pointed
to by s, excluding the terminating null byte ('\0').

The strlen() function returns the number of bytes in the string
pointed to by s.
*/
#include "ft_strlen.h"

size_t ft_strlen(const char *s)
{
	int		i;
	size_t 	len;

	i = 0;
	while (s[i])
		i++;
	len = i * sizeof(char);
	return (len);
}
