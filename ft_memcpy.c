/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:08:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 01:05:05 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*ptr;
	char		*temp;

	ptr = src;
	temp = dest;
	while (n--)
		*temp++ = *ptr++;
	*temp++ = 0;
	return (dest);
}

/*
The memcpy() function copies n bytes 
from memory area src 
to memory area dest.  

The memory areas must not overlap.  									!!!! COMMENT SAVOIR !!!!?
Use memmove(3) if the memory areas do overlap.

The memcpy() function returns a pointer to dest.
*/

/*
The memmove() function copies n bytes from memory area src to
memory area dest.  The memory areas may overlap: copying takes
place as though the bytes in src are first copied into a
temporary array that does not overlap src or dest, 						!!!! COMMENT FAIRE !!!!?
and the bytes are then copied from the temporary array to dest.
*/
