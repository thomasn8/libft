/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:44:55 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/18 16:05:12 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int	words_count(char const *s, char c)
{
	int	i;
	int	start;
	int	end;
	int	words;

	i = 0;
	start = 0;
	end = 0;
	words = 0;
	if (!s)
		return (0);
	if (!c)
		return (1);
	while (s[i] || (i == 0))
	{
		while (s[i] == c)
			++i;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		words++;
	}
	return (words);
}

int	words_split(char **tab, char const *s, char c, int i)
{
	int	start;
	int	end;
	int	word;
	int	letter;

	start = 0;
	end = 0;
	word = 0;
	letter = 0;
	while (s[i] || (i == 0))
	{
		while (s[i] == c)
			++i;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		tab[word] = malloc((end - start) * sizeof(char) + 1);
		if (!tab)
			return (0);
		while (start < end)
			tab[word][letter++] = s[start++];
		tab[word][letter] = 0;
		word++;
		letter = 0;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	words = words_count(s, c);
	if (!words)
		return (NULL);
	tab = malloc(words * sizeof(char *) + 1);
	if (!tab)
		return (NULL);
	if ((words_split(tab, s, c, i)) == 0)
		return (NULL);
	return (tab);
}
