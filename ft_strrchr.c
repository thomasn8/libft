/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:19:02 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/15 18:34:50 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	len *= sizeof(char);
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	s = s + length;
	while (length--)
	{
		if (*s == c)
			return ((char *) s);
		s--;
	}
	if (c == 0 && *s == 0)
		return ((char *) s);
	return (NULL);
}
