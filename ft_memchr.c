/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:31:52 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/24 12:43:07 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

/*int	main(int ac, char **av)
{
	(void)ac;
	printf("%s | %s\n", (char*)ft_memchr(av[1], av[2][0], ft_strlen(av[1])),
		(char*)memchr(av[1], av[2][0], ft_strlen(av[1])));
	printf("%s\n", ft_memchr(av[1], av[2][0], ft_strlen(av[1])) == memchr(av[1],
			av[2][0], ft_strlen(av[1])) ? "OK" : "KO");
	return (0);
}*/