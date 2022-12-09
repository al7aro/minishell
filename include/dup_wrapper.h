/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:58:41 by yoav              #+#    #+#             */
/*   Updated: 2022/12/09 15:55:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUP_WRAPPER_H
# define DUP_WRAPPER_H

# include <unistd.h>

# include "error_code.h"

t_error_code	dup_wrapper(int src, int dest);

#endif
