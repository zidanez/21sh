/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbuffer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 06:02:46 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:49:20 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LBUFFER_H
# define FT_LBUFFER_H

# include <unistd.h>

# define LBUFFER_SZ 512
# define PTR_SZ 8
# define LB_STR_SZ (LBUFFER_SZ - PTR_SZ - 1)

typedef struct		s_lbuf
{
	char			str[LB_STR_SZ + 1];
	struct s_lbuf	*next;
}					t_lbuf;

t_lbuf				*ft_lb_readbytes(int fd, ssize_t *summ_rmem);
size_t				ft_lb_strlen(t_lbuf *buff);
char				*ft_lb_flush(t_lbuf *buff);
char				*ft_lb_getstr(t_lbuf *buff);

#endif
