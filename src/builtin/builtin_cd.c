/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:34:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/02 00:35:20 by r3dc4t           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_cd(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	if (2 != tab_count(c->argv))
	{
		c->builtin_ret_val = -1;
		return (SUCCESS);
	}
	c->builtin_ret_val = 0;
	return (SUCCESS);
}
