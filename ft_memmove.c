/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/21 16:11:42 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src > dest)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else if (dest > src)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}
/*
int	main(void)
{
	char	*src;
	char	*dst;

	src = (char *) malloc(10);
	dst = (char *) malloc(10);
	memset(src, 'a', 10);
	memset(dst, 'b', 10);
	printf("memmove test\n");
	ft_memmove(dst, src, 0);
	printf("memmove(dst, src, 0) = %s\n", dst);
	ft_memmove(dst, src, 10);
	printf("memmove(dst, src, 10) = %s\n", dst);
	ft_memmove(dst, src, 15);
	printf("memmove(dst, src, 15) = %s\n", dst);
	free(src);
	free(dst);
}
*/