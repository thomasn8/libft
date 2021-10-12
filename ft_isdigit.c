#include "ft_isdigit.h"

// needs - '0' to convert int digit in ascii code
int	ft_isdigit(int c)
{
	c = c - '0';
	if (c >= 0 && c <= 9)
		return (1);
	return (0);
}