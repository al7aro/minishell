/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/17 06:27:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

t_bool	heredoc_line(char **line, char *eol)
{
	char	*str;
	char	*tmp;

	if (!eol)
		return (FALSE);
	str = readline(HEREDOC_PROMPT);
	*line = ft_strdup("");
	while (ft_strcmp(str, eol))
	{
		tmp = *line;
		*line = ft_strjoin(*line, str);
		free(tmp);
		free(str);
		tmp = *line;
		*line = ft_strjoin(*line, "\n");
		free(tmp);
		str = readline(HEREDOC_PROMPT);
	}
	return (TRUE);
}

void	heredoc_tab_add_heredoc(char ***heredoc_tab, char *value)
{
	if (!*heredoc_tab)
		tab_create(heredoc_tab, 1);
	tab_add(heredoc_tab, value);
}

void	heredoc_tab_destroy(char ***heredoc_tab)
{
	tab_shallow_destroy(heredoc_tab);
}

t_error_code	heredoc_handle_heredoc(t_cmd *c)
{
	int		pipe_ends[2];
	char	*final_line;
	char	*tmp;
	char	*line;
	size_t	i;

	pipe(pipe_ends);
	if (fork() == 0)
	{
		close(pipe_ends[0]);
		i = -1;
		final_line = ft_strdup("");
		while (*(c->heredoc + ++i) && heredoc_line(&line, *(c->heredoc + i)))
		{
			tmp = final_line;
			final_line = ft_strjoin(final_line, line);
			free(tmp);
			free(line);
		}
		write(pipe_ends[1], final_line, ft_strlen(final_line));
		exit(0);
	}
	close(pipe_ends[1]);
	dup_wrapper(pipe_ends[0], STDIN_FILENO);
	wait(NULL);
	return (SUCCESS);
}
