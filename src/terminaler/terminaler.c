/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminaler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:11:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/12/13 11:14:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminaler.h"

t_error_code	terminaler_create(t_terminaler **ret)
{
	*ret = ft_calloc(1, sizeof(t_terminaler));
	if (!(*ret))
		return (ALLOCATION_ERROR);
	terminaler_init(*ret);
	return (SUCCESS);
}

void	terminaler_destroy(t_terminaler **obj)
{
	terminaler_close(*obj);
	ft_bzero(*obj, sizeof(t_terminaler));
	free(*obj);
	*obj = NULL;
}

void	terminaler_init(t_terminaler *t)
{
	t->term_fd = open("/dev/tty", O_RDWR);
	t->stderr_fd = dup(STDERR_FILENO);
	t->stdout_fd = dup(STDOUT_FILENO);
	t->null_fd = open("/dev/null", O_RDONLY);
}

void	terminaler_close(t_terminaler *t)
{
	if (ERROR != t->term_fd)
		close(t->term_fd);
	if (ERROR != t->stderr_fd)
		close(t->stderr_fd);
	if (ERROR != t->stdout_fd)
		close(t->stdout_fd);
	if (ERROR != t->null_fd)
		close(t->null_fd);
	if (t->should_close_stdout)
		close(STDOUT_FILENO);
}
