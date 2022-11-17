/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/17 04:18:01 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

t_error_code	heredoc_get_line(char **line, char *eol)
{
	char	*str;
	char	*tmp;

	str = readline(HEREDOC_PROMPT);
	*line = ft_strdup("");
	while (ft_strcmp(str, eol))
	{
		tmp = *line;
		*line = ft_strjoin(*line, str);
		free(tmp);
		free(str);
		str = readline(HEREDOC_PROMPT);
	}
	return (SUCCESS);
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
