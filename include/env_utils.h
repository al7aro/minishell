/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:15:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/04 15:07:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "macro.h"

char			*get_key_value_pair(char *key, char *value);
t_error_code	new_var(char ***env, char *key, char *value);
t_bool			is_key(char *env, char *key);
char			*get_value(char *env_var);
void			fill_mem(char **to_empty, char **new_element);
t_bool			env_is_key_valid(char *key);

#endif
