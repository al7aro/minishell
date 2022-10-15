/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:07:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 21:20:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

//easy version
void	env_unsetvar(t_cmd *sp, char *key)
{
	int		i;
	int		esize;
	char	**env;

	i = 0;
	esize = env_size(sp->env);
	env = sp->env;
	while (*(env + i))
	{
		if (key_compare(*(env + i), key))
		{
			free(*(env + i));
			*(env + i) = *(env + esize - 1);
			*(env + esize - 1) = NULL;
			return ;
		}
		i++;
	}
}

char	*env_getvar(t_cmd *sp, char *key)
{
	char	**env;

	env = sp->env;
	while (*env)
	{
		if (key_compare(*env, key))
			return (get_value(*env));
		env++;
	}
	return (NULL);
}

t_error_code	env_setvar(t_cmd *sp, char *key, char *value)
{
	char	**env;
	char	i;

	i = 0;
	env = sp->env;
	if (env)
	{
		while (*(env + i))
		{
			if (key_compare(*(env + i), key))
			{
				free(*(env + i));
				*(env + i) = get_key_value_pair(key, value);
				return (SUCCESS);
			}
			i++;
		}
	}
	new_var(sp, key, value);
	return (SUCCESS);
}

t_error_code	env_initenv(t_cmd *sp, char **envp)
{
	t_error_code	err;
	int				esize;
	int				i;

	i = 0;
	if (!envp)
		return (tab_create(&sp->env, 1));
	esize = env_size(envp);
	err = tab_create(&sp->env, esize);
	if (SUCCESS != err)
		return (err);
	*(sp->env + esize) = NULL;
	while (i < esize)
	{
		*(sp->env + i) = ft_strdup(*(envp + i));
		i++;
	}
	return (SUCCESS);
}
