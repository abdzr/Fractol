/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:11:02 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/05 19:08:08 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void				*burningshipdraw1(void *arg)
{
	t_threads		thread;
	t_env			*env;
	int				iter;
	int				row;
	int				col;

	env = (t_env *)arg;
	row = -1;
	while (++row <= WIN_W / 2)
	{
		col = -1;
		while (++col <= WIN_H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = burningshipcalc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void				*burningshipdraw2(void *arg)
{
	t_threads		thread;
	t_env			*env;
	int				iter;
	int				row;
	int				col;

	env = (t_env *)arg;
	row = -1;
	while (++row <= WIN_W / 2)
	{
		col = WIN_H / 2;
		while (++col <= WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = burningshipcalc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void				*burningshipdraw3(void *arg)
{
	t_threads		thread;
	t_env			*env;
	int				iter;
	int				row;
	int				col;

	env = (t_env *)arg;
	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = -1;
		while (++col <= WIN_H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = burningshipcalc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void				*burningshipdraw4(void *arg)
{
	t_threads		thread;
	t_env			*env;
	int				iter;
	int				row;
	int				col;

	env = (t_env *)arg;
	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = WIN_H / 2;
		while (++col <= WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = burningshipcalc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void				burningshipdraw(t_env *env)
{
	int			i;
	pthread_t	thread[4];

	images(env);
	i = 0;
	pthread_create(&thread[0], NULL, burningshipdraw1, (void *)env);
	pthread_create(&thread[1], NULL, burningshipdraw2, (void *)env);
	pthread_create(&thread[2], NULL, burningshipdraw3, (void *)env);
	pthread_create(&thread[3], NULL, burningshipdraw4, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
