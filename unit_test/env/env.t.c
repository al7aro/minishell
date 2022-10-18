/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 10:56:40 by alopez-g         ###   ########.fr       */
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
	env_setvar(&sp.envp, "KEY 0", "VALUE 0");
	env_setvar(&sp.envp, "KEY 1", "VALUE 1");
	env_setvar(&sp.envp, "KEY 2", "VALUE 2");
	env_setvar(&sp.envp, "KEY 3", "VALUE 3");
	env_setvar(&sp.envp, "KEY 4", "VALUE 4");
	env_unsetvar(sp.envp, "KEY 4");
	env_unsetvar(sp.envp, "KEY -1");
	env_setvar(&sp.envp, "KEY 5", "VALUE 5");
	env_setvar(&sp.envp, "KEY 5", "VALUE 5.2");
	env_setvar(&sp.envp, "KEY 6", "VALUE 6");
	env_unsetvar(sp.envp, "KEY 6");
	env_setvar(&sp.envp, "KEY 7", "VALUE 7");
	env_setvar(&sp.envp, "KEY 8", "VALUE 8");
	env_setvar(&sp.envp, "KEY 9", "VALUE 9");
	env_unsetvar(sp.envp, "KEY 2");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 0), "KEY 0=VALUE 0");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 2), "KEY 9=VALUE 9");
	CU_ASSERT_STRING_EQUAL(*(sp.envp + 6), "KEY 8=VALUE 8");
	CU_ASSERT_STRING_EQUAL(env_getvar(sp.envp, "KEY 1"), "VALUE 1");
	CU_ASSERT_STRING_EQUAL(env_getvar(sp.envp, "KEY 3"), "VALUE 3");
	CU_ASSERT(env_getvar(sp.envp, "KEY 4") == NULL);
	env_destroy(&(sp.envp));
}
