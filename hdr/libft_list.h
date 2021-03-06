/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
#define LIBFT_LIST_H

/*
** ************************************************************************** *|
**                                   Includes                                 *|
** ************************************************************************** *|
*/

#include "libft.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
** ************************************************************************** *|
**                                    Macros                                  *|
** ************************************************************************** *|
*/

#define List_New			ft_lstnew
#define List_Add			ft_lstadd
#define List_Append			ft_lstappend
#define List_Insert			ft_lstinsert
#define List_Copy			ft_lstcpy
#define List_Remove			ft_lstdelone
#define List_Delete			ft_lstdel
#define List_Pop			ft_lstpop

#define List_Size			ft_lstsize
#define List_Get			ft_lstget
#define List_Find			ft_lstfind

#define List_Sub			ft_lstsub
#define List_Iterate		ft_lstiter
#define List_Iterate_I		ft_lstiteri
#define List_Map			ft_lstmap
#define List_Map_I			ft_lstmapi
#define List_ToArray		ft_lst_to_array
#define List_ToTuple		ft_lst_to_tuple



/*
** ************************************************************************** *|
**                                 Definitions                                *|
** ************************************************************************** *|
*/

typedef struct		s_tuple_
{
	void			*items;
	t_size			item_size;
	t_size			length;
}					s_tuple;

typedef struct		s_list_
{
	void			*item;
	t_size			item_size;
	struct s_list_	*next;
}					s_list;

/*
**	typedef void	(*f_list_delete)(void *, t_size);
**	typedef void	(*f_list_iterate)(s_list *);
**	typedef s_list*	(*f_list_map)(s_list *);
*/



/*
** ************************************************************************** *|
**                             Basic List Operations                          *|
** ************************************************************************** *|
*/

/*
**	Allocates a new linked list element, and feeds it the given 'item' pointer
**	and the given 'item_size' (if 'item' is NULL, item_size is set to 0).
*/
s_list				*ft_lstnew(void *item, t_size item_size);

/*
**	Inserts a new element of a list 'elem' at the pointer '*alst',
**	chaining this new element with the next element of this list.
*/
void				ft_lstadd(s_list **alst, s_list *elem);

/*
**	Appends the element 'elem' to the end of the list starting at '*alst'.
**	If '*alst' is NULL, it'll append 'elem' at index 0, creating a 1-elem list.
*/
void				ft_lstappend(s_list **alst, s_list *elem);

/*
**	Inserts the given element 'elem' at the given 'index' of the list '*alst'.
**	If 'index' is too large, the 'elem' is appended to the end of the list.
**	If 'elem' is NULL, then nothing is done by this function.
*/
void				ft_lstinsert(s_list **alst, s_list *elem, t_u32 index);

/*
**	Returns a newly allocated copy of the given linked list 'lst'.
**	The underlying data is not copied, only the s_list* structs are malloc'ed.
*/
s_list				*ft_lstcpy(s_list *lst);

/*
**	Deletes the given element pointed to by 'alst' with the function 'del',
**	and then frees memory and sets '*alst' as a NULL pointer.
*/
void				ft_lstdelone(s_list **alst, void (*del)(void *, t_size));

/*
**	Deletes all the elements in the list starting at '*alst',
**	calls 'del' and frees memory for each, and lastly sets '*alst' as NULL.
*/
void				ft_lstdel(s_list **alst, void (*del)(void *, t_size));

/*
**	Deletes the last element in the list starting at '*alst', calling 'del'
**	and freeing that element, and setting the preceding 'lst->next' as NULL.
*/
void				ft_lstpop(s_list **alst, void (*del)(void *, t_size));



/*
** ************************************************************************** *|
**                                 List Checks                                *|
** ************************************************************************** *|
*/

/*
**	Returns the amount of elements in the given list 'lst'.
*/
t_u32				ft_lstsize(s_list *lst);

/*
**	Returns the 'index'th element in the given list 'lst'.
**	Will return NULL if 'index' is beyond the last element.
*/
s_list				*ft_lstget(s_list *lst, t_u32 index);

/*
**	Returns the first encountered element of the given linked list 'lst'
**	for which (lst.item == query), matching only the pointers, not the data.
*/
s_list				*ft_lstfind(s_list *lst, void const *query);



/*
** ************************************************************************** *|
**                             Other List Operations                          *|
** ************************************************************************** *|
*/

/*
**	Returns a newly allocated subsection of the given list 'lst',
**	starting at 'index', and copying 'n' list elements (not their 'item' data).
**	Will return NULL if 'index' is too large or if 'n' is 0.
**	If 'index' is valid but the list is not large enough for 'n',
**	then the resulting list will have fewer than 'n' elements.
*/
s_list				*ft_lstsub(s_list *lst, t_u32 index, t_u32 n);

/*
**	Iterates upon each element of the given list 'lst',
**	applying the given function 'f' to each of its elements.
*/
void				ft_lstiter(s_list *lst,
					void (*f)(s_list *elem));
void				ft_lstiteri(s_list *lst,
					void (*f)(s_list *elem, t_u32 index));

/*
**	Creates a new list which is the result of applying
**	the given function 'f' to each element of 'lst'.
*/
s_list				*ft_lstmap(s_list *lst,
					s_list *(*f)(s_list *elem));
s_list				*ft_lstmapi(s_list *lst,
					s_list *(*f)(s_list *elem, t_u32 index));

/*
**	Creates a new jagged array (2D pointer array) from the given list '*alst'.
**	The top-level pointer array is terminated by a NULL pointer.
**	The underlying 'lst->item' data is not copied, only the pointers are.
*/
void				**ft_lst_to_array(s_list **alst);

/*
**	Creates a new contiguous memory array from the given linked list.
**	It sets this array pointer to the 'items' pointer of the given 'tuple'.
**	It also sets the 'item_size' and 'length' fields of this 'tuple'.
**	Returns NULL if any elements of '*alst' are of unequal 'lst->item_size'.
*/
s_tuple				*ft_lst_to_tuple(s_list **alst, s_tuple *tuple);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
