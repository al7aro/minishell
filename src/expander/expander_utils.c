/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:56 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/13 12:31:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	is_end_of_var_name(char c)
{
	if (!ft_isalnum(c) && UNDERSCORE_CHAR != c)
		return (TRUE);
	return (FALSE);
}

t_bool	ready_to_expand(char *str, int i)
{
	if (i < 0)
		return (FALSE);
	if (is_redirect(str + i))
		return (TRUE);
	return (FALSE);
}

t_bool	is_valid_tilde(char *str, int i, t_bool in_quote)
{
	if (!in_quote || TILDE_CHAR != str[i])
		return (FALSE);
	if (0 < i && SPACE_CHAR != str[i - 1])
		return (FALSE);
	if (!str[i + 1] || SPACE_CHAR == str[i + 1] || SLASH_CHAR == str[i + 1])
		return (TRUE);
	return (FALSE);
}

t_bool	should_expand(char *str, int i, t_bool in)
{
	return (EXPANDER_CHAR == *(str + i) && in && !ready_to_expand(str, i - 1));
}
