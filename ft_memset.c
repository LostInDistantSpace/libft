/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:11:54 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 15:46:57 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = malloc(sizeof(char) * 5);
	str[0] = 'P';
	str[1] = 'a';
	str[2] = 'b';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';
	printf("%s\n", str);
	memset(str, 'u', 3);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/