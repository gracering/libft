/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string/ft_strrep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_string.h"
#include "libft_stringarray.h"



char		*ft_strrep_char(char const *str, char const old, char const newchar)
{
	char	*result;
	t_size	i;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (old == newchar)
		return (ft_strdup(str));
	if (str == NULL)
		return (NULL);
#endif
	if (old == '\0')
		return (NULL);
	i = 0;
	while (str[i])
		++i;
	if (!(result = (char *)ft_memalloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = (str[i] == old) ? newchar : str[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}



char		*ft_strrep_charset(char const *str, char const *old, char const *newcharset)
{
	char	*result;
	t_size	i;
	t_size	j;
	int		c_index;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (old == newcharset)
		return (ft_strdup(str));
	if (str == NULL || old == NULL || newcharset == NULL)
		return (NULL);
#endif
	if (ft_strlen(old) != ft_strlen(newcharset))
		return (NULL);
	i = 0;
	while (old[i])
	{
		j = i;
		while (old[++j])
			if (old[i] == old[j])
				return (NULL);
		++i;
	}
	if (!(result = (char *)ft_memalloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if ((c_index = ft_strichr(old, str[i])) >= 0)
			result[i] = newcharset[c_index];
		++i;
	}
	result[i] = '\0';
	return (result);
}



char		*ft_strrep_str(char const *str, char const *old, char const *newstring)
{
	char	*result;
	char	**strarr;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (old == newstring)
		return (ft_strdup(str));
	if (str == NULL || old == NULL || newstring == NULL)
		return (NULL);
#endif
	strarr = ft_strsplit_str(str, old);
	result = ft_strarrjoin((const char **)strarr, newstring);
	ft_strarrdel(&strarr);
	return (result);
}



void		ft_strrep_char_inplace(char *str, char const old, char const newchar)
{
	t_size	i;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (str == NULL)
		return ;
#endif
	if (old == '\0')
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = newchar;
		++i;
	}
}



void		ft_strrep_charset_inplace(char *str, char const *old, char const *newchar)
{
	t_size	i;
	t_size	j;
	int		c_index;

#if LIBFTCONFIG_HANDLE_NULLPOINTERS
	if (str == NULL || old == NULL || newchar == NULL)
		return ;
#endif
	if (ft_strlen(old) != ft_strlen(newchar))
		return ;
	i = 0;
	while (old[i])
	{
		j = i;
		while (old[++j])
			if (old[i] == old[j])
				return ;
		++i;
	}
	i = 0;
	while (str[i])
	{
		if ((c_index = ft_strichr(old, str[i])) >= 0)
			str[i] = newchar[c_index];
		++i;
	}
}



void	ft_strrep_str_inplace(char **a_str, char const *old, char const *newstring)
{
	char	*tmp;
	tmp = ft_strrep_str(*a_str, old, newstring);
	ft_strdel(a_str);
	*a_str = tmp;
}
