/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:02:58 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 15:57:19 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

int			burningshipcalc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x - thread.y *
			thread.y + thread.cre + env->xx;
		thread.y = ft_abs(2 * thread.x * thread.y) + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int			mandelcalc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x - thread.y *
			thread.y + thread.cre + env->xx;
		thread.y = 2 * thread.x * thread.y + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int			mandelv3calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x * thread.x - 3 *
			thread.x * thread.y * thread.y + thread.cre + env->xx;
		thread.y = 3 * thread.x * thread.x * thread.y - thread.y *
			thread.y * thread.y + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int			julia1calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x - thread.y * thread.y + env->jul_cre;
		thread.y = 2 * thread.x * thread.y + env->jul_cim;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int			juliav3calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x * thread.x - 3 *
			thread.x * thread.y * thread.y + env->jul_cre;
		thread.y = 3 * thread.x * thread.x * thread.y -
			thread.y * thread.y * thread.y + env->jul_cim;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}
