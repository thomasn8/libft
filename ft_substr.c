/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:14:28 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/17 23:14:23 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = -1;
	substr = malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = s[start + i];
	substr[i] = 0;
	return (substr);
}
