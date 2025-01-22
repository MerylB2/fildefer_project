/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:20:29 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:20:35 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*ptr_s;

	i = 0;
	ptr_s = (char *)s;
	while (ptr_s[i])
	{
		if (ptr_s[i] != (unsigned char)c)
			i++;
		else
			break ;
	}
	if (s[i] == (unsigned char)c || !c)
		return (&ptr_s[i]);
	return (NULL);
}
