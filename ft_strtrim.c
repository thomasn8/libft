/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:26:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/18 23:16:56 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static int	slen(char const *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len - 1);
}

static int	trim_start_count(char const *s1, char const *set)
{
	int	trim_start;
	int	i;
	int	j;

	trim_start = 0;
	j = -1;
	i = 0;
	while (set[++j])
	{
		if (set[j] == s1[i])
		{
			trim_start++;
			i++;
			j = -1;
		}
	}
	return (trim_start);
}

static int	trim_end_count(char const *s1, char const *set, int len)
{
	int	trim_end;
	int	j;

	trim_end = 0;
	j = -1;
	while (set[++j])
	{
		if (set[j] == s1[len])
		{
			trim_end++;
			len--;
			j = -1;
		}
	}
	return (trim_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		len;
	int		trim_start;
	int		trim_end;
	int		i;

	strtrim = NULL;
	len = slen(s1);
	trim_start = trim_start_count(s1, set);
	trim_end = trim_end_count(s1, set, len);
	strtrim = malloc((len - trim_start - trim_end) * sizeof(char) + 1);
	if (! strtrim)
		return (NULL);
	i = -1;
	len = len - trim_start - trim_end + 1;
	while (++i < len)
		strtrim[i] = s1[trim_start++];
	strtrim[i] = 0;
	return (strtrim);
}
