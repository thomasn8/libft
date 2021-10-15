/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:58:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/15 23:45:45 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ptr1;
	const char	*ptr2;
	int 		i;
	int 		cmp;

	if (n == 0)
		return (0);
	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (*ptr1 == *ptr2 && --n)
	{
		ptr1++;
		ptr2++;
		i++;
	}
	cmp = *ptr1 - *ptr2;
	if (cmp == 0)
		return (0);
	return (cmp);
}

/*
The memcmp() function compares byte string s1 against byte string s2.  Both
strings are assumed to be n bytes long.

The memcmp() function returns zero if the two strings are identical, other-
wise returns the difference between the first two differing bytes (treated
as unsigned char values, so that `\200' is greater than `\0', for example).
Zero-length strings are always identical.  This behavior is not required by
C and portable code should only depend on the sign of the returned value.
*/