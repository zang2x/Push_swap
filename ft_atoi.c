/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hazel <Hazel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:00:53 by hcruz-me          #+#    #+#             */
/*   Updated: 2025/06/03 11:09:27 by Hazel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
	{
		nptr++;
	}
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += (*nptr - 48);
		nptr++;
	}
	return (result * sign);
}
