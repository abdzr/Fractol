/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:02:58 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/05 19:03:37 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

double			ft_abs(double x)
{
	if (x < 0)
		return (-x);
	else if (x > 0)
		return (x);
	return (0);
}


int				burningshipcalc(t_env *env , t_threads thread)
{
	int iter;
	iter = 0;

	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
			{
				thread.xnew = thread.x * thread.x - thread.y * thread.y + thread.cre;
				thread.y = ft_abs(2 * thread.x * thread.y) + thread.cim;
				thread.x = thread.xnew;
				iter++;
			}
	return(iter);
}
