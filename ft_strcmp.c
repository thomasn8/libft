/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:11:45 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/15 21:03:22 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	int cmp;

	i = 0;
	while (*s1 == *s2 && *s1 && n--)
	{
		s1++;
		s2++;
		i++;
	}
	cmp = *s1 - *s2;
	return (cmp);
}
