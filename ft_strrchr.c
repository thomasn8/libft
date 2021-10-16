/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:19:02 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/16 15:09:10 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	s = s + len;
	while (len--)
	{
		if (*s == c)
			return ((char *) s);
		s--;
	}
	if (c == 0 && *s == 0)
		return ((char *) s);
	return (NULL);
}
