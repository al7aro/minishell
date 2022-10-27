/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:26:56 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/25 09:48:18 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	is_end_of_var_name(char c)
{
	if (SPACE_CHAR == c
		|| R_BRACKET == c
		|| MINUS_CHAR == c
		|| EQUAL_CHAR == c
		|| SINGLE_QUOTE_CHAR == c
		|| DOUBLE_QUOTE_CHAR == c
		|| '\0' == c)
		return (TRUE);
	return (FALSE);
}
