/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:21:49 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:21:52 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (dsize == 0)
		return (s_len);
	if (dsize <= d_len)
		return (s_len + dsize);
	i = 0;
	while (src[i] && ((d_len + i) < (dsize - 1)))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (i < dsize)
		dest[d_len + i] = '\0';
	return (d_len + s_len);
}
