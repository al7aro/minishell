/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_internal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:50:39 by al7aro            #+#    #+#             */
/*   Updated: 2022/12/14 16:19:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_error_code	handle_input(t_shell_op *sp, t_read_input read_func)
{
	t_error_code	err;

	err = read_func(sp);
	if (SUCCESS != err)
		return (err);
	if (NULL == sp->input)
		return (EOF_SUCCESS);
	if (!(**(sp->input)))
		return (NO_INPUT);
	err = laxer_create_token_list(sp);
	if (SUCCESS != err)
		return (err);
	err = expander_remove_all_quotes(sp);
	if (SUCCESS != err)
		return (err);
	err = parser_check_tokens(sp);
	if (SUCCESS != err)
		cleaner_on_parse_error(sp);
	return (err);
}

t_error_code	handle_valid_input(t_shell_op *sp)
{
	t_error_code	err;

	err = commander_create_cmds(sp);
	if (SUCCESS != err)
		return (err);
	err = redirecter_setup_files(sp);
	if (SUCCESS != err)
	{
		if (HEREDOC_SIGNAL_EXIT == err)
			cleaner_round_clean(sp);
		return (err);
	}
	err = piper_init_pipes(sp);
	if (SUCCESS != err)
		return (err);
	err = executer_run_all_cmds(sp);
	if (SUCCESS != err)
		return (err);
	cleaner_round_clean(sp);
	return (SUCCESS);
}

t_error_code	internal_flow(char *cli_input, char **envp, \
	t_read_input read_func)
{
	int				ret;
	t_error_code	err;
	t_shell_op		*sp;

	ret = SUCCESS;
	err = shell_op_create(&sp, envp);
	if (SUCCESS != err)
		return (err);
	sp->run = TRUE;
	env_inc_shlvl(&(sp->envp));
	env_set_pwd(&(sp->envp));
	if (cli_input)
		sp->cli_input = cli_input;
	err = internal_loop(sp, read_func);
	if (SUCCESS == err)
		ret = sp->last_cmd_stt;
	shell_op_destroy(&sp);
	return (ret);
}
