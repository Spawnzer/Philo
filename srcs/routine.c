/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:09:23 by adubeau           #+#    #+#             */
/*   Updated: 2022/03/08 13:22:55 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_console(t_state *state, int id, char *str)
{
	long long	ct;

	ct = ft_timestamp() - state->start_time;
	pthread_mutex_lock(&(state->console));
	printf("%lld %d %s\n", ct, id, str);
	pthread_mutex_unlock(&(state->console));
	return ;
}

void	ft_eat(t_state *state, t_philo *philo)
{
//	ft_console(state, philo->id, "has picked up the fork to its left");
//	ft_console(state, philo->id, "has picked up the fork to its right");
	ft_console(state, philo->id, "is eating");
	ft_sleep(state->time_eat, state);
	philo->time_eaten++;
	philo->last_meal = ft_timestamp();
	pthread_mutex_unlock(&(state->forks[philo->left]));
	pthread_mutex_unlock(&(state->forks[philo->right]));
}

int	ft_can_eat(t_state *state, t_philo *philo)
{
	int left;
	int right;

	left = -1;
	right = -1;
	left = pthread_mutex_lock(&(state->forks[philo->left]));
	right = pthread_mutex_lock(&(state->forks[philo->right]));
	if (left == 0 && right == 0)
		return (1);
	else
	{
		if (left == 0)
			pthread_mutex_unlock(&(state->forks[philo->left]));
		if (right == 0)
			pthread_mutex_unlock(&(state->forks[philo->right]));
		return (0);
	}
}

void	*ft_action(void	*philosopher)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)philosopher;
	state = philo->state;
	if (philo->id % 2)
		usleep(25);
	while (!(state->rip))
	{	
		while(!(ft_can_eat(state, philo)))
			usleep(25);
		if (!(state->rip))
			ft_eat(state, philo);
		if (state->finished_eating)
			break ;
		if (!(state->rip))
			ft_console(state, philo->id, "is sleeping");
		ft_sleep(state->time_sleep, state);
		if (!(state->rip))
			ft_console(state, philo->id, "is thinking");
	}
	return (NULL);
}

void	ft_waiter(t_state *state, t_philo *philo)
{
	int i;

	while(!(state->finished_eating))
	{
		i = 0;
		while (i < state->nb_philos && !(state->rip))
		{
			pthread_mutex_lock(&(state->waiter));
			if (ft_time_diff(philo[i].last_meal, ft_timestamp()) > state->time_die)
			{
				ft_console(state, i, "has died");
				state->rip = 1;
			}
			i++;
			pthread_mutex_unlock(&(state->waiter));
			usleep(100);
		}
		if (state->rip)
			break;
		i = 0;
		while(i < state->nb_philos && philo[i].time_eaten >= state->n_to_eat - 1)
			i++;
		if (i == state->nb_philos && state->n_to_eat >= 1)
			state->finished_eating = 1;
	}
}

void	ft_finition(t_state *state, t_philo *philo)
{
	int i;

	i = 0;
	while (i < state->nb_philos)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < state->nb_philos)
	{
		pthread_mutex_destroy(&(state->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(state->console));
}

int	ft_routine(t_state *state)
{
	int	i;
	int	ret;
	t_philo	*phi;

	i = 0;
	phi = state->philo;
	state->start_time = ft_timestamp();
	while (i < state->nb_philos)
	{
		ret = pthread_create(&(phi[i].thread_id), NULL, ft_action, &(phi[i]));
		if (ret)
			ft_exit_with_error(1, "Erreur thread @philo");
		phi[i].last_meal = ft_timestamp();
		i++;
	}	
	ft_waiter(state, state->philo);
	ft_finition(state, phi);
	return (1);
}
