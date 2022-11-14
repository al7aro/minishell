/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/14 13:32:31 by al7aro           ###   ########.fr       */
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
