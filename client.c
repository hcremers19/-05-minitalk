/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:08:11 by hcremers          #+#    #+#             */
/*   Updated: 2021/12/04 18:08:18 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr_fd("Error! Not enough arguments.\n", 1);
	else if (argc > 2)
		ft_putstr_fd("Error! Too many arguments.\n", 1);
	else
	{
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(1);
		kill(ft_atoi(argv[1]), SIGUSR2);
	}
	return (0);
}
