/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/22 23:59:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "reader.h"

// TODO CHECK HUGE AMMOUNT OF LEAKS
// TODO EXPAND $?
// TODO IMPLEMENT IT TO MAIN FLOW AND USE QUOTE REMOVAL

// CALL EXPANDER JUST AFTER READLINE (INSIDE READER_GET_TAB)
// EXPANDER SHOULD RETURN EVERYTHING AS A WORD (BETWEEN QUOTES -> "word")
static void	str_append_char(char **str, char c, t_bool sufix)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) + 1);
	if (!ret)
		return ;
	*ret = c;
	*(ret + 1) = 0;
	tmp = *str;
	if (sufix)
		*str = ft_strjoin(*str, ret);
	else
		*str = ft_strjoin(ret, *str);
	free(tmp);
	free(ret);
}

static char	*word_encloser(char *str)
{
	char	*final_ret;
	char	*tmp;
	char	**ret;
	size_t	i;

	i = 0;
	final_ret = ft_strdup("");
	reader_split_by_token(str, &ret);
	while (*(ret + i))
	{
 			str_append_char((ret + i), '\"', FALSE);
 			str_append_char((ret + i), '\"', TRUE);
 			if (*(ret + i + 1))
 				str_append_char((ret + i), ' ', TRUE);
 			tmp = final_ret;
 			final_ret = ft_strjoin(final_ret, *(ret + i));
 			free(tmp);
 			i++;
	}
	free(ret);
	return (final_ret);
}

static int	expander_get_var(char **env, char *str, char **ret)
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
			if (!*ret)
				*ret = "";
			if (i == 1)
				*ret = "$";
			return (i - 1);
		}
	}
	return (0);
}

char	*expander_expand_var(char **env, char *str)
{
	char	*ret;
	char	*exp;
	char	*tmp;
	int		i;
	int		var_len;

	i = 0;
	if (!env)
		return (ft_strdup(str));
	ret = ft_strdup("");
	while (*(str + i))
	{
		var_len = 1;
		tmp = ret;
		if (EXPANDER_CHAR == *(str + i))
		{
			var_len += expander_get_var(env, str + i, &exp);
			ret = ft_strjoin(tmp, word_encloser(exp));
			free(tmp);
		}
		else
			str_append_char(&ret, *(str + i), 1);
		i += var_len;
	}
	return (ret);
}
