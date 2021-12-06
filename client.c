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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
		printf("Error! Not enough arguments.\n");
	else if (argc > 2)
		printf("Error! Too many arguments.\n");
	else
		kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
