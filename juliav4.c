/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliav4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:24:16 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/05 12:43:03 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int juliav4calc(t_env *env, t_threads thread)
{
    int iter;

    iter = 0;
    while (thread.x * thread.x + thread.y * thread.y <= 4 && iter < env->max)
    {
        thread.xnew = thread.x * thread.x * thread.x * thread.x - 6 * thread.x * thread.x * thread.y * thread.y + thread.y * thread.y * thread.y * thread.y + env->jul_cre;
        thread.y = 4 * thread.x * thread.x * thread.x * thread.y - 4 * thread.x * thread.y * thread.y * thread.y + env->jul_cim;
        thread.x = thread.xnew;
        iter++;
    }
    return (iter);
}

void *juliadrawv41(void     *arg)
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
            thread.x = thread.cre;
            thread.y = thread.cim;
            iter = juliav4calc(env , thread);
            if (iter < env->max)
                env->mlx_data[row * WIN_W + col] =
                    env->colors[iter % 24];
        }
    }
   pthread_exit(NULL);
}

void *juliadrawv42(void     *arg)
{
    t_threads thread;
    t_env *env;
    env = (t_env *)arg;
    int iter;
    int row;
    int col;

    row = -1;
    while (++row <= WIN_W)
    {
        col = WIN_H / 2;
        while (++col <= WIN_H)
        {
            thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
            thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
            thread.x = thread.cre;
            thread.y = thread.cim;
            iter = juliav4calc(env , thread);
            if (iter < env->max)
                env->mlx_data[row * WIN_W + col] =
                    env->colors[iter % 24];
        }
    }
   pthread_exit(NULL);
}

void *juliadrawv43(void     *arg)
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
            thread.x = thread.cre;
            thread.y = thread.cim;
            iter = juliav4calc(env , thread);
            if (iter < env->max)
                env->mlx_data[row * WIN_W + col] =
                    env->colors[iter % 24];
        }
    }
   pthread_exit(NULL);
}

void *juliadrawv44(void     *arg)
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
            thread.x = thread.cre;
            thread.y = thread.cim;
            iter = juliav4calc(env , thread);
            if (iter < env->max)
                env->mlx_data[row * WIN_W + col] =
                    env->colors[iter % 24];
        }
    }
   pthread_exit(NULL);
}


void juliadrawv4(t_env *env)
{
	int i;
	pthread_t thread[4];
	images(env);

	i = 0;
	pthread_create(&thread[0], NULL, juliadrawv41, (void *)env);
	pthread_create(&thread[1], NULL, juliadrawv42, (void *)env);
	pthread_create(&thread[2], NULL, juliadrawv43, (void *)env);
	pthread_create(&thread[3], NULL, juliadrawv44, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}