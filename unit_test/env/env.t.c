/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 00:53:52 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "env.h"
#include "tab.h"
#include "shell_op.h"

void	test_env(void)
{
	t_shell_op	sp;

	env_initenv(&sp.envp, 0);
	env_setvar(&sp.envp, "KEY 0", "VALUE 0"); 	//size = 1
	env_setvar(&sp.envp, "KEY 1", "VALUE 1"); 	//size = 2
	env_setvar(&sp.envp, "KEY 2", "VALUE 2"); 	//size = 3
	env_setvar(&sp.envp, "KEY 3", "VALUE 3"); 	//size = 4
	env_setvar(&sp.envp, "KEY 4", "VALUE 4"); 	//size = 5
	env_unsetvar(&sp.envp, "KEY 4"); 			//size = 4
	env_unsetvar(&sp.envp, "KEY -1"); 			//size = 4
	env_setvar(&sp.envp, "KEY 5", "VALUE 5"); 	//size = 5
	env_setvar(&sp.envp, "KEY 5", "VALUE 5.2"); //size = 5
	env_setvar(&sp.envp, "KEY 6", "VALUE 6"); 	//size = 6
	env_unsetvar(&sp.envp, "KEY 6"); 			//size = 5
	env_setvar(&sp.envp, "KEY 7", "VALUE 7"); 	//size = 6
	env_setvar(&sp.envp, "KEY 8", "VALUE 8"); 	//size = 7
	env_setvar(&sp.envp, "KEY 9", "VALUE 9"); 	//size = 8
	env_unsetvar(&sp.envp, "KEY 2"); 			//size = 7

	// tab_print(sp.envp);
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 0), "KEY 0=VALUE 0");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 1), "KEY 1=VALUE 1");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 2), "KEY 9=VALUE 9");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 3), "KEY 3=VALUE 3");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 4), "KEY 5=VALUE 5.2");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 5), "KEY 7=VALUE 7");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 6), "KEY 8=VALUE 8");
	env_destroy(&(sp.envp));
}
