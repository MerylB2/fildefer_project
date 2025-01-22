/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:20:48 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:20:53 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		n;
	char		*dup;

	n = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(char) * (n));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, n);
	return (dup);
}
