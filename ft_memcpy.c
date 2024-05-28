/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:22:18 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/24 12:25:18 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*str2;

	if (!dest && !src)
		return (NULL);
	str = (char *)dest;
	str2 = (char *)src;
	while (n-- > 0)
		*str++ = *str2++;
	return (dest);
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("%s | %s\n", (char*)ft_memcpy(av[1], av[2], ft_strlen(av[1])),
//		(char*)memcpy(av[1], av[2], ft_strlen(av[1])));
// 	printf("%s\n", ft_memcpy(av[1], av[2], ft_strlen(av[1])) == memcpy(av[1],
//			av[2], ft_strlen(av[1])) ? "OK" : "KO");
// 	return (0);
// }