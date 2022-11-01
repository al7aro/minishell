/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:33 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/02 00:01:36 by r3dc4t           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_error_code	builtin_exit(t_shell_op *sp, t_cmd *c)
{
	(void)c;
	sp->run = FALSE;
	c->builtin_ret_val = SUCCESS;
	return (SUCCESS);
}
