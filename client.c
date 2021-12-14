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

int	ft_sendstr(int pid, int x)
{
	int	b;

	b = 128;
	while (b)
	{
		if (x / b)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
			x %= b;
		}
		else
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		usleep(100);
		b /= 2;
	}
	return (0);
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
		pid = ft_atoi(argv[1]);
		if (pid < 1 || 4194304 < pid)
			return (errors(3));
		i = 0;
		while (argv[2][i])
		{
			x = argv[2][i];
			if (ft_sendstr(pid, x) == -1)
				return (errors(3));
			i++;
		}
		if (ft_sendstr(pid, '\n') == -1)
			return (errors(3));
	}
	return (0);
}
