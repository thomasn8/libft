/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:40:15 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:26 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static int	n_len(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*is_exception(int n)
{
	char	*nbr;
	int		i;

	i = 10;
	nbr = NULL;
	if (n == 0)
	{
		nbr = malloc(1 * sizeof(char) + 1);
		*nbr = '0';
		*(nbr + 1) = 0;
		return (nbr);
	}
	nbr = malloc(11 * sizeof(char) + 1);
	if (!nbr)
		return (NULL);
	nbr[0] = '-';
	nbr[11] = 0;
	nbr[10] = '8';
	n = 214748364;
	while (--i > 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	if (n != 0 && n != -2147483648)
	{
		len = n_len(n);
		nbr = malloc(len * sizeof(char) + 1);
		if (!nbr)
			return (NULL);
		if (n < 0)
		{	
			n *= -1;
			nbr[0] = '-';
		}
		nbr[len] = 0;
		while (len-- && n > 0)
		{
			nbr[len] = n % 10 + '0';
			n /= 10;
		}
		return (nbr);
	}
	nbr = is_exception(n);
	return (nbr);
}
