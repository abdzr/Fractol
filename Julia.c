/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:43:37 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/02 04:38:19 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"




/* THREADING PART TESTING */



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
			env->x = thread.cre;
			env->y = thread.cim;
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
			env->x = thread.cre;
			env->y = thread.cim;
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









/* EVERYTHING ELSE */
void juliadrawv3(t_env *env)
{
	images(env);
	while (++env->row < WIN_W)
	{
		env->col = -1;
		while (++env->col < WIN_H)
		{
			env->cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * env->col;
			env->cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * env->row;
			env->x = env->cre;
			env->y = env->cim;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < env->max)
			{
				env->xnew = env->x * env->x * env->x - 3 * env->x * env->y * env->y + env->jul_cre;
				env->y = 3 * env->x * env->x * env->y - env->y * env->y * env->y + env->jul_cim;
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < env->max)
				env->mlx_data[env->row * WIN_W + env->col] =
					env->colors[env->iter % 24];
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}

void juliadrawv4(t_env *env)
{
	images(env);
	while (++env->row < WIN_W)
	{
		env->col = -1;
		while (++env->col < WIN_H)
		{
			env->cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * env->col;
			env->cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * env->row;
			env->x = env->cre;
			env->y = env->cim;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < env->max)
			{
				env->xnew = env->x * env->x * env->x * env->x - 6 * env->x * env->x * env->y * env->y + env->y * env->y * env->y * env->y + env->jul_cre;
				env->y = 4 * env->x * env->x * env->x * env->y - 4 * env->x * env->y * env->y * env->y + env->jul_cim;
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < env->max)
				env->mlx_data[env->row * WIN_W + env->col] =
					env->colors[env->iter % 24];
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}