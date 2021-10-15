/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:15 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/15 18:39:01 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		n;
	size_t	src_length;
	size_t	dst_length;
	int		src_length_cpy;

	src_length = 0;
	while (src[src_length])
		src_length++;
	dst_length = 0;
	while (dst[dst_length])
		dst_length++;
	src_length_cpy = src_length;
	if (dstsize > dst_length)
	{	
		dst[dstsize] = 0;
		i = dst_length;
		n = dstsize - dst_length - 1;
		while (n-- && src_length--)
			dst[i++] = *src++;
	}
	if (dstsize > dst_length)
		return (dst_length + src_length_cpy);
	return (dstsize + src_length);
}
