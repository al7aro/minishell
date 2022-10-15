/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:07:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 01:18:23 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

//easy version
void	env_unsetvar(char ***env, char *key)
{
	int		i;
	int		esize;

	i = 0;
	esize = env_size(*env);
	while (*(*env + i))
	{
		if (key_compare(*(*env + i), key))
		{
			free(*(*env + i));
			*(*env + i) = *(*env + esize - 1);
			*(*env + esize - 1) = NULL;
			return ;
		}
		i++;
	}
}

char	*env_getvar(char ***env, char *key)
{
	while (**env)
	{
		if (key_compare(**env, key))
			return (get_value(**env));
		(*env)++;
	}
	return (NULL);
}

t_error_code	env_setvar(char ***env, char *key, char *value)
{
	char	i;

	i = 0;
	if (*env)
	{
		while (*(*env + i))
		{
			if (key_compare(*(*env + i), key))
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
	if (!envp)
		return (tab_create(env, 1));
	esize = env_size(envp);
	err = tab_create(env, esize);
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
