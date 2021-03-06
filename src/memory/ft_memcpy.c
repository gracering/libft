/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory/ft_memcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"



void	*ft_memcpy(void *dest, void const *src, t_size n)
{
	t_u8	*result;
	t_u8	*source;
	t_size	i;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
#endif
	result = (t_u8 *)dest;
	source = (t_u8 *)src;
	i = 0;
	while (i < n)
	{
		result[i] = source[i];
		++i;
	}
	return (dest);
}



void	*ft_memccpy(void *dest, void const *src, t_u8 byte, t_size n)
{
	t_u8	*result;
	t_u8	*source;
	t_size	i;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (dest == NULL || src == NULL)
		return (NULL);
#endif
	result = (t_u8 *)dest;
	source = (t_u8 *)src;
	i = 0;
	while (source[i] != byte)
	{
		if (i == n)
			return (NULL);
		result[i] = source[i];
		++i;
	}
	result[i] = byte;
	return (result + i + 1);
}
