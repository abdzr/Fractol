/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotv4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 05:14:53 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/03 04:56:58 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     mandeldrawv4calc(t_env *env, t_threads thread)
{
    int iter;
    iter = 0;
    while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
			{
				thread.xnew = thread.x * thread.x * thread.x * thread.x - 6 * thread.x * thread.x * thread.y * thread.y + thread.y * thread.y * thread.y * thread.y + thread.cre;
				thread.y = 4 * thread.x * thread.x * thread.x * thread.y - 4 * thread.x * thread.y * thread.y * thread.y + thread.cim;
				thread.x = thread.xnew;
				iter++;
			}
            return (iter);
}

void        *mandeldrawv41(void *arg)
{
    t_threads thread;
    t_env *env;
    env = (t_env *)arg;
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
            iter = mandeldrawv4calc(env , thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
    pthread_exit(NULL);
}

void        *mandeldrawv42(void *arg)
{
    t_threads thread;
    t_env *env;
    env = (t_env *)arg;
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
            iter = mandeldrawv4calc(env , thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
    pthread_exit(NULL);
}

void        *mandeldrawv43(void *arg)
{
    t_threads thread;
    t_env *env;
    env = (t_env *)arg;
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
            iter = mandeldrawv4calc(env , thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
    pthread_exit(NULL);
}

void        *mandeldrawv44(void *arg)
{
    t_threads thread;
    t_env *env;
    env = (t_env *)arg;
    int iter;
    int row;
    int col;

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
            iter = mandeldrawv4calc(env , thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
    pthread_exit(NULL);
}

void mandeldrawv4(t_env *env)
{
	int i;
	pthread_t thread[4];
	images(env);

	i = 0;
	pthread_create(&thread[0], NULL, mandeldrawv41, (void *)env);
	pthread_create(&thread[1], NULL, mandeldrawv42, (void *)env);
	pthread_create(&thread[2], NULL, mandeldrawv43, (void *)env);
	pthread_create(&thread[3], NULL, mandeldrawv44, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}