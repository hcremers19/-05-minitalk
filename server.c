/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:07:52 by hcremers          #+#    #+#             */
/*   Updated: 2021/12/04 18:07:59 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s1_handler(int num)
{
	(void)num;
	ft_putstr_fd("SIGUSR1 received!\n", 1);
}

void	s2_handler(int num)
{
	(void)num;
	ft_putstr_fd("SIGUSR2 received!\n", 1);
}

int	main(void)
{
	ft_printf("Welcome! Here's your PID: %d\n", getpid());
	signal(SIGUSR1, s1_handler);
	signal(SIGUSR2, s2_handler);
	while (1)
	{
		pause();
	}	
	return (0);
}
