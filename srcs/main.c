/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:09:23 by adubeau           #+#    #+#             */
/*   Updated: 2022/03/08 13:22:55 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_state(t_state *state, int ac, char **av)
{
	state->nb_philos = ft_atoi(av[1]);
	if (state->nb_philos > 255)
		ft_exit_with_error(1, "Erreur, veuillez rééssayer avec moins de 256 philos");
	state->time_die = ft_atoi(av[2]);
	state->time_eat = ft_atoi(av[3]);
	state->time_sleep = ft_atoi(av[4]);
	state->rip = 0;
	if (ac == 6)
		state->n_to_eat = ft_atoi(av[5]);
	else
		state->n_to_eat = -1;
}

void	ft_init_philo(t_state *state)
{
	int i;

	i = 0;
	while (i < state->nb_philos)
	{
		state->philo[i].id = i;
		state->philo[i].dead = 0;
		state->philo[i].left = i;
		state->philo[i].right = (i + 1) % state->nb_philos;
		state->philo[i].last_meal = 0;
		state->philo[i].state = state;
		i++;
	}

}

int main(int ac, char **av)
{
	t_state state;
	if (ac != 5 && ac != 6)
		ft_exit_with_error(1, "Erreur, mauvais nombre d'argument");
	ft_init_state(&state, ac, av);
	ft_init_philo(&state);
	return (0);
}
