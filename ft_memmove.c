/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:11:21 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/21 12:06:45 by tnanchen         ###   ########.fr       */
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
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}

// Difference with memcpy :
// To obtain all the copy in dest in case of OVERLAP 
// (pas que src s'écrase avant d'être copié) :
// Utiliser des variables temp
//
// si dest_src > src_src		==>		copy from front to back
// [---- src ----]
//         [---- dst ---]
//
// si src_src > dest_src		==>		copy from back to front
// [---- dst ----]
//         [---- src ---]
// https://stackoverflow.com/questions/1201319/
// what-is-the-difference-between-memmove-and-memcpy
