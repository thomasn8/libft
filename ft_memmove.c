/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:11:21 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 12:55:04 by tnanchen         ###   ########.fr       */
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

void 	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr;
	char		*temp;
	int			copy_length;

	ptr = src;
	temp = dest;
	copy_length = n;

	printf("%d\n",&dest);
	printf("%d\n",&src);
	
	if (&dest > &src)
	{
		while(n--)
			temp[n] = ptr[n];			// copy from front to back
		temp[copy_length + 1] = 0;
		return (dest);
	}
	n = copy_length;
	while (n--)
		*temp++ = *ptr++;				// copy from back to front
	*temp++ = 0;
	return (dest);
}

// explainations :
// https://stackoverflow.com/questions/1201319/what-is-the-difference-between-memmove-and-memcpy

/*
The memmove() function copies n bytes from memory area src to
memory area dest.  The memory areas may overlap: copying takes
place as though the bytes in src are first copied into a
temporary array that does not overlap src or dest,
and the bytes are then copied from the temporary array to dest.
*/
