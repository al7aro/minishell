/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:28:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/13 11:04:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static t_bool	is_quote_paired(char *str)
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

static t_bool	is_quote_valid(char *line)
{
	size_t	i;

	i = -1;
	while (*(line + ++i))
	{
		if (reader_is_squote(*(line + i)) || reader_is_dquote(*(line + i)))
		{
			if (!is_quote_paired(line + i))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}

// TODO move this string to macros
// todo write into the terminal fd
t_error_code	reader_get_tab_from_file(t_shell_op *sp)
{
	t_error_code	err;
	char			*line;
	char			*tmp;

	terminaler_set_out_to_null(sp->t);
	line = readline(NULL);
	terminaler_set_out_to_out(sp->t);
	if (!line)
		return (ERROR);
	if (!is_quote_valid(line))
	{
		error_code_print(1, EOF_ERR_STR);
		return (ERROR);
	}
	tmp = line;
	line = expander_expand_var(sp, line);
	free(tmp);
	err = reader_split_by_token(line, &(sp->input));
	free(line);
	return (err);
}
