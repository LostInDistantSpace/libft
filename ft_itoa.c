/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:46:52 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 15:25:08 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_size(long long int nb, long long int *size)
{
	if (nb == 0)
		*size = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		(*size)++;
	}
}

static void	ft_putnbr(long long int nb, char *tab, long long i)
{
	i = i - 1;
	tab[i] = (nb % 10) + 48;
	if (nb >= 10)
		ft_putnbr ((nb / 10), tab, i);
}

char	*ft_itoa(int n)
{
	long long	nb;
	long long	size;
	char		*tab;

	nb = n;
	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	ft_size(nb, &size);
	tab = malloc(sizeof(char) * size + 1);
	if (!tab)
		return (NULL);
	tab[0] = '-';
	ft_putnbr(nb, tab, size);
	tab[size] = '\0';
	return (tab);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("ft_itoa : %s\n", ft_itoa(ft_atoi(av[1])));
}*/