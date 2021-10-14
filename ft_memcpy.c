/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:08:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/14 23:56:51 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

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
