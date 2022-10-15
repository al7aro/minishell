/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:51:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 21:20:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "error_code.h"
# include "cmd.h"
# include "tab.h"
# include "env_utils.h"

t_error_code	env_initenv(t_cmd *sp, char **envp);
char			*env_getvar(t_cmd *sp, char *key);
t_error_code	env_setvar(t_cmd *sp, char *key, char *value);
void			env_unsetvar(t_cmd *sp, char *key);

void			env_destroyenv(t_cmd *sp);
char			**env_getenv(t_cmd *sp);

#endif
