/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:11:21 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 23:57:14 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void 	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*ptr;
	char		*temp;

	ptr = src;
	temp = dst;
	if (dst > src)
	{
		temp[n + 1] = 0;
		while(n--)
			temp[n] = ptr[n];			// copy from front to back
		return (dst);
	}
	while (n--)
		*temp++ = *ptr++;				// copy from back to front
	*temp++ = 0;
	return (dst);
}

// Difference with memcpy :
// To obtain all the copy in dest in case of OVERLAP (pas que src soit ecrase avant la copie) :
//
// si dest_ptr > src_ptr		==>		copy from front to back
// [---- src ----]
//         [---- dst ---]
//
// si src_ptr > dest_ptr		==>		copy from back to front
// [---- dst ----]
//         [---- src ---]
// https://stackoverflow.com/questions/1201319/what-is-the-difference-between-memmove-and-memcpy
