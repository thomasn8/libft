/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:08:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 12:54:24 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

// To obtain all the copy in dest in case of OVERLAP (pas que src soit ecrase avant la copie) :
//
// si dest_ptr > src_ptr		==>		copy from front to back
// [---- src ----]
//         [---- dst ---]
//
// si src_ptr > dest_ptr		==>		copy from back to front
// [---- dst ----]
//         [---- src ---]

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

// explainations :
// https://stackoverflow.com/questions/1201319/what-is-the-difference-between-memmove-and-memcpy
