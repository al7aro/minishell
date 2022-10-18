/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:24:16 by alopez-g          #+#    #+#             */
/*   Updated: 2022/10/16 09:27:31 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdlib.h>
# include <unistd.h>

# include "error_code.h"
# include "libft.h"
# include "macro.h"
# include "env.h"

char	*expander_expand(char **env, char *str);

#endif
