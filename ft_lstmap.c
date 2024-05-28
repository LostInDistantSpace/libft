/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:04:10 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/28 11:49:07 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_iter(t_list *lst, void *(*f)(void *),
		void (*del)(void *), t_list *head)
{
	t_list	*new_elem;
	t_list	*tmp;
	void	*content;

	tmp = head;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp->next = new_elem;
		tmp = new_elem;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	head = ft_lstnew(content);
	if (!head)
	{
		del(content);
		return (NULL);
	}
	lst = lst->next;
	return (ft_lstmap_iter(lst, f, del, head));
}
