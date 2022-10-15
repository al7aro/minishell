/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:07:51 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 20:24:55 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	*get_key_value_pair(char *key, char *value)
{
	char	*pair;
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	pair = ft_strjoin(tmp, value);
	free(tmp);
	return (pair);
}

static t_error_code	new_var(t_cmd *sp, char *key, char *value)
{
	if (!sp->env)
	{
		sp->env = (char **)malloc(sizeof(char *) + 1);
		*(sp->env + 1) = NULL;
	}
	return (tab_add(&sp->env, get_key_value_pair(key, value)));
}

static int	env_size(char **envp)
{
	int	env_size;

	if (!envp)
		return (0);
	env_size = 0;
	while (*(envp + env_size))
		env_size++;
	return (env_size);
}

static char	*get_value(char *env_var)
{
	char	*pos;

	pos = ft_strchr((const char *)env_var, '=');
	return (pos + 1);
}

static t_bool	key_compare(char *env, char *key)
{
	char	*pos;
	char	i;

	pos = ft_strchr((const char *)env, '=');
	i = 0;
	while ((env + i) != pos && *(key + i))
	{
		if (*(env + i) != *(key + i))
			return (FALSE);
		i++;
	}
	if (*(key + i) == '\0' && *(env + i) == '=' )
		return (TRUE);
	return (FALSE);
}

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
	if (env + i)
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
	sp->env = 0;
	if (!envp)
		return (ERROR);
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

char	**env_getenv(t_cmd *sp)
{
	return (sp->env);
}

void	env_destroyenv(t_cmd *sp)
{
	tab_deep_destroy(&(sp->env));
}
