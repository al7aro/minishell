/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:05:08 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/15 13:11:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

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
	char	*ret;

	if (!ft_strcmp(str, EMPTY_STRING))
		return (ft_strdup(str));
	ret = ft_strdup(str);
	ret = str_append_char(&ret, DOUBLE_QUOTE_CHAR, FALSE);
	ret = str_append_char(&ret, DOUBLE_QUOTE_CHAR, TRUE);
	return (ret);
}

static int	expander_get_var(t_shell_op *sp, char *str, char **ret, \
	t_quote q_stt)
{
	int		i;
	int		is_dollar;

	i = 0;
	if (QUESTION_MARK_CHAR == *(str + 1))
	{
		*ret = ft_itoa(sp->last_cmd_stt);
		return (1);
	}
	while (++i <= (int)ft_strlen(str))
	{
		if (is_end_of_var_name(*(str + i)))
		{
			is_dollar = is_print_dollar(str, i, q_stt);
			str = ft_substr(str, 1, i - 1);
			*ret = env_getvar(sp->envp, str);
			free(str);
			if (!*ret)
				*ret = EMPTY_STRING;
			if (i == 1 && is_dollar)
				*ret = EXPANDER_STRING;
			return (i - 1);
		}
	}
	return (0);
}

static void	hndl_exp(char **exp, char **ret, char *tmp)
{
	*exp = word_encloser(*exp);
	*ret = ft_strjoin(tmp, *exp);
	free(*exp);
	free(tmp);
}

char	*expander_expand_var(t_shell_op *sp, char *str)
{
	char	*ret;
	char	*exp;
	char	*tmp;
	int		i;
	t_quote	q_stt;

	ft_bzero(&q_stt, sizeof(t_quote));
	i = -1;
	ret = ft_strdup(EMPTY_STRING);
	while (*(str + ++i) && (sp->envp))
	{
		update_stt(&q_stt, *(str + i));
		tmp = ret;
		if (should_expand(str, i, q_stt.in) || is_valid_tilde(str, i, q_stt.in))
		{
			if (should_expand(str, i, q_stt.in))
				i += expander_get_var(sp, str + i, &exp, q_stt);
			else
				exp = get_tilde(sp);
			hndl_exp(&exp, &ret, tmp);
		}
		else
			ret = str_append_char(&ret, *(str + i), 1);
	}
	return (ret);
}
