/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:11:21 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/21 19:36:03 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (dst != NULL || src != NULL)
	{
		if (d > s)
		{
			while (n--)
				d[n] = s[n];
		}
		else
		{
			while (n--)
				*d++ = *s++;
		}
	}
	return (dst);
}
