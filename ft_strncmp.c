/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:11:45 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/19 20:08:38 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	cmp;

	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && --n)
	{
		s1++;
		s2++;
	}
	cmp = *s1 - *s2;
	return (cmp);
}
