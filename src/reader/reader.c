/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/18 12:05:51 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
#include "tab.h"

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
			while (!quote_is_closed(*line + i))
			{
				tmp = *line;
				new_content = readline("dquote> ");
				*line = ft_strjoin(*line, new_content);
				free(tmp);
				tmp = *line;
				*line = ft_strjoin(*line, "");
				free(tmp);
				free(new_content);
			}
			i += quote_is_closed(*line + i);
		}
	}
	return (SUCCESS);
}

void	reader_arg(int argc, char **argv)
{
	t_error_code	err;
	char			**tab;

	if (argc != 1)
	{
		err = reader_split_arg(*(argv + 1), &tab);
		if (ERROR == err)
			exit(err);
		tab_print(tab);
		exit(err);
	}
}

/*
 * TODO CREATE QUOTE_CONSTANT
 * DO NOT EXIT HERE
 **/
t_error_code	reader(char ***ret)
{
	t_error_code	err;
	char			*line;

	line = readline(">_");
	dquote(&line);
	if (!line)
		exit(0);
	add_history(line);
	err = reader_split_arg(line, ret);
	free(line);
	return (err);
}
