/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:14:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 22:14:30 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_key_value_pair(char *key, char *value)
{
	char	*pair;
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	pair = ft_strjoin(tmp, value);
	free(tmp);
	return (pair);
}

t_error_code	new_var(char ***env, char *key, char *value)
{
	if (!*env)
	{
		*env = (char **)malloc(sizeof(char *) + 1);
		*(*env + 1) = NULL;
	}
	return (tab_add(&(*env), get_key_value_pair(key, value)));
}

int	env_size(char **envp)
{
	int	env_size;

	if (!envp)
		return (0);
	env_size = 0;
	while (*(envp + env_size))
		env_size++;
	return (env_size);
}

char	*get_value(char *env_var)
{
	char	*pos;

	pos = ft_strchr((const char *)env_var, '=');
	return (pos + 1);
}

t_bool	key_compare(char *env, char *key)
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
