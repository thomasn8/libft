/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:12 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 23:02:31 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int 	i;
	size_t 	src_length;
	
	src_length = 0;
	while (src[src_length])
		src_length++;				// src_length = length of src string (until 1st \0)
	i = src_length;					// i = copy of src_length
	if(dstsize)						// si dst > 0
		dstsize--;					// dstsize -1 to get last index (due to index 0)	
	dst[dstsize] = 0;				// put \0 at the end (arbitrary last pos) of dst 
	while (i-- && dstsize--)		// tant que src string n'est pas terminée && qu'on a pas atteint dstsize
		*dst++ = *src++;			// copie src dans dst
	return (src_length);			// retourne la longueur de la string (peu importe dstsize)
}

// If the src and dst strings overlap, the behavior is undefined.
// If the return value is >= dstsize, the output string has been truncated.
// It is the caller's responsibility to handle this.
