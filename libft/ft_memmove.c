/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:18:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:18:12 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	if (!d && !s)
		return (NULL);
	if (src < dest && dest < (src + n))
		while (n--)
			dest[n] = src[n];
	else
		while (n--)
			*(dest++) = *(src++);
	return (d);
}
