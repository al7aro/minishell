/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/20 17:16:30 by r3dc4t-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "macro.h"
#include "reader.h"
#include "tab.h"

// TODO CHECK HUGE AMMOUNT OF LEAKS
// TODO EXPAND $?
// TODO IMPLEMENT IT TO MAIN FLOW AND USE QUOTE REMOVAL

// CALL EXPANDER JUST AFTER READLINE (INSIDE READER_GET_TAB)
// EXPANDER SHOULD RETURN EVERYTHING AS A WORD (BETWEEN QUOTES -> "word")
static char	*str_append_char(char **str, char c, t_bool sufix)
{
	char	*ret;
	char	*app;

	app = (char *)malloc(sizeof(char) * 2);
	*app = c;
	*(app + 1) = 0;
	if (sufix)
		ret = ft_strjoin(*str, app);
	else
		ret = ft_strjoin(app, *str);
	free(*str);
	free(app);
	return (ret);
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
		*(ret + i) = str_append_char((ret + i), '\"', FALSE);
		*(ret + i) = str_append_char((ret + i), '\"', TRUE);
		if (*(ret + i + 1))
			*(ret + i) = str_append_char((ret + i), ' ', TRUE);
		tmp = final_ret;
		final_ret = ft_strjoin(final_ret, *(ret + i));
		free(tmp);
		i++;
	}
	tab_deep_destroy(&ret);
	return (final_ret);
}

static int	expander_get_var(t_shell_op *sp, char *str, char **ret)
{
	int		i;
	int		str_len;

	i = -1;
	str_len = ft_strlen(str);
	if ('?' == *(str + 1))
	{
		*ret = ft_itoa(sp->last_cmd_stt);
		return (1);
	}
	while (++i <= str_len)
	{
		if (is_end_of_var_name(*(str + i)))
		{
			str = ft_substr(str, 1, i - 1);
			*ret = env_getvar(sp->envp, str);
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

static	t_bool	inside_quote(t_bool flag, char c)
{
	if (c == '\"')
		return (!flag);
	return (flag);
}

char	*expander_expand_var(t_shell_op *sp, char *str)
{
	char	*ret;
	char	*exp;
	char	*tmp;
	int		i;
	t_bool	expand;

	expand = TRUE;
	i = -1;
	ret = ft_strdup("");
	while (*(str + ++i) && (sp->envp))
	{
		expand = inside_quote(expand, *(str + i));
		tmp = ret;
		if (EXPANDER_CHAR == *(str + i) && expand)
		{
			i += expander_get_var(sp, str + i, &exp);
			exp = word_encloser(exp);
			ret = ft_strjoin(tmp, exp);
			free(exp);
			free(tmp);
		}
		else
			ret = str_append_char(&ret, *(str + i), 1);
	}
	return (ret);
}