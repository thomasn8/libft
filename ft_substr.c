/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:14:28 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/22 13:57:53 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			j++;
		i++;
	}
	substr = malloc(j * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	substr[j] = 0;
	i = 0;
	while (i < j)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
