/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:04:01 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/12/10 16:26:35 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <unistd.h>

size_t		ft_insert_percent(t_frmt_fs *f)
{
	f->orient ? write(STDOUT_FILENO, "%", 1) : 1;
	ft_putchar_n(f->zerofill && !f->orient ? '0' : ' ', f->field_len - 1);
	!f->orient ? write(STDOUT_FILENO, "%", 1) : 1;
	return (f->field_len > 1 ? f->field_len : 1);
}
