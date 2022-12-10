/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:21:18 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/01 22:34:02 by r3dc4t-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "shell_op.h"
# include "error_code.h"
# include "libft.h"
# include "tab.h"
# include "macro.h"
# include "expander.h"

t_error_code	reader_get_tab(t_shell_op *sp);
t_error_code	reader_get_tab_from_file(t_shell_op *sp);
t_error_code	reader_get_tab_from_cli(t_shell_op *sp);
t_error_code	reader_split_by_token(char *str, char ***ret);
t_bool			reader_is_special(char *str);
t_bool			reader_is_dquote(char c);
t_bool			reader_is_squote(char c);
t_bool			reader_is_space(char c);
char			reader_is_del(char c, char del);
char			*reader_get_quote_prompt(char c);

#endif
