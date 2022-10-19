/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:07:07 by al7aro            #+#    #+#             */
/*   Updated: 2022/10/18 22:07:07 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"


static char	*remove_pair_from_str(char *str, char *c1, char *c2)
{
	size_t	len;
	size_t	i_ret;
	char	*ret;
	char	*tmp;

	tmp = str;
	len = ft_strlen(str) - 1;
	ret = (char *)malloc(sizeof(char) * len);
	*(ret + len) = 0;
	i_ret = 0;
	while (*(str))
		if (str++ !=  c1 && str - 1 != c2)
			*(ret + i_ret++) = *(str - 1);
	free(tmp);
	return (ret);
}


char	*expander_remove_quotes(char *str)
{
	char	*ret;

	(void)str;
	ret = ft_strdup("Alv-(aro");
	printf("%s\n", ret);
	ret = remove_pair_from_str(ret, ret + 3, ret + 4);
	printf("%s\n", ret);
	return (ret);
}
