/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 21:11:23 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "env.h"
#include "tab.h"

void	test_env(void)
{
	t_cmd	cmd;

	env_initenv(&cmd, 0);
	env_setvar(&cmd, "KEY 0", "VALUE 0"); 	//size = 1
	env_setvar(&cmd, "KEY 1", "VALUE 1"); 	//size = 2
	env_setvar(&cmd, "KEY 2", "VALUE 2"); 	//size = 3
	env_setvar(&cmd, "KEY 3", "VALUE 3"); 	//size = 4
	env_setvar(&cmd, "KEY 4", "VALUE 4"); 	//size = 5
	env_unsetvar(&cmd, "KEY 4"); 			//size = 4
	env_unsetvar(&cmd, "KEY -1"); 			//size = 4
	env_setvar(&cmd, "KEY 5", "VALUE 5"); 	//size = 5
	env_setvar(&cmd, "KEY 5", "VALUE 5.2"); //size = 5
	env_setvar(&cmd, "KEY 6", "VALUE 6"); 	//size = 6
	env_unsetvar(&cmd, "KEY 6"); 			//size = 5
	env_setvar(&cmd, "KEY 7", "VALUE 7"); 	//size = 6
	env_setvar(&cmd, "KEY 8", "VALUE 8"); 	//size = 7
	env_setvar(&cmd, "KEY 9", "VALUE 9"); 	//size = 8
	env_unsetvar(&cmd, "KEY 2"); 			//size = 7

	// tab_print(cmd.env);
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 0), "KEY 0=VALUE 0");
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 1), "KEY 1=VALUE 1");
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 2), "KEY 9=VALUE 9");
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 3), "KEY 3=VALUE 3");
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 4), "KEY 5=VALUE 5.2");
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 5), "KEY 7=VALUE 7");
	CU_ASSERT_STRING_EQUAL(*(cmd.env + 6), "KEY 8=VALUE 8");
	env_destroyenv(&cmd);
}
