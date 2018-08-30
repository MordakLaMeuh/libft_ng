/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:07:49 by bmickael          #+#    #+#             */
/*   Updated: 2017/04/10 17:08:15 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern void putchar(char c);

void	ft_putstr(const char *s)
{
	size_t len = ft_strlen(s);

	for (size_t i = 0; i < len; i++)
		putchar(s[i]);
}
