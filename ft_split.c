/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:44:55 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/21 23:55:52 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static int	words_count(const char *str, char c)
{
	int	i;
	int	switcher;

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

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 2) * sizeof(char));
	while (start <= end)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

static int	words_split(char **tab, char const *s, char c)
{
	int	i;
	int	start;
	int	end;
	int	word;

	i = 0;
	start = 0;
	end = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (!s[i] && start == end && word > 0)
		{
			tab[word] = malloc(1 * sizeof(char));
			return (1);
		}
		tab[word++] = word_dup(s, start, end - 1);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (0);
	words = words_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (0);
	if (!(words_split(tab, s, c)))
	{
		free(tab);
		return (NULL);
	}
	tab[words] = NULL;
	return (tab);
}

/*
//////////////////////////////////////
SPLIT CORE FUNCTION WITH PRINTF 
FOR CHECKING MEMORY AND DEBUGGING

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	words = words_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!s || !tab)
		return (0);
	printf("Tab malloc size pour %d mot(s) : %lu\n",
	words+1, (words * sizeof(char *) + 1));
	printf("tab : %p\n", tab);
	printf("tab[0] : %p | Val : ", tab[0]);
	printf("%s\n", tab[0]);
	printf("tab[1] : %p | Val : ", tab[1]);
	printf("%s\n", tab[1]);
	printf("tab[2] : %p | Val : ", tab[2]);
	printf("%s\n", tab[2]);
	i = 0;
	if ((words_alloc(tab, s, c, i)) == 0)
		return (0);
	printf("tab : %p\n", tab);
	printf("tab[0] : %p | Val : ", tab[0]);
	printf("%s\n", tab[0]);
	printf("tab[1] : %p | Val : ", tab[1]);
	printf("%s\n", tab[1]);
	printf("tab[2] : %p | Val : ", tab[2]);
	printf("%s\n", tab[2]);
	words_split(tab, s, c, i);
	tab[words] = NULL;
	printf("tab : %p\n", tab);
	printf("tab[0] : %p | Val : ", tab[0]);
	printf("%s\n", tab[0]);
	printf("tab[1] : %p | Val : ", tab[1]);
	printf("%s\n", tab[1]);
	printf("tab[2] : %p | Val : ", tab[2]);
	printf("%s\n", tab[2]);
	return (tab);
}
*/
/*
////////////////////////////////////// 
PREV FT_SPLIT
size_t	strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	switcher;

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

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**tab;

	if (!s)
		return (0);
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			tab[j++] = word_dup(s, index, i);
			index = -1;
		}
	}
	tab[j] = 0;
	return (tab);
}
*/
