/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:29:44 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/19 16:41:04 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

// Modifie une chaine de char en mémoire
// en lui appliquant une fonction donnée

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !(*s))
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
	return ;
}
