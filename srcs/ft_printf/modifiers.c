/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 18:22:30 by bmickael          #+#    #+#             */
/*   Updated: 2017/04/10 23:23:27 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void set_text_color(unsigned int color);

#include "internal_printf.h"

static int			compare(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i] != 0x00 && s1[i] != 0x00 && (s1[i] == s2[i]))
		i++;
	if (s1[i] == 0x00)
		return (i);
	return (0);
}

struct modifier_list {
	char *string;
	int color;
};

static const struct modifier_list g_modifier_list[MODIFIER_QUANTITY] = {
	{ "{eoc}", 7 },
	{ "{red}", 4 },
	{ "{green}", 2 },
	{ "{yellow}", 14 },
	{ "{blue}", 1 },
	{ "{magenta}", 5 },
	{ "{cyan}", 3 },
	{ "{white}", 7 },
	{ "{black}", 0},
	{ "{orange}", 6},
	{ "{grey}", 8},
	{ "{deepblue}", 9},
	{ "{lightgreen}", 10}
};

void				assign_modifier(t_status *op)
{
	int l;

	l = 0;
	while (l < MODIFIER_QUANTITY)
	{
		if (compare(g_modifier_list[l].string, op->s))
		{
			op->s += ft_strlen(g_modifier_list[l].string);
			set_text_color(g_modifier_list[l].color);
			return ;
		}
		l++;
	}
	op->s += 1;
	char_to_buffer('{', 1, op);
}
