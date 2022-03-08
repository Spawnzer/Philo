/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:08 by adubeau           #+#    #+#             */
/*   Updated: 2022/03/08 10:10:16 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_exit_with_error(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(fd, str[i++]);
	exit(1);
}

int	ft_atoi(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	if (!str)
		return (-1);
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		ft_exit_with_error(1, "Erreur, les valeurs ne peuvent être négatives\n");
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + (str[i++] - '0');
		else
			ft_exit_with_error(1, "Erreur, les valeurs doivent entrées en chiffres\n");
	}
	return (nb);
}		
