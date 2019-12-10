/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 06:04:42 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:48:10 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t		i;

	i = 0;
	if (s)
		i = ft_strlen(s);
	i > maxlen ? (i = maxlen) : i;
	return (i);
}
