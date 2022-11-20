/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r3dc4t <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:01:18 by r3dc4t            #+#    #+#             */
/*   Updated: 2022/11/20 17:44:39 by r3dc4t           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "expander.h"
#include "libft.h"
#include "tab.h"

static t_bool	key_is_valid(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	str_is_valid(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == EQUAL_CHAR)
				cnt++;
		str++;
	}
	if (1 < cnt)
		return (FALSE);
	return (TRUE);
}

static char	*get_expanded_var(t_shell_op *sp, char *str)
{
	char	*ret;

	ret = expander_expand_var(sp, str);
	return (ret);
}

t_error_code	builtin_export(t_shell_op *sp, t_cmd *c)
{
	char	**spl;

	c->builtin_ret_val = ERROR;
	if (2 != tab_count(c->argv))
		return (SUCCESS);
	spl = ft_split(*(c->argv + 1), EQUAL_CHAR);
	if (2 != tab_count(spl) || !str_is_valid(*(c->argv + 1)))
	{
		tab_deep_destroy(&spl);
		return (SUCCESS);
	}
	if (!key_is_valid(*(spl)))
	{
		tab_deep_destroy(&spl);
		return (SUCCESS);
	}
	c->builtin_ret_val = SUCCESS;
	env_setvar(&sp->envp, *spl, get_expanded_var(sp, *(spl + 1)));
	tab_deep_destroy(&spl);
	return (SUCCESS);
}
