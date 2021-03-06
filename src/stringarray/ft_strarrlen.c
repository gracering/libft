/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringarray/ft_strarrlen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stringarray.h"



t_u32		ft_strarrlen(char const** strarr)
{
	t_u32		i;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (strarr == NULL)
		return (0);
#endif
	i = 0;
	while (strarr[i])
	{
		++i;
	}
	return (i);
}
