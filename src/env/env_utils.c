/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:06:13 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/08 20:06:13 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

t_env	*env_create(char *key, char *value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->value = value;
	env->key = key;
	return (env);
}

void	env_destroy(t_env *env)
{
	free(env);
}

void	env_list_print(t_env_list *env_lst)
{
	t_dll	*env_dll;
	t_env	*env;
	if (!env_lst)
		return ;
	env_dll = env_list_get_node(env_lst);
	while (env_dll)
	{
		env = (t_env *)(env_dll->value);
		printf("%s: [%s]\n", env->key, env->value);
	}
}
