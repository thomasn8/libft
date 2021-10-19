/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:12 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/19 20:27:50 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;

	src_length = 0;
	while (src[src_length])
		src_length++;
	i = src_length;
	if (dstsize)
		dstsize--;
	dst[dstsize] = 0;
	while (i-- && dstsize--)
		*dst++ = *src++;
	return (src_length);
}

/*
strlcpy() take the full size of the destination buffer and
guarantee NUL-termination if there is room.  
Note that room for the NUL should be included in dstsize.

strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0.

strlcpy() return the total length of the string it tried to create.  
For strlcpy() that means the length of src.
*/