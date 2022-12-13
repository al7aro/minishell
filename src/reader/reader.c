/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/01 10:59:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static t_bool	is_quote_closed(char *str)
{
	char	quote_char;
	size_t	i;

	i = 1;
	quote_char = *str;
	while ((*(str + i) && *(str + i) != quote_char))
		i++;
	if (*(str + i) == quote_char)
		return (i);
	return (0);
}

static t_error_code	close_opened_quote(char **line)
{
	char	*tmp;
	char	*new_content;
	size_t	i;

	i = -1;
	while (*(*line + ++i))
	{
		if (reader_is_squote(*(*line + i)) || reader_is_dquote(*(*line + i)))
		{
			while (!is_quote_closed(*line + i))
			{
				tmp = *line;
				new_content = readline(reader_get_quote_prompt(*(*line + i)));
				if (!new_content)
					return (ERROR);
				*line = ft_strjoin(*line, new_content);
				free(tmp);
				if (!(*line))
					return (ALLOCATION_ERROR);
				free(new_content);
			}
			i += is_quote_closed(*line + i);
		}
	}
	return (SUCCESS);
}

t_error_code	reader_get_tab(t_shell_op *sp)
{
	t_error_code	err;
	char			*full_expansion;
	char			*semi_expansion;
	char			*line;

	line = readline(MAIN_PROMPT);
	if (!line)
		return (END_OF_TRANSMISSION);
	add_history(line);
	err = close_opened_quote(&line);
	if (SUCCESS != err)
		return (err);
	if (!line)
		return (ERROR);
	full_expansion = expander_expand_var(sp, line, TRUE);
	semi_expansion = expander_expand_var(sp, line, FALSE);
	if (!full_expansion || !semi_expansion)
		return (ERROR);
	err = reader_split_by_token(full_expansion, &(sp->input_full_expansion));
	err = reader_split_by_token(semi_expansion, &(sp->input));
	free(full_expansion);
	free(semi_expansion);
	free(line);
	return (err);
}
