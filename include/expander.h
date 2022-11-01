/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:24:16 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/01 22:36:35 by r3dc4t-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdlib.h>
# include <unistd.h>

# include "error_code.h"
# include "shell_op.h"
# include "libft.h"
# include "macro.h"
# include "env.h"

char			*expander_expand_var(t_shell_op *sp, char *str);
t_error_code	expander_remove_all_quotes(t_shell_op *sp);
char			*expander_remove_line_quotes(char *str);
char			*str_insert_char_after(char *str, char c, size_t pos);
t_bool			is_end_of_var_name(char c);
t_bool			is_valid_for_expansion(char *str);

#endif
