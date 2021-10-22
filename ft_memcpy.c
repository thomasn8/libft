/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:08:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/22 13:52:07 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_dst;
	char	*ptr_src;

	ptr_dst = dst;
	ptr_src = (char *)src;
	if (dst != NULL || src != NULL)
	{
		while (n--)
			*ptr_dst++ = *ptr_src++;
	}
	return (dst);
}
