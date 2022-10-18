/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 10:05:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <string.h>

static t_bool	is_end_of_var_name(char c)
{
	if (SPACE_CHAR == c
		|| R_BRACKET == c
		|| MINUS_CHAR == c
		|| EQUAL_CHAR == c
		|| '\0' == c)
		return (TRUE);
	return (FALSE);
}

int	expander_get_var(char **env, char *str, char **ret)
{
	int		i;
	int		start;
	int		str_len;

	i = -1;
	str_len = ft_strlen(str);
	start = 1 + (L_BRACKET == *(str + 1));
	while (++i <= str_len)
	{
		if (is_end_of_var_name(*(str + i)))
		{
			str = ft_substr(str, start, i - 1);
			*ret = env_getvar(env, str);
			free(str);
			return (i - 1);
		}
	}
	return (0);
}

static char	*str_append_char(char *ret, char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) + 1);
	*str = c;
	*(str + 1) = 0;
	ret = ft_strjoin(ret, str);
	free(str);
	return (ret);
}

char	*expander_expand(char **env, char *str)
{
	char	*ret;
	char	*exp;
	char	*tmp;
	int		i;
	int		var_len;

	i = 0;
	ret = ft_strdup("");
	while (*(str + i))
	{
		var_len = 1;
		tmp = ret;
		if (EXPANDER_CHAR == *(str + i))
		{
			var_len += expander_get_var(env, str + i, &exp);
			ret = ft_strjoin(tmp, exp);
			free(exp);
		}
		else
			ret = str_append_char(tmp, *(str + i));
		free(tmp);
		i += var_len;
	}
	return (ret);
}
