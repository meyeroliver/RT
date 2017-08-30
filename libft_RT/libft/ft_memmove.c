/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnematan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:16:14 by dnematan          #+#    #+#             */
/*   Updated: 2016/11/17 16:16:34 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp;
	const char	*tmp2;
	char		copy[len];

	i = 0;
	tmp = (char*)dst;
	tmp2 = (const char*)src;
	while (i < len)
	{
		copy[i] = tmp2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmp[i] = copy[i];
		i++;
	}
	return (dst);
}
