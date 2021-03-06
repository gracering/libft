/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list/ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_list.h"



s_list	*ft_lstnew(void *item, t_size item_size)
{
	s_list *result;

	if (!(result = (s_list *)ft_memalloc(sizeof(s_list))))
		return (NULL);
	result->item = item;
	result->item_size = (item ? item_size : 0);
	result->next = NULL;
	return (result);
}
