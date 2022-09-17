/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:12:35 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/17 17:51:08 by alopez-g         ###   ########.fr       */
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
			printf("[%d] %s$\n", i, *(input_table + i));
			i++;
		}
}

char	paired(char *str)
{
	char	q;
	char	i;

	printf("%c\n", *str);
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
	char	*str;
	char	*tmp;
	char	*new_content;
	char	i;

	str = *line;
	tmp = NULL;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '\"' || *(str + i) == '\'')
		{
			while (!paired(str + i)) 
			{
				tmp = str;
				new_content = readline("dquote> ");
				str = ft_strjoin(str, new_content);
				free(tmp);
				tmp = str;
				str = ft_strjoin(str, " ");
				free(tmp);
				free(new_content);
			}
			i += paired(str + i);
		}
		i++;
	}
	*line = str;
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
	printf("%s\n", line);
	tab = ft_split_smart(line, ' ', '\'');
	free(line);
	return (tab);
}
