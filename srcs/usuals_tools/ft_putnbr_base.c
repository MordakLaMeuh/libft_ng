/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:09:28 by bmickael          #+#    #+#             */
/*   Updated: 2017/04/10 17:13:14 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern void putchar(char c);

void		ft_putnbr_base(int n, int base)
{
	int		exponent;
	int		sign;
	int		i;
	char	buff;

	sign = (n < 0) ? 1 : 0;
	exponent = 1;
	i = n;
	while ((i = i / base))
		exponent *= base;
	if (sign)
		putchar('-');
	while (exponent)
	{
		i = n / exponent;
		buff = (sign) ? HEX_T(-(i % base)) : HEX_T((i % base));
		n -= i * exponent;
		putchar(buff);
		exponent /= base;
	}
}
