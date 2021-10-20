/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:44:55 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/18 17:11:42 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static int	words_count(char const *s, char c)
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
		printf("Start 1st while at [%d]\n", i);
		while (s[i] == c)
		{
			i++;
		}
		start = i;
		// printf("First letter (%d of s) of word %d : %c\n", start, words, s[start]);
		while (s[i] != c && s[i])
		{
			i++;
		}
		end = i;
		// printf("Last letter (%d of s) of word %d : %c\n", end, words, s[end-1]);
		if (s[start] != 0)		
			words++;
		// printf("%d words\n", words);
	}
	printf("Nombre final de words : %d\n", words);
	return (words);
}

static int	words_alloc(char **tab, char const *s, char c, int i)
{
	int	start;
	int	end;
	int	word;

	start = 0;
	end = 0;
	word = 0;
	while (s[i] || (i == 0))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		tab[word] = malloc((end - start) * sizeof(char) + 1);
		printf("Malloc size (%d): %d\n", word, (end - start + 1));
		if (!tab)
			return (0);
		word++;
	}
	// printf("start : %d / %c\n", start, s[start]);
	// printf("end : %d/%c\n", end, s[end]);
	// printf("i : %d/%c\n", i, s[i]);
	if (start != end)
	{
		tab[word] = malloc(1 * sizeof(char));
		printf("Malloc size (%d): %d\n", word, 1);
	}
	return (1);
}

static void	words_split(char **tab, char const *s, char c, int i)
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
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		while (start < end)
			tab[word][letter++] = s[start++];
		tab[word][letter] = 0;
		printf("word %d : %s\n", word, tab[word]);
		word++;
		letter = 0;
	}
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
	printf("Tab malloc size pour %d mot(s) : %lu\n",words+1, (words * sizeof(char *) + 1));
	tab[words] = NULL;
	printf("tab : %p\n", tab);
	printf("tab[0] : %p | Val : ", tab[0]);
	printf("%s\n", tab[0]);
	printf("tab[1] : %p | Val : ", tab[1]);
	printf("%s\n", tab[1]);
	printf("tab[2] : %p | Val : ", tab[2]);
	printf("%s\n", tab[2]);
	if ((words_alloc(tab, s, c, i)) == 0)
		return (NULL);
	printf("tab : %p\n", tab);
	printf("tab[0] : %p | Val : ", tab[0]);
	printf("%s\n", tab[0]);
	printf("tab[1] : %p | Val : ", tab[1]);
	printf("%s\n", tab[1]);
	printf("tab[2] : %p | Val : ", tab[2]);
	printf("%s\n", tab[2]);
	words_split(tab, s, c, i);
	printf("tab : %p\n", tab);
	printf("tab[0] : %p | Val : ", tab[0]);
	printf("%s\n", tab[0]);
	printf("tab[1] : %p | Val : ", tab[1]);
	printf("%s\n", tab[1]);
	printf("tab[2] : %p | Val : ", tab[2]);
	printf("%s\n", tab[2]);
	return (tab);
}
