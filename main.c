/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:23:39 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/30 16:00:40 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		start_data(av[1]);
	else
		write(2, "invalid argument", 16);
	return (0);
}
