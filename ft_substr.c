/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:14:28 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/17 23:14:23 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

// KO.3 KO.9
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			j++;					// taille du malloc
		i++;
	}
	substr = malloc(j * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	substr[j] = 0;
	while (j--)
		substr[j] = s[j];
	return (substr);
}

// KO.5
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;
// 	size_t	s_len;
// 	
// 
// 
// 	s_len = start;
// 	while(s[s_len] && len--)
// 		s_len++;
// 	s_len -= start;
// 	substr = malloc(s_len * sizeof(char) + 1);
// 	if (!substr)
// 		return (NULL);
// 	i = -1;
// 	while (++i < s_len)
// 		substr[i] = s[start + i];
// 	substr[i] = 0;
// 	return (substr);
// }
