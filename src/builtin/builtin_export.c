/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:18 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/02 00:41:52 by r3dc4t           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "tab.h"

static t_bool	key_is_valid(char *str)
{
	while (*str)
	{
		if (*str == SPACE_CHAR
			|| *str == SINGLE_QUOTE_CHAR
			|| *str == DOUBLE_QUOTE_CHAR)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	value_is_valid(char *str)
{
	(void)str;
	return (TRUE);
}

static t_bool	str_is_valid(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '=')
				cnt++;
		str++;
	}
	if (1 < cnt)
		return (FALSE);
	return (TRUE);
}

static char	*get_expanded_var(char *str)
{
	return (str);
}

t_error_code	builtin_export(t_shell_op *sp, t_cmd *c)
{
	char	**spl;

	if (2 != tab_count(c->argv))
	{
		c->builtin_ret_val = -1;
		return (SUCCESS);
	}
	spl = ft_split(*(c->argv + 1), '=');
	if (2 != tab_count(spl)
		|| !key_is_valid(*(spl + 1))
		|| !str_is_valid(*(c->argv + 1))
		|| !value_is_valid(*(c->argv + 1)))
	{
		c->builtin_ret_val = -1;
		tab_deep_destroy(&spl);
		return (SUCCESS);
	}
	c->builtin_ret_val = 0;
	env_setvar(&sp->envp, *spl, get_expanded_var(*(spl + 1)));
	tab_deep_destroy(&spl);
	return (SUCCESS);
}
