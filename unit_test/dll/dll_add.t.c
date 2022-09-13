/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add.t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:17:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/13 10:35:26 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void	test_dll_add_after(void)
{
	int i1 = 1;
	int i2 = 2;
	t_dll *lst = dll_create_elem(&i1);
	t_dll *new = dll_create_elem(&i2);

	dll_add_after(lst, new);
	CU_ASSERT_EQUAL(*(int *)lst->value, 1);
	CU_ASSERT_EQUAL(*(int *)lst->next->value, 2);
	CU_ASSERT_EQUAL(lst->next, new);
	dll_clear_list(lst, NULL);
}

void	test_dll_add_before(void)
{
	int i1 = 1;
	int i2 = 2;
	t_dll *lst = dll_create_elem(&i1);
	t_dll *new = dll_create_elem(&i2);

	dll_add_before(lst, new);
	CU_ASSERT_EQUAL(*(int *)lst->value, 2);
	CU_ASSERT_EQUAL(*(int *)lst->next->value, 1);
	dll_clear_list(lst, NULL);
}

void	test_dll_add_last(void)
{
	int i1 = 1;
	int i2 = 2;
	t_dll *lst = NULL;

	dll_add_last(&lst, dll_create_elem(&i1));
	dll_add_last(&lst, dll_create_elem(&i2));
	CU_ASSERT_EQUAL(*(int *)lst->value, 1);
	CU_ASSERT_EQUAL(*(int *)lst->next->value, 2);
	dll_clear_list(lst, NULL);
}

