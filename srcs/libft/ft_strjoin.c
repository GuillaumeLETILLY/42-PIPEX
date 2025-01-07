/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <pymousss.dev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:21:10 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/06 14:21:51 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;
	char	*copy;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *)malloc(s1len + s2len + 1);
	if (!result)
		return (NULL);
	copy = result;
	while (*s1)
		*copy++ = *s1++;
	while (*s2)
		*copy++ = *s2++;
	*copy = '\0';
	return (result);
}
