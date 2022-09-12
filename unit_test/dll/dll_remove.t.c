/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_remove.t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:17:36 by yoav              #+#    #+#             */
/*   Updated: 2022/09/12 16:42:18 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"
#include "unit_test.h"

void	test_dll_remove_elem(void)
{
	int i1 = 1;
	int i2 = 2;
	t_dll *tmp = NULL;
	t_dll *lst = dll_create_elem(&i1);
	t_dll *new = dll_create_elem(&i2);

	dll_add_last(&lst, new);
	tmp = dll_remove_elem(new);
	CU_ASSERT_EQUAL(*(int *)tmp->value, 2);
	CU_ASSERT_PTR_NULL(lst->next);
	dll_destroy_elem(lst);
	dll_destroy_elem(new);
}

void	test_dll_remove_first_elem(void)
{
	int i1 = 1;
	int i2 = 2;
	t_dll *tmp = NULL;
	t_dll *lst = dll_create_elem(&i1);
	t_dll *new = dll_create_elem(&i2);

	dll_add_last(&lst, new);
	tmp = dll_remove_first_elem(lst);
	CU_ASSERT_EQUAL(*(int *)tmp->value, 1);
	CU_ASSERT_PTR_NULL(lst->next);
	dll_destroy_elem(lst);
	dll_destroy_elem(new);
}

void	test_dll_remove_last_elem(void)
{
	int i1 = 1;
	int i2 = 2;
	t_dll *tmp = NULL;
	t_dll *lst = dll_create_elem(&i1);
	t_dll *new = dll_create_elem(&i2);

	dll_add_last(&lst, new);
	tmp = dll_remove_last_elem(lst);
	CU_ASSERT_EQUAL(*(int *)tmp->value, 2);
	CU_ASSERT_PTR_NULL(lst->next);
	dll_destroy_elem(lst);
	dll_destroy_elem(new);
}

