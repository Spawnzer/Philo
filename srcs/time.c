/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:08 by adubeau           #+#    #+#             */
/*   Updated: 2022/03/08 10:10:16 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep(long long t, t_state *state)
{
	long long i;

	i = ft_timestamp();
	while (!(state->rip))
	{
		if (ft_time_diff(i, ft_timestamp()) >= t)
			break;
		usleep(50);
	}
}

long long	ft_time_diff(long long past, long long present)
{
	return (present - past);
}

long long	ft_timestamp()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
