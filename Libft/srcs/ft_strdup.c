/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:30:04 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:47:30 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*str;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	str = ft_strsub(s1, 0, len);
	return (str);
}
