/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:39:25 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/13 19:17:39 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdio.h>

static void	print_string(char **tab, t_bool nl)
{
	int	i;

	i = 0;
	while (*(tab + i))
		printf("%s", *(tab + i++));
	if (nl)
		printf("\n");
}

t_error_code	builtin_echo(t_shell_op *sp, t_cmd *c)
{
	(void)sp;
	if (!*(c->argv + 1))
	{
		printf("\n");
		return (SUCCESS);
	}
	if (!ft_strcmp(*(c->argv + 1), "-n"))
		print_string(c->argv + 2, 0);
	else
		print_string(c->argv + 1, 1);
	c->builtin_ret_val = 0;
	return (SUCCESS);
}
