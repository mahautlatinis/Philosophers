/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:54:50 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 18:50:24 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

long	ft_atoi_bis(char *str, t_atoi_var *var)
{
	if (!str[var->i] || !ft_isdigit(str[var->i]))
	{
		printf("Error.\nError with args.\n");
		return (0);
	}
	while (ft_isdigit(str[var->i]))
		var->result = var->result * 10 + (str[var->i++] - '0');
	if (str[var->i] && !(ft_isdigit(str[var->i])) && str[var->i] != ' ')
	{
		printf("Error.\nError with args.\n");
		return (0);
	}
	return (var->result * var->sign);
}

long	ft_atoi(char *str)
{
	t_atoi_var	var;

	var.i = 0;
	var.max = 0;
	var.sign = 1;
	var.result = 0;
	while (str[var.i] == '-' || str[var.i] == '+')
	{
		if (ft_isalpha(str[var.i]) || var.max >= 1)
		{
			printf("Error.\nError with args.\n");
			return (0);
		}
		if (str[var.i] == '-')
			var.sign = -var.sign;
		var.max++;
		var.i++;
	}
	return (ft_atoi_bis(str, &var));
}
