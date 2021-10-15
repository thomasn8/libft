/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:05:16 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/15 21:26:48 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *ptr;

	ptr = s;
	while (*ptr != 0 && n--)
	{
		if (*ptr == c)
			return ((void *) ptr);
		ptr++;
	}
	if (c == 0 && *ptr == 0)
		return ((void *) ptr);
	return (NULL);
}
