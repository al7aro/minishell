/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 20:34:11 by alopez-g         ###   ########.fr       */
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
	env_setvar(&cmd, "KEY 0", "VALUE 0");
	env_setvar(&cmd, "KEY 1", "VALUE 1");
	env_setvar(&cmd, "KEY 2", "VALUE 2");
	env_setvar(&cmd, "KEY 3", "VALUE 3");
	env_setvar(&cmd, "KEY 4", "VALUE 4");
	env_unsetvar(&cmd, "KEY 4");
	env_unsetvar(&cmd, "KEY -1");
	env_setvar(&cmd, "KEY 5", "VALUE 5");
	env_setvar(&cmd, "KEY 5", "VALUE 5.2");
	env_setvar(&cmd, "KEY 6", "VALUE 6");
	env_unsetvar(&cmd, "KEY 6");
	env_setvar(&cmd, "KEY 7", "VALUE 7");
	env_setvar(&cmd, "KEY 8", "VALUE 8");
	env_setvar(&cmd, "KEY 9", "VALUE 9");
	tab_print(cmd.env);
	tab_deep_destroy(&cmd.env);
}
