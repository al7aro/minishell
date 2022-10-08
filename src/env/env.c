/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:06:48 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/08 17:19:28 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "env_default.h"


/*
 * MAN getenv
 * minishell can be started without access to previous shell
 * in that case default env should be created
 * */
t_error_code	env_init(t_env_list *env)
{
	if (ERROR == env_set(env, PATH_KEY, getenv(PATH_KEY)))
		return (ERROR);
	if (ERROR == env_set(env, BIN_KEY, getenv(BIN_KEY)))
		return (ERROR);
	if (ERROR == env_set(env, HOME_KEY, getenv(HOME_KEY)))
		return (ERROR);
	if (ERROR == env_set(env, PWD_KEY, getenv(PWD_KEY)))
		return (ERROR);
	if (ERROR == env_set(env, PWD_OLD_KEY, getenv(PWD_OLD_KEY)))
		return (ERROR);
	if (ERROR == env_set(env, USER_KEY, getenv(USER_KEY)))
		return (ERROR);
	return (SUCCESS);
}

char			*env_get(t_env_list *env_lst, char *key)
{
	t_dll	*env_dll;
	t_env	*env;

	if (!env_lst || !key)
		return (NULL);
	env_dll = env_list_get_node(env_lst);
	while (env_dll)
	{
		env = (t_env *)(env_dll->value);
		if (ft_strcmp(key, env->key))
			return (env->value);
		env_dll = env_dll->next;
	}
	return (NULL);
}

t_error_code	env_set(t_env_list *env_lst, char *key, char *value)
{
	t_dll	*env_dll;
	t_env	*env;

	if (!env_lst || !key)
		return (ERROR);
	env_dll = env_list_get_node(env_lst);
	while (env_dll)
	{
		env = (t_env *)(env_dll->value);
		if (!ft_strcmp(key, env->key))
		{
			env->value = value;
			return (SUCCESS);
		}
		env_dll = env_dll->next;
	}
	env_list_add_last(env_lst, env_create(key, value));
	return (SUCCESS);
}

void	env_unset(t_env_list *env_lst, char *key)
{
	t_dll	*env_dll;
	t_env	*env;

	if (!env_lst || !key)
		return ;
	env_dll = env_list_get_node(env_lst);
	while (env_dll)
	{
		env = (t_env *)(env_dll->value);
		if (ft_strcmp(key, env->key))
		{
			env->value = "";
			return ;
		}
		env_dll = env_dll->next;
	}
}
