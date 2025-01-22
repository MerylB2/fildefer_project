/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:23:53 by cmetee-b          #+#    #+#             */
/*   Updated: 2024/11/28 16:24:11 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmer;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == end + 1)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]))
		end--;
	trimmer = ft_substr(s1, i, (end - i) + 1);
	if (!trimmer)
		return (NULL);
	return (trimmer);
}
