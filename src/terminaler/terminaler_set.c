/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminaler_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:11:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/13 11:08:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminaler.h"

void	terminaler_set_out_to_null(t_terminaler *t)
{
	t->should_close_stdout = TRUE;
	dup_wrapper(t->null_fd, STDOUT_FILENO);
}

void	terminaler_set_out_to_err(t_terminaler *t)
{
	t->should_close_stdout = TRUE;
	dup_wrapper(t->stderr_fd, STDOUT_FILENO);
}

void	terminaler_set_out_to_out(t_terminaler *t)
{
	t->should_close_stdout = TRUE;
	dup_wrapper(t->stdout_fd, STDOUT_FILENO);
}
