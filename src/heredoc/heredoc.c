/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:24:41 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/21 18:03:57 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "libft.h"

void	heredoc_line(char **line, char *eol)
{
	char	*str;
	char	*tmp;

	if (!eol)
		return ;
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
}

void	heredoc_tab_destroy(char ***heredoc_tab)
{
	tab_shallow_destroy(heredoc_tab);
}

#include <time.h>
char	*heredoc_get_temp_path(char *eol)
{
	char	*path;
	char	*aux;
	int		n;

	(void)eol;
	srand(time(NULL));
	n = rand();
	aux = ft_itoa(n);
	path = ft_strjoin("/tmp/hd_file", aux);
	free(aux);
	return (path);
}

char	*heredoc_handle_heredoc(char *eol)
{
	char	*line;
	char	*tmp_path;
	int		fd;

	tmp_path = heredoc_get_temp_path(eol);
	line = ft_strdup("");
	heredoc_line(&line, eol);
	fd = open(tmp_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, line, ft_strlen(line));
	close(fd);
	free(line);
	return (tmp_path);
}
