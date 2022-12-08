/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:07:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/04 15:12:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_unsetvar(char **env, char *key)
{
	int		i;
	int		esize;

	i = 0;
	if (!env)
		return ;
	esize = tab_count(env);
	while (*(env + i))
	{
		if (is_key(*(env + i), key))
			return (fill_mem(env + i, env + esize - 1));
		i++;
	}
}

char	*env_getvar(char **env, char *key)
{
	if (!env)
		return (NULL);
	while (*env)
	{
		if (is_key(*env, key))
			return (get_value(*env));
		env++;
	}
	return (NULL);
}

t_error_code	env_setvar(char ***env, char *key, char *value)
{
	char	i;

	i = 0;
	if (!env_is_key_valid(key))
		return (ERROR);
	if (*env)
	{
		while (*(*env + i))
		{
			if (is_key(*(*env + i), key))
			{
				free(*(*env + i));
				*(*env + i) = get_key_value_pair(key, value);
				return (SUCCESS);
			}
			i++;
		}
	}
	new_var(env, key, value);
	return (SUCCESS);
}

t_error_code	env_initenv(char ***env, char **envp)
{
	t_error_code	err;
	int				esize;
	int				i;

	i = 0;
	if (!envp || !(*envp))
		return (tab_create(env, 1));
	else
	{
		esize = tab_count(envp);
		err = tab_create(env, esize);
	}
	if (SUCCESS != err)
		return (err);
	*(*env + esize) = NULL;
	while (i < esize)
	{
		*(*env + i) = ft_strdup(*(envp + i));
		i++;
	}
	return (SUCCESS);
}

void	env_destroy(char ***env)
{
	tab_deep_destroy(env);
}
