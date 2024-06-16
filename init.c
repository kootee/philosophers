/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:16:28 by ktoivola          #+#    #+#             */
/*   Updated: 2024/06/15 21:41:46 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int create_threads(t_meta *meta, int num_of_philos)
{
    int i;
    
    i = 0;
    while (i < num_of_philos)
    {
        if(pthread_create(&meta->philo[i].thread, NULL, \
        &routine, &(meta->philo[i])) > 0)
            return (EXIT_FAILURE);
        i++;
    }
    i = 0;
    while (i < num_of_philos)
    {
        if (pthread_join(meta->philo[i].thread, NULL) > 0)
            return (EXIT_FAILURE);
    }
    return (0);
}

int init_philos(t_meta *meta, int num_of_philos)
{
    int i;

    i = 0;
    meta->start_time = get_time();
    while (i < num_of_philos)
    {
        meta->philo[i].num = i + 1;
        meta->philo[i].meal_count = 0;
        meta->philo[i].ate_last = 0;
        meta->philo[i].right_fork = NULL;
        if (pthread_mutex_init(&(meta->philo[i].left_fork), NULL) > 0);
            return(EXIT_FAILURE);
        if (i == num_of_philos - 1)
            meta->philo[i].right_fork = &meta->philo[0].left_fork;
        else
            meta->philo[i].right_fork = &meta->philo[i + 1].left_fork;
        i++;
    }
    create_threads(meta, num_of_philos);
    return (0);
}

int    init_meta(t_meta *meta, char **argv)
{
    pthread_mutex_init(&meta->print, NULL);
    pthread_mutex_init(&meta->m_eat, NULL);
    pthread_mutex_init(&meta->m_stop, NULL);
    pthread_mutex_init(&meta->dead, NULL);
    meta->philos_num = atoi(argv[1]); // change to ft
    meta->t_die = atoi(argv[2]);
    meta->t_eat = atoi(argv[3]);
    meta->t_sleep = atoi(argv[4]);
    if (argv[5])
    {
        meta->n_eat = atoi(argv[5]);
        if (meta->n_eat == 0)
            return (1);
    }
    meta->philo = malloc(sizeof(t_philo) * meta->philos_num);
    if (meta->philo == NULL)
        return (EXIT_MALLOC_FAIL);
    meta->stop = false;
    meta->eats = false;
}
