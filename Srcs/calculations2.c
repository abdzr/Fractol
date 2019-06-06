/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:47:29 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 19:48:46 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

int			tridraw(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x -
			thread.y * thread.y + thread.cre + env->xx;
		thread.y = -2 * thread.x * thread.y + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int			juliav4calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x * thread.x * thread.x - 6 *
			thread.x * thread.x * thread.y * thread.y + thread.y *
			thread.y * thread.y * thread.y + env->jul_cre;
		thread.y = 4 * thread.x * thread.x * thread.x *
			thread.y - 4 * thread.x * thread.y * thread.y *
			thread.y + env->jul_cim;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int			mandeldrawv4calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x * thread.x * thread.x - 6 *
		thread.x * thread.x * thread.y * thread.y + thread.y *
		thread.y * thread.y * thread.y + thread.cre + env->xx;
		thread.y = 4 * thread.x * thread.x * thread.x * thread.y - 4 *
		thread.x * thread.y * thread.y * thread.y + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}
