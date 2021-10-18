/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:44:55 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/18 15:06:03 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char **ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**tab;
	int		words;
	int		word;
	int		letter;

	i = 0;
	start = 0;
	end = 0;
	tab = NULL;
	words = 0;
	if (!s)
		return (tab);
	while (s[i] || (i = 0))
	{
		while (s[i] == c)
			++i;
		start = i;
		printf("Start of new string : s[%d]: %c\n",start, s[start]);
		while (s[i] != c && s[i])
			i++;
		end = i;
		words++;
		printf("End of string : s[%d]: %c\n",end, s[end]);
	}

	printf("\nWords count: %d\n", words);
	tab = malloc(words * sizeof(char *) + 1);
	if(!tab)
		return (NULL);
	tab[words] = 0;
	printf("Pointer on tab : %p\n\n", tab);

	
	i = 0;
	start = 0;
	end = 0;
	word = 0;
	letter = 0;
	while (s[i] || (i = 0))
	{
		while (s[i] == c)
			++i;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;

		printf("Malloc size : %d\n", (end - start + 1));
		tab[word] = malloc((end - start) * sizeof(char) + 1);
		if(!tab[word])
			return (NULL);
		while (start < end)
			tab[word][letter++] = s[start++];
		tab[word][letter] = 0;
		printf("Str[%d] starts at pointer %p\n", word, tab[word]);
		word++;
		letter = 0;
	}

	return (tab);
}

// tab[j] = malloc((end - start) * sizeof(char) + 1);
// if (!tab[j])
// 	return (NULL);
// if (j == 0)
// 	tab = &tab[j];
// printf("Pointer on new string : %p\n", tab[j]);
// while (start < end)
// 	tab[j][k++] = s[start++];
// tab[j][k] = 0;
// // printf("End of string : %p\n", &tab[j][k]);
// j++;

// #1. La chaine de caractères à découper.
// #2. Le caractère délimitant.

// Le tableau de nouvelles chaines de caractères résultant du découpage.
// NULL si l’allocation échoue.
// Le tableau doit être terminé par NULL.