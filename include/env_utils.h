/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:15:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/15 21:18:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "error_code.h"
# include "cmd.h"

char			*get_key_value_pair(char *key, char *value);
t_error_code	new_var(t_cmd *sp, char *key, char *value);
t_bool			key_compare(char *env, char *key);
char			*get_value(char *env_var);
int				env_size(char **envp);

#endif
