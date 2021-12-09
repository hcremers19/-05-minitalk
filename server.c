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

void	handler(int num)
{
	static int	i = 128;
	static int	x = 0;

	if (num == 31)
		x = x + i;
	i = i / 2;
	if (!i)
	{
		ft_printf("%c", x);
		i = 128;
		x = 0;
	}
}

int	main(void)
{
	int	i;
	int	x;

	i = 128;
	x = 0;
	ft_printf("Welcome! Here's your PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}	
	return (0);
}
