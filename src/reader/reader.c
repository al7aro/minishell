/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/14 12:09:31 by al7aro           ###   ########.fr       */
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

void	arg_reader(int argc, char **argv)
{
	char	**tab;

	(void)argc;
	(void)argv;
	if (argc != 1)
	{
		tab = argv + 1;
		info_log_input_table(tab);
		//tab = ft_split_copy(argv + 1); //returns TAB
		//exec_command();
		exit(0);
	}
}

void	info_log_input_table(char **input_table)
{
	int	i;

	i = 0;
	if (input_table)
		while (*(input_table + i))
		{
			printf("[%d] %s\n", i, *(input_table + i));
			i++;
		}
}

int	cnt_char(char *str, char c)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			cnt++;
		i++;
	}
	return (cnt);
}

/*
 * TODO Create improved split to treat "" as a hole 
 * TODO Each dqoute line is ADDED TO HISTORY following by a ''\n' rather than ' '
 **/
char	*dquote(char **line)
{
	char	*tmp;
	char	*new_content;

	tmp = NULL;
	while (cnt_char(*line, '\"') % 2 != 0) //quotes are opened
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
	return NULL;
}

/*
 * Handle dquote (open quotes)
 * whats inside "" should not be splitted
 * 		it should be sent as a hole
 * */
char **reader()
{
	char	*line;
	char	**tab;

	line = readline(">_");
	if (!line)
		exit(0);
	dquote(&line);
	add_history(line);
	tab = ft_split(line, ' '); //make smart split
	free(line);
	return (tab);
}
