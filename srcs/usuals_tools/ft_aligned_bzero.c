/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligned_bzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:09 by bmickael           #+#    #+#             */
/*   Updated: 2018/07/22 17:22:16 by bmickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** XXX This function is not secure ! Only size multiplied by 8 works !
*/

void	ft_aligned_bzero(void *s, size_t n)
{
	uint64_t *dst;

	dst = (uint64_t *)s;
	n >>= 3;
	while (n--)
		*dst++ = (uint64_t)0;
}
