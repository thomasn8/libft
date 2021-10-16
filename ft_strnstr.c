/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:26:20 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/16 13:32:10 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		prev_match;
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *) haystack);
	prev_match = 0;
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			prev_match = i;
			while (haystack[i] == needle[j] || needle[j] == 0)
			{
				if (needle[j] == 0)
					return ((char *) &haystack[prev_match]);
				i++;
				j++;
			}
			i = prev_match;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
