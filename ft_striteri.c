/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:29:44 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/19 10:57:42 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

// Modifie une chaine de char en mémoire
// en lui appliquant une fonction donnée

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !(*s))
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
	return ;
}
