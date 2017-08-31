/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnematan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:16:14 by dnematan          #+#    #+#             */
/*   Updated: 2016/11/17 16:16:33 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		character;
	size_t		i;
	char		*s1;
	const char	*s2;

	i = 0;
	character = (unsigned char)c;
	s1 = (char*)dst;
	s2 = (char*)src;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == character)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
