/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:54:24 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/08 20:57:25 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "dll.h"
#include "error_code.h"
#include "libft.h"

typedef struct	s_env
{
	char	*key;
	char	*value;
}				t_env;

t_env	*env_create(char *key, char *value);
void	env_destroy(t_env **env);

#endif
