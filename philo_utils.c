/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:17 by ktoivola          #+#    #+#             */
/*   Updated: 2024/06/15 20:36:11 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    valid_args(char **args)
{
    if (0)
        return (true);
    else
        return (false);
}

size_t  get_time(void)
{
    struct timeval   time;
    
    if (gettimeofday(&time, NULL) < 0)
        handle_error(EXIT_FAILURE);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}