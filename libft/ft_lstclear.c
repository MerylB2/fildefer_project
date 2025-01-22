/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:15:05 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:15:11 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mem;

	while (*lst)
	{
		mem = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = mem;
	}
	return ;
}
