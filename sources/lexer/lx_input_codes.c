/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_input_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaemoni <gdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:53:18 by gdaemoni          #+#    #+#             */
/*   Updated: 2019/12/10 16:16:46 by gdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_req.h"
#include "sh_token.h"
#include "sh_tokenizer.h"
#include "sys_tools/sys_sh_configs.h"

char	get_code(void)
{
	const char	codes_buf[] = "sp&|uaqllm";

	if (g_parse_err >= 0 || g_syntax_err >= 0)
	{
		g_parse_err = -1;
		g_syntax_err = -1;
		return (0);
	}
	if (g_input_nover >= 0 && g_input_nover <= 9)
		return (codes_buf[g_input_nover]);
	return (0);
}
