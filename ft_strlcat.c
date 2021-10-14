/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:14:15 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 16:57:50 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
	
// }

/*
strlcpy() et strlcat() prennent la pleine taille du tampon de destination et garantissent la terminaison NUL s'il y a de la place. Notez que la place pour le NUL doit être incluse dans dstsize. 

strlcat() appends string src to the end of dst.  It will append at most
dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
dstsize is 0 or the original dst string was longer than dstsize (in prac-
tice this should not happen as it means that either dstsize is incorrect
or that dst is not a proper string).

If the src and dst strings overlap, the behavior is undefined.

strlcpy() and strlcat() functions return the total
length of the string they tried to create.  For strlcpy() that means the
length of src.  For strlcat() that means the initial length of dst plus
the length of src.

If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.
*/