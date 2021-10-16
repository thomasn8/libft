/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:50:28 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/16 15:45:41 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char 	*dup;
	int 	i;

	len = 0;
	i = -1;
	while (s1[len])
		len++;
	dup = (char *)malloc(len * sizeof(char));
	if(!dup)
		return (NULL);
	while (s1[++i])
		dup[i] = s1[i];
	dup[i] = 0;
	return (dup);
}
