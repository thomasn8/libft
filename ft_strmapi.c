/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 08:57:54 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/19 10:58:09 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

// Créer une nouvelle chaine de char 
// sur la base d'une chaine donnée (sans modifier cette chaine !) 
// en lui appliquant une fonction donnée

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	size_t	len;
	size_t	i;

	strmapi = NULL;
	if (!s)
		return (strmapi);
	len = 0;
	while (s[len])
		len++;
	strmapi = malloc(len * sizeof(char) + 1);
	if (!strmapi)
		return (NULL);
	strmapi[len] = 0;
	i = -1;
	while (s[++i])
		strmapi[i] = f(i, s[i]);
	return (strmapi);
}