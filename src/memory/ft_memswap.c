/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory/ft_memswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int			ft_memswap(void *ptr1, void *ptr2, t_size size)
{
	t_u8	*p1;
	t_u8	*p2;
	t_size	i;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (ptr1 == NULL || ptr2 == NULL)
		return (ERROR);
#endif
	if (ptr1 == ptr2)
		return (OK);
	else if (size == 1 && *(uint8_t*)(ptr1) == *(uint8_t*)(ptr2))
		return (OK);
	else if (size == 2 && *(uint16_t*)(ptr1) == *(uint16_t*)(ptr2))
		return (OK);
	else if (size == 4 && *(uint32_t*)(ptr1) == *(uint32_t*)(ptr2))
		return (OK);
	else if (size == 8 && *(uint64_t*)(ptr1) == *(uint64_t*)(ptr2))
		return (OK);
	else if (ptr1 && ptr2)
	{
		p1 = (t_u8*)(ptr1);
		p2 = (t_u8*)(ptr2);
		i = 0;
		while (i < size)
		{
			p1[i] = (p1[i] ^ p2[i]);
			p2[i] = (p2[i] ^ p1[i]);
			p1[i] = (p1[i] ^ p2[i]);
			++i;
		}
		return (OK);
	}
	return (ERROR);
}
