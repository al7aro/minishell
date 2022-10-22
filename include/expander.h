/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:24:16 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/22 20:55:23 by alopez-g         ###   ########.fr       */
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

char	*expander_remove_quotes(char *str);
char	*expander_expand_var(t_shell_op sp, char *str);

#endif
