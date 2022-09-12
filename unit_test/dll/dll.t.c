/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:21:17 by yoav              #+#    #+#             */
/*   Updated: 2022/09/12 15:17:49 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void test_dll_create_and_destroy_elem(void)
{
	int		i = 6;
	t_dll	*node;

	node = dll_create_elem(&i);
	CU_ASSERT_PTR_NOT_NULL(node);
	CU_ASSERT(*(int *)(node->value) == 6);
	dll_destroy_elem(node);
}

void test_dll_clear_list(void)
{
	int		i = 1;
	t_dll	*lst = NULL;
	
	dll_add_last(&lst, dll_create_elem(&i));
	dll_add_last(&lst, dll_create_elem(&i));
	dll_add_last(&lst, dll_create_elem(&i));
	dll_clear_list(lst);
}
