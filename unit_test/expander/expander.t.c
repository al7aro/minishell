/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:25:13 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/12 10:05:23 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test_util.h"
#include "unit_test.h"
#include "expander.h"

void	test_expander(void)
{
	t_shell_op	sp;

	env_initenv(&sp.envp, 0);
	env_setvar(&sp.envp, "USER", "al7aro");
	env_setvar(&sp.envp, "PATH", "/bin/");
	env_setvar(&sp.envp, "NAME", "ALVARO LOPEZ");
	env_setvar(&sp.envp, "PWD", "~/");
	env_setvar(&sp.envp, "OLD_PWD", "~/Documents/");
	expander_expand(sp.envp, "Your name is $USER :D");
	expander_expand(sp.envp, "Your name is $PATH :D $PWD $OLD_PWD $USER");
	env_destroy(&(sp.envp));
}
