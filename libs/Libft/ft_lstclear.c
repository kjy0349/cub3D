/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:28:41 by soopark           #+#    #+#             */
/*   Updated: 2022/04/10 14:59:13 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_n;

	if (!lst)
		return ;
	while (*lst)
	{
		lst_n = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_n;
	}
}
