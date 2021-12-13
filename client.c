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

void	ft_sendstr(int pid, int x)
{
	int	b;

	b = 128;
	while (b)
	{
		if (x / b)
		{
			kill(pid, SIGUSR2);
			x %= b;
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		b = b / 2;
	}
}

int	errors(int err)
{
	if (err == 1)
		ft_putstr_fd("Error! Not enough arguments.\n", 1);
	else if (err == 2)
		ft_putstr_fd("Error! Too many arguments.\n", 1);
	else if (err == 3)
		ft_putstr_fd("Error! Invalid PID.\n", 1);
	return (-1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	x;

	if (argc < 3)
		return (errors(1));
	else if (argc > 3)
		return (errors(2));
	else
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		if (pid < 1 || 4194304 < pid)
			return (errors(3));
		while (argv[2][i])
		{
			x = argv[2][i];
			ft_sendstr(pid, x);
			i++;
		}
		ft_sendstr(pid, '\n');
	}
	return (0);
}
