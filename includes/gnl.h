/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:21:53 by vcombey           #+#    #+#             */
/*   Updated: 2018/07/22 17:21:56 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "custom_allocator.h"

/*
** Return the next newline of a file descriptor.
*/

int					get_next_line(
		const int fd,
		char **line,
		struct s_custom_memory_fn *mem);

#endif
