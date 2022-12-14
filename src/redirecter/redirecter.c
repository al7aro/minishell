/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:37 by yoav              #+#    #+#             */
/*   Updated: 2022/12/14 16:10:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirecter.h"

static int	handle_redirect(t_dll *elem, void *param)
{
	t_error_code	err;
	t_redirect		*r;

	(void)param;
	r = elem->value;
	if (HEREDOC == r->type)
	{
		if (!mode_mngr_is_interactive())
			return (HEREDOC_ERR_ON_INTERACTIVE_MODE);
		r->heredoc_eol = r->path;
		r->path = heredoc_get_temp_path(HEREDOC_TMP_PATH);
		r->should_free_path = TRUE;
		err = heredoc_run_child(r);
		r->should_del_tmp = TRUE;
		if (HEREDOC_SIGNAL_EXIT == err)
			return (err);
	}
	err = open_file(r);
	if (SUCCESS != err)
		error_code_print(3, r->path, ": ", strerror(errno));
	return (err);
}

static int	handle_cmd(t_dll *elem, void *param)
{
	t_error_code	err;
	t_cmd			*c;

	(void)param;
	c = elem->value;
	err = dll_iterate(c->redirect->lst, handle_redirect, NULL);
	if (OPEN_ERROR == err)
	{
		c->stt = REDIRECT_ERROR;
		err = SUCCESS;
	}
	return (err);
}

t_error_code	redirecter_setup_files(t_shell_op *sp)
{
	t_error_code	err;

	err = dll_iterate(cmd_list_get_list(shell_op_get_cmd_list(sp)), \
		handle_cmd, NULL);
	if (SUCCESS != err)
	{
		if (HEREDOC_ERR_ON_INTERACTIVE_MODE == err)
			error_code_print(2, HEREDOC_ERR_STR, HEREDOC_INTER_ERR_STR);
		return (err);
	}
	return (SUCCESS);
}

void	redirecter_init_redirect(t_cmd *c, char *symbol, char *path)
{
	if (is_rr(symbol))
		redirect_list_add(c->redirect, path, OUT);
	else if (is_rl(symbol))
		redirect_list_add(c->redirect, path, IN);
	else if (is_drr(symbol))
		redirect_list_add(c->redirect, path, APPEND);
	else if (is_drl(symbol))
		redirect_list_add(c->redirect, path, HEREDOC);
}
