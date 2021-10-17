/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:51:33 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/17 20:34:37 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (++i < (count * size))
		ptr[i] = 0;
	return ((void *) ptr);
}
