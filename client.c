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
	int	b;
	int	i;

	i = 0;
	b = 128;
	if (argc < 3)
		ft_putstr_fd("Error! Not enough arguments.\n", 1);
	else if (argc > 3)
		ft_putstr_fd("Error! Too many arguments.\n", 1);
	else
	{
		while (argv[2][i])
		{
			while (b)
			{
				if (argv[2][i] / b)
				{
					kill(ft_atoi(argv[1]), SIGUSR2);
					argv[2][i] -= b;
					usleep(100);
				}
				else
				{
					kill(ft_atoi(argv[1]), SIGUSR1);
					usleep(100);
				}
				b = b / 2;
			}
			b = 128;
			i++;
		}
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(100);
		kill(ft_atoi(argv[1]), SIGUSR1);
		usleep(100);
	}
	return (0);
}
