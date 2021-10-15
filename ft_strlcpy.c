/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:12 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/15 18:41:34 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
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
