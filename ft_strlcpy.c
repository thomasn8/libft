/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:12 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 19:10:21 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int 	i;
	size_t 	src_length;
	
	src_length = 0;
	while (src[src_length])
		src_length++;
	i = src_length;
	dst[dstsize] = 0;
	if(dstsize)
		dstsize--;
	while (i-- && dstsize--)
	{
		*dst++ = *src++;
	}
	return (src_length);
}

// If the src and dst strings overlap, the behavior is undefined.

// recopie toute la chaîne pointée par src vers la destination dest jusqu'à ce qu'elle rencontre le zéro '\0'
// ne contrôle absolument pas la taille du buffer de destination, et le tout se termine en buffer overflow si jamais ça dépasse
// prennent la pleine taille du tampon de destination => avec sizeof()
// dstsize comprend le \0 de fin : chars + 0
// retourne la taille 
// exemple : (void)strlcpy(buf, s, sizeof(buf));
// n est égal à la taille du buffer de destination

/*
strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0.

strlcpy() et strlcat() prennent la pleine taille du tampon de destination et garantissent la terminaison NUL s'il y a de la place. Notez que la place pour le NUL doit être incluse dans dstsize. 

If the src and dst strings overlap, the behavior is undefined.

strlcpy() and strlcat() functions return the total
length of the string they tried to create.  For strlcpy() that means the
length of src.  For strlcat() that means the initial length of dst plus
the length of src.

If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.
*/