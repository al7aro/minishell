/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/25 14:50:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

char	quote_is_closed(char *str)
{
	char	quote_char;
	char	i;

	i = 1;
	quote_char = *str;
	while ((*(str + i) && *(str + i) != quote_char))
		i++;
	if (*(str + i) == quote_char)
		return (i);
	return (0);
}

/*
 * line 53 is probably redundant
 * */
t_error_code	dquote(char **line)
{
	char	*tmp;
	char	*new_content;
	char	i;

	i = -1;
	while (*(*line + ++i))
	{
		if (is_squote(*(*line + i)) || is_dquote(*(*line + i)))
		{
			i += quote_is_closed(*line + i);
			while (!i)
			{
				tmp = *line;
				new_content = readline(DQUOTE_PROMPT);
				*line = ft_strjoin(*line, new_content);
				if (!(*line))
					return (ALLOCATION_ERROR);
				free(tmp);
				tmp = *line;
				*line = ft_strjoin(*line, EMPTY_STRING);
				if (!(*line))
					return (ALLOCATION_ERROR);
				free(tmp);
				free(new_content);
			}
		}
	}
	return (SUCCESS);
}

t_error_code	reader_from_arg(int argc, char **argv)
{
	t_error_code	err;
	char			**tab;

	err = SUCCESS;
	if (argc != 1)
		err = reader_split_arg(*(argv + 1), &tab);
	return(err);
}

/*
 * TODO CREATE QUOTE_CONSTANT
 **/
t_error_code	reader(char ***ret)
{
	t_error_code	err;
	char			*line;

	line = readline(MAIN_PROMPT);
	dquote(&line);
	if (!line)
		return (ERROR);
	add_history(line);
	err = reader_split_arg(line, ret);
	free(line);
	return (err);
}
