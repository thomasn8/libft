/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:05:16 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/19 18:50:33 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	u_c;

	u_c = c;
	while (n--)
	{
		if (*(char *)s == u_c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
