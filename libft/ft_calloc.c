/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:12:30 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:12:31 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*nptr;
	size_t	i;

	if (n == 0 || size == 0)
		return (malloc(0));
	nptr = malloc(n * size);
	if (n > ((size_t)-1) / size)
		return (NULL);
	if (!nptr)
		return (NULL);
	i = 0;
	while (i < (n * size))
		((char *)nptr)[i++] = 0;
	return (nptr);
}
