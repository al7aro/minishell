/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/18 05:00:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "reader.h"
#include "tab.h"
#include "error_code.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	paired(char *str)
{
	char	q;
	char	i;

	i = 1;
	q = *str;
	while ((*(str + i) && *(str + i) != q))
		i++;
	if (*(str + i) == q)
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
		if (*(*line + i) == '\"' || *(*line + i) == '\'')
		{
			while (!paired(*line + i))
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
			i += paired(*line + i);
		}
	}
	return (SUCCESS);
}

void	info_log_input_table(char **input_table)
{
	int	i;

	i = 0;
	if (input_table)
	{
		while (*(input_table + i))
		{
			printf("[%d] %s\n", i, *(input_table + i));
			i++;
		}
	}
}

void	arg_reader(int argc, char **argv)
{
	t_error_code	err;
	char			**tab;

	if (argc != 1)
	{
		err = ft_split_arg(*(argv + 1), &tab);
		if (err == ERROR)
			exit(err);
		info_log_input_table(tab);
		exit(err);
	}
}

t_error_code	reader(char ***ret)
{
	t_error_code	err;
	char			*line;

	line = readline(">_");
	dquote(&line);
	if (!line)
		exit(0);
	add_history(line);
	err = ft_split_arg(line, ret);
	free(line);
	return (err);
}
