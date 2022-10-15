/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:36 by yoav              #+#    #+#             */
/*   Updated: 2022/10/12 12:27:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "executer.h"
#include "commander.h"
#include "laxer.h"

void	test_basic_executer(void)
{
	t_error_code		err;
	t_cmd				*c;
	char				**args;

	err = cmd_create(&c);
	CU_ASSERT_EQUAL_FATAL(err, SUCCESS);
	args = util_create_tab(2, "/usr/bin/touch", TEST_FILE);
	cmd_add_arg(c, args[0]);
	cmd_add_arg(c, args[1]);
	executer_run_cmd(c);
	util_check_file_and_remove(TEST_FILE);
	cmd_destroy(&c);
	tab_deep_destroy(&args);
}

static void	init_sp(t_shell_op **ret)
{
	t_error_code	err;
	t_shell_op		*sp;
	char			**input;

	err = shell_op_create(&sp, g_envp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	input = util_create_tab(5, "/usr/bin/touch", TEST_FILE, "|", \
		"/usr/bin/touch", TEST_FILE2);
	shell_op_set_input(sp, input);
	err = laxer_create_token_list(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	err = commander_create_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	*ret = sp;
}

void	test_multi_cmd_exec(void)
{
	t_error_code	err;
	t_shell_op		*sp;

	init_sp(&sp);
	err = executer_run_all_cmds(sp);
	CU_ASSERT_EQUAL_FATAL(SUCCESS, err);
	util_check_file_and_remove(TEST_FILE);
	util_check_file_and_remove(TEST_FILE2);
	shell_op_destroy(&sp);
}
