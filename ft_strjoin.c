/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:15:31 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/22 13:54:51 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = 0;
	len_s2 = 0;
	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	strjoin = malloc((len_s1 + len_s2) * sizeof(char) + 1);
	if (!strjoin)
		return (NULL);
	while (++i < len_s1)
		strjoin[i] = s1[i];
	while (++j < len_s2)
		strjoin[i++] = s2[j];
	strjoin[i] = 0;
	return (strjoin);
}
