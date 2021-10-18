/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:40:15 by tnanchen          #+#    #+#             */
/*   Updated: 2021/10/18 21:24:25 by tnanchen         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
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
