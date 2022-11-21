/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/21 13:51:45 by al7aro-g         ###   ########.fr       */
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

void	heredoc_tab_destroy(char ***heredoc_tab)
{
	tab_shallow_destroy(heredoc_tab);
}

t_error_code	heredoc_handle_heredoc(t_cmd *c)
{
	char	*final_line;
	char	*tmp;
	char	*l;
	size_t	i;

	i = -1;
	final_line = ft_strdup("");
	while (*(c->heredoc + ++i) && heredoc_line(&l, *(c->heredoc + i)))
	{
		tmp = final_line;
		final_line = ft_strjoin(final_line, l);
		free(tmp);
		free(l);
	}
	free(final_line);
	return (SUCCESS);
}
