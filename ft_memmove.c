/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:11:21 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 01:12:22 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void 	*ft_memmove(void *dest, const void *src, size_t n)
{
	
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
