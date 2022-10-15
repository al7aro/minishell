/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:51:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 00:53:30 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "error_code.h"
# include "tab.h"
# include "env_utils.h"

t_error_code	env_initenv(char ***env, char **envp);
char			*env_getvar(char ***env, char *key);
t_error_code	env_setvar(char ***env, char *key, char *value);
void			env_unsetvar(char ***env, char *key);
void			env_destroy(char ***env);

char			**env_getenv(char ***env);

#endif
