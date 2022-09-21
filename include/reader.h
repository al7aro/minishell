/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:21:18 by al7aro            #+#    #+#             */
/*   Updated: 2022/09/21 13:00:21 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "error_code.h"
# include "libft.h"
# include "tab.h"
# include "macro.h"

t_error_code	reader_split_arg(char *str, char ***ret);
void			reader_arg(int argc, char **argv);
t_error_code	reader(char ***ret);
int				is_special(char *str);
int				is_dquote(char c);
int				is_squote(char c);
int				is_space(char c);

#endif
