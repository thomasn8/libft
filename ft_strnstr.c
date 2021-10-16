/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:26:20 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/16 13:45:50 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static char	*str_in_str(const char *haystack, const char *needle, size_t len)
{
	int		prev_match;
	size_t	i;
	size_t	j;

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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str_search;

	if (*needle == 0)
		return ((char *) haystack);
	str_search = str_in_str(haystack, needle, len);
	if (str_search)
		return (str_search);
	return (NULL);
}
