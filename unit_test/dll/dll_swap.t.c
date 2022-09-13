/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_swap.t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:54:12 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void	test_dll_swap_value(void)
{
	int		a;
	int		b;
	t_dll	e1;
	t_dll	e2;

	a = 2;
	b = 55;
	e1.value = &a;
	e2.value = &b;
	dll_swap_value(&e1, &e2);
	CU_ASSERT(*(int *)(e1.value) == 55);
	CU_ASSERT(*(int *)(e2.value) == 2);
}
