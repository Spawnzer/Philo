/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:14:10 by adubeau           #+#    #+#             */
/*   Updated: 2022/03/08 15:01:52 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

//struct	s_state;

typedef	struct				s_philo
{
	int						id;
	int						dead;
	int						left;
	int						right;
	int						last_meal;
	struct s_state			*state;
}							t_philo;

typedef	struct				s_fork
{
	int						clean;
}							t_fork;

typedef	struct				s_state
{
	int						nb_philos;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						n_to_eat;
	int						rip;
	int						start_time;
	t_fork					fork_state;
	pthread_mutex_t			console;
	pthread_mutex_t			forks;
	t_philo					*philo;
}							t_state;

void			ft_putchar(int fd, char c);
void			ft_exit_with_error(int fd, char *str);
int				ft_atoi(char *str);
void			ft_init_state(t_state *state, int ac, char **av);
void			ft_init_philo(t_state *state);
int 			main(int ac, char **av);

#endif
