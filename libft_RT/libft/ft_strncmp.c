/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnematan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:16:17 by dnematan          #+#    #+#             */
/*   Updated: 2016/11/17 16:16:37 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (*(unsigned char *)&s1[i] < *(unsigned char *)&s2[i])
			return (-1);
		if (*(unsigned char *)&s1[i] > *(unsigned char *)&s2[i])
			return (1);
		i++;
	}
	return (0);
}
