/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:47 by yoav              #+#    #+#             */
/*   Updated: 2022/11/17 04:31:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// TODO do something with stt = execve() on err
// TODO err print
// apply heredoc here
t_error_code	executer_child_logic(t_shell_op *sp, t_cmd *c)
{
	t_error_code	err;
	int				stt;

	err = piper_child_dup_if_needed(c);
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	err = piper_close_pipes(sp);
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	err = redirecter_child_dup_if_needed(c);
	if (SUCCESS != err)
		return (error_code_print_internal_err(err));
	if (c->heredoc)
	{
					printf("HEREDOC PROMPT IS ALWAYS SHOWED\n"); fflush(stdout);
					// char	*line = NULL;
					// heredoc_get_line(&line, "end_test");
					// pipe_close(c->pp->in);
					// write(c->pp->out->fd, line, ft_strlen(line));
					// pipe_close(c->pp->out);
					// dup2(c->pp->in->fd, STDIN_FILENO);
					if (tab_count(c->argv) == 1)
						{printf("HEREDOC IS WORKING\n"); fflush(stdout); tab_print(c->heredoc);}
					else
						{printf("HEREDOC DOES NOT WORK NOW\n");fflush(stdout);}
	}
	stt = execve(c->exec_path, c->argv, sp->envp);
	if (ERROR == stt)
		error_code_print(3, strerror(errno), ": ", cmd_get_cmd(c));
	return (SUCCESS);
}
