/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:31:58 by yoav              #+#    #+#             */
/*   Updated: 2022/09/14 08:48:39 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_OP_H
# define SHELL_OP_H

# include "error_code.h"
# include "libft.h"
# include "token_list.h"

typedef struct s_shell_op
{
	char			**input;
	t_token_list	*token_list;
}	t_shell_op;

#endif
