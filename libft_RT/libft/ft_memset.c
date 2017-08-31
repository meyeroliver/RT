/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnematan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:16:14 by dnematan          #+#    #+#             */
/*   Updated: 2016/11/17 16:16:34 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*character;

	if (len == 0)
	{
		return (b);
	}
	character = (unsigned char *)b;
	while (len--)
	{
		*character = (unsigned char)c;
		if (len)
			character++;
	}
	return (b);
}
