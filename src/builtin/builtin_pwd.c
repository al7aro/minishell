/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:28:23 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/02 00:35:04 by r3dc4t           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "tab.h"

t_error_code	builtin_pwd(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	if (1 != tab_count(c->argv))
	{
		c->builtin_ret_val = -1;
		return (SUCCESS);
	}
	c->builtin_ret_val = 0;
	printf("%s\n", env_getvar(sp->envp, "PWD"));
	return (SUCCESS);
}
