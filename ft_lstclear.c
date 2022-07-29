/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:09:18 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 21:09:19 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del || !(*lst))
		return ;
	tmp = *lst;
	if (tmp->next != NULL)
	{
		*lst = tmp->next;
		ft_lstclear(lst, del);
	}
	if (tmp->content)
		del(tmp->content);
	free(tmp);
	*lst = NULL;
}
