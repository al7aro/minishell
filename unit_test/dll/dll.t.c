/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/12 09:42:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void test_dll_create_elem(void)
{
	int		i = 6;
	t_dll	*node;

	node = dll_create_elem(&i);
	CU_ASSERT_PTR_NOT_NULL(node);
	CU_ASSERT(*(int *)(node->value) == 6);
}
