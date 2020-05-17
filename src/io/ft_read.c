/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io/ft_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Functions used from <stdlib.h>:
**	-	void	read(int fd, char* buffer, size_t n);
*/
#include <unistd.h>

#include "libft_memory.h"
#include "libft_string.h"
#include "libft_io.h"



static int	ft_readfile_error(int result, char **file)
{
	if (result < 0)
	{
		if (*file)
		{
			ft_memfree(*file);
			*file = NULL;
		}
		return (ERROR);
	}
	else
		return (OK);
}

int			ft_readfile(int const fd, char **file, t_size max)
{
	int		result;
	char	buffer[BUFF_SIZE + 1];
	char	*temp;
	t_size	length;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (file == NULL)
		return (ERROR);
#endif
	if (!(*file = ft_strnew(1)))
		return (ERROR);
	buffer[BUFF_SIZE] = '\0';
	length = 0;
	while ((result = read(fd, buffer, BUFF_SIZE)) > 0 &&
		(length += result) < max)
	{
		temp = *file;
		if (result < BUFF_SIZE)
			buffer[result] = '\0';
		if (!(*file = ft_strjoin(temp, buffer)))
			return (ERROR);
		ft_memfree(temp);
	}
	return (ft_readfile_error(result, file));
}



int			ft_readlines(int const fd, char ***strls)
{
	return (fd || strls); // TODO implement
}
