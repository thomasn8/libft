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

static int	words_count(const char *str, char c)
{
	int i;
	int switcher;

	i = 0;
	switcher = 0;
	while (*str)
	{
		if (*str != c && switcher == 0)
		{
			switcher = 1;
			i++;
		}
		else if (*str == c)
			switcher = 0;
		str++;
	}
	return (i);
}

static int	words_alloc(char **tab, char const *s, char c, int i)
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
		tab[word] = malloc((end - start) * sizeof(char) + 1);
		while (start < end)
			tab[word][letter++] = s[start++];
		tab[word][letter] = 0;
		letter = 0;
		word++;
	}
	if (start != end)
		tab[word] = malloc(1 * sizeof(char));
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	words = words_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!s || !tab)
		return (NULL);
	i = 0;
	if ((words_alloc(tab, s, c, i)) == 0)
		return (NULL);
	// words_split(tab, s, c, i);
	tab[words] = NULL;
	return (tab);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN FUNCTION WITH PRINTF TO DEBUG

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		words;
// 	int		i;

// 	words = words_count(s, c);
// 	tab = malloc((words + 1) * sizeof(char *));
// 	if (!s || !tab)
// 		return (0);
// 	printf("Tab malloc size pour %d mot(s) : %lu\n",words+1, (words * sizeof(char *) + 1));
// 	printf("tab : %p\n", tab);
// 	printf("tab[0] : %p | Val : ", tab[0]);
// 	printf("%s\n", tab[0]);
// 	printf("tab[1] : %p | Val : ", tab[1]);
// 	printf("%s\n", tab[1]);
// 	printf("tab[2] : %p | Val : ", tab[2]);
// 	printf("%s\n", tab[2]);
// 	i = 0;
// 	if ((words_alloc(tab, s, c, i)) == 0)
// 		return (0);
// 	printf("tab : %p\n", tab);
// 	printf("tab[0] : %p | Val : ", tab[0]);
// 	printf("%s\n", tab[0]);
// 	printf("tab[1] : %p | Val : ", tab[1]);
// 	printf("%s\n", tab[1]);
// 	printf("tab[2] : %p | Val : ", tab[2]);
// 	printf("%s\n", tab[2]);
// 	words_split(tab, s, c, i);
// 	tab[words] = NULL;
// 	printf("tab : %p\n", tab);
// 	printf("tab[0] : %p | Val : ", tab[0]);
// 	printf("%s\n", tab[0]);
// 	printf("tab[1] : %p | Val : ", tab[1]);
// 	printf("%s\n", tab[1]);
// 	printf("tab[2] : %p | Val : ", tab[2]);
// 	printf("%s\n", tab[2]);
// 	return (tab);
// }

////////////////////////////////////////////////////////////////////////////////////////////////
// FT_SPLIT WORKING

// size_t	strlen(const char *s)
// {
// 	size_t	l;

// 	l = 0;
// 	while (s[l])
// 		l++;
// 	return (l);
// }
// static int	count_words(const char *str, char c)
// {
// 	int i;
// 	int trigger;

// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(const char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	while (start < finish)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char		**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**split;

// 	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	index = -1;
// 	while (i <= strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == strlen(s)) && index >= 0)
// 		{
// 			split[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 		i++;
// 	}
// 	split[j] = 0;
// 	return (split);
// }
