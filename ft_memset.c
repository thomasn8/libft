/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:28:13 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 01:12:37 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

// S is a pointer to fulfill 
// ! VOID pointer, so that we can pass any type of pointer to this function
// C is the value to fill in S
// N is the amount of bytes (corresponding to unsigned char) from S to fill

// we need to specify a type to modify the pointer
// we can do that creating a copy of the pointer with the type.
// incrementing the pointer position one by one, 
// *p++ will modify the values pointed by the copy pointer
// and then we can return the original pointer
