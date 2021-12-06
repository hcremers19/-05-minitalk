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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	handler(int num)
{
	printf("Received!	%d\n", num);
}

int	main(void)
{
	signal(SIGUSR1, handler);
	printf("Welcome! Here's your PID: %d\n", getpid());
	while (1)
	{
		pause();
	}	
	return (0);
}
