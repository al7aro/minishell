/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/14 09:19:56 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_code.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	tmp_print_input_table(char **input_table)
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

char	**first_read(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	return (NULL); }

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
 * 	TODO
 * 		LEAK: free tab..?
 * */
char **reader()
{
	char	*line;
	char	**tab;

	line = readline(">_");
	dquote(&line);
	add_history(line);
	tab = ft_split(line, ' ');
	free(line);
	return (tab);
}
