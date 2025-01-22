/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:23:37 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:23:40 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	i = ft_strlen(s);
	ptr_s = (char *)s;
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (ptr_s[i] == (unsigned char)c)
			return (&ptr_s[i]);
		i--;
	}
	return (NULL);
}
