/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:02:58 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/05 19:50:40 by azarzor          ###   ########.fr       */
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
				thread.xnew = thread.x * thread.x - thread.y * thread.y + thread.cre + env->xx;
				thread.y = ft_abs(2 * thread.x * thread.y) + thread.cim + env->yy;
				thread.x = thread.xnew;
				iter++;
			}
	return (iter);
}

void images(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	mlx_destroy_image(env->mlx_ptr, env->mlx_img);
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &(env->bpp),
											 &(env->size_l), &(env->endian));
	env->row = -1;
}

int             mandelcalc(t_env *env, t_threads thread)
{
	int iter;
	iter = 0;

	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x - thread.y * thread.y + thread.cre + env->xx;
		thread.y = 2 * thread.x * thread.y + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}

int     mandelv3calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x * thread.x - 3 * thread.x * thread.y * thread.y + thread.cre + env->xx;
		thread.y = 3 * thread.x * thread.x * thread.y - thread.y * thread.y * thread.y + thread.cim + env->yy;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}