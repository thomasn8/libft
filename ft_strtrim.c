/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:26:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/20 18:18:40 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static int	get_start(char const *s1, char const *set, int len)
{
	int	start;
	int	i;
	int	j;

	start = 0;
	j = -1;
	i = 0;
	while (set[++j] && len)
	{
		if (set[j] == s1[i])
		{
			start++;
			i++;
			j = -1;
			len--;
		}
	}
	return (start);
}

static int	get_end(char const *s1, char const *set, int len)
{
	int	j;

	len--;
	j = -1;
	while (set[++j])
	{
		if (set[j] == s1[len])
		{
			len--;
			j = -1;
		}
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		len;
	int		start;
	int		end;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	start = get_start(s1, set, len);
	if(start >= len)
		return (NULL);
	end = get_end(s1, set, len);
	len = end - start + 1;
	if(len <= 0)
		return (NULL);
	strtrim = malloc(len * sizeof(char) + 1);
	if (!strtrim)
		return (NULL);
	strtrim[len] = 0;
	while (len--)
		strtrim[i++] = s1[start++];
	return (strtrim);
}
