/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:43:37 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/05 18:42:57 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

int julia1calc(t_env *env, t_threads thread)
{
	int iter;

	iter = 0;
	while (thread.x * thread.x +thread.y * thread.y <= 4 && iter < env->max)
	{
		thread.xnew = thread.x * thread.x - thread.y * thread.y + env->jul_cre;
		thread.y = 2 * thread.x * thread.y + env->jul_cim;
		thread.x = thread.xnew;
		iter++;
	}
	return (iter);
}


void *juliadraw1(void	*arg)
{

	t_threads thread;
	t_env	*env;
	env = (t_env *)arg;
	int iter = 0;
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
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
pthread_exit(NULL);
}

void *juliadraw2(void *arg)
{
	t_threads thread;
	t_env *env;
	env = (t_env *)arg;
	int iter = 0;
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
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
pthread_exit(NULL);
}

void *juliadraw3(void *arg)
{
	t_threads thread;
	t_env *env;
	env = (t_env *) arg;
	int row;
	int col;
int iter = 0;

	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = -1;
		while (++col <= WIN_H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col ;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row ;
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void *juliadraw4(void *arg)
{
	t_threads thread;
	t_env *env;
	int iter = 0;
	int row;
	int col;
	env = (t_env *)arg;

	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = WIN_H / 2;
		while (++col <= WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col ;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row ;
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void juliadraw(t_env *env)
{
	int i;
	pthread_t thread[4];
	images(env);

	i = 0;
	pthread_create(&thread[0], NULL, juliadraw1, (void *)env);
	pthread_create(&thread[1], NULL, juliadraw2, (void *)env);
	pthread_create(&thread[2], NULL, juliadraw3, (void *)env);
	pthread_create(&thread[3], NULL, juliadraw4, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
