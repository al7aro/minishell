/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/18 02:23:33 by alopez-g         ###   ########.fr       */
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

/*
 * tab = ft_split_copy(argv + 1); //returns TAB
 * exec_command();
 * */
void	arg_reader(int argc, char **argv)
{
	char	**tab;

	(void)argc;
	(void)argv;
	if (argc != 1)
	{
		tab = argv + 1;
		info_log_input_table(tab);
		exit(0);
	}
}

void	info_log_input_table(char **input_table)
{
	int	i;

	i = 0;
	if (input_table)
	{
		while (*(input_table + i))
		{
			printf("[%d] %s$\n", i, *(input_table + i));
			i++;
		}
	}
}

char	paired(char *str)
{
	char	q;
	char	i;

	i = 1;
	q = *str;
	while (*(str + i) && *(str + i) != q)
		i++;
	if (*(str + i) == q)
		return (i);
	return (0);
}

char	*dquote(char **line)
{
	char	*tmp;
	char	*new_content;
	char	i;

	i = 0;
	while (*(*line + i))
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
				*line = ft_strjoin(*line, " ");
				free(tmp);
				free(new_content);
			}
			i += paired(*line + i);
		}
		i++;
	}
	return (NULL);
}

/*
 * Handle dquote (open quotes)
 * whats inside "" should not be splitted
 * 		it should be sent as a hole
 * */
char	**reader(void)
{
	char	*line;
	char	**tab;

	line = readline(">_");
	if (!line)
		exit(0);
	dquote(&line);
	add_history(line);
	tab = ft_split_arg(line);
	free(line);
	return (tab);
}
