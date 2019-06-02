/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotv3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:35:29 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/02 05:14:12 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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



void        *mandeldrawv31(void *args)
{
	t_env *env;
	t_threads thread;

	env = (t_env *)args;
	int iter;
	int row;
	int col;

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
			iter = mandelv3calc(env, thread);			
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void        *mandeldrawv32(void *args)
{
	t_env *env;
	t_threads thread;

	env = (t_env *)args;
	int iter;
	int row;
	int col;

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
			iter = mandelv3calc(env, thread);			
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void        *mandeldrawv33(void *args)
{
	t_env *env;
	t_threads thread;

	env = (t_env *)args;
	int iter;
	int row;
	int col;

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
			iter = mandelv3calc(env, thread);			
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void        *mandeldrawv34(void *args)
{
	t_env *env;
	t_threads thread;

	env = (t_env *)args;
	int iter;
	int row;
	int col;

	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = WIN_W / 2;
		while (++col <= WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = mandelv3calc(env, thread);			
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void mandeldrawv3(t_env *env)
{
	int i;
	pthread_t thread[4];
	images(env);

	i = 0;
	pthread_create(&thread[0], NULL, mandeldrawv31, (void *)env);
	pthread_create(&thread[1], NULL, mandeldrawv32, (void *)env);
	pthread_create(&thread[2], NULL, mandeldrawv33, (void *)env);
	pthread_create(&thread[3], NULL, mandeldrawv34, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
