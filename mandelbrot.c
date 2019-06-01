/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:53:04 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/01 20:43:21 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/libft.h"

void images(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	mlx_destroy_image(env->mlx_ptr, env->mlx_img);
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &(env->bpp),
											 &(env->size_l), &(env->endian));
	env->row = -1;
}

int test(t_env *env, t_threads thread)
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

/* TRYING THE THREADING PART */

void *mandeldraw1(void *arg)
{
	t_threads thread;
	t_env *env;
	env = (t_env *)arg;
	int iter;
	int row = 0;
	int col = 0;

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
			iter = test(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void *mandeldraw2(void *arg)
{
	t_threads thread;
	t_env *env;
	env = (t_env *)arg;
	int iter;
	int row = 0;
	int col = 0;

	row = -1;
	while (++row <= WIN_W / 2)
	{
		col = WIN_H / 2;
		while (++col < WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = test(env,thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}

	pthread_exit(NULL);
}

void *mandeldraw3(void *arg)
{
	t_threads thread;
	t_env *env;
	env = (t_env *)arg;
	int iter;
	int row = 0;
	int col = 0;



	row = WIN_W / 2;
	while (++row < WIN_W)
	{
		col = -1;
		while (++col <= WIN_H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = test(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}

	pthread_exit(NULL);
}

void *mandeldraw4(void *arg)
{
	t_threads thread;
	t_env *env;
	env = (t_env *)arg;
	int iter;
	int row = 0;
	int col = 0;



	row = WIN_W / 2;
	while (++row < WIN_W)
	{
		col = WIN_H / 2;
		while (++col < WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			env->x = 0;
			env->y = 0;
			iter = test(env,thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}

	pthread_exit(NULL);
}

void mandeldraw(t_env *env)
{
	int i;
	pthread_t thread[4];
	images(env);

	i = 0;
	pthread_create(&thread[0], NULL, mandeldraw1, (void *)env);
	pthread_create(&thread[1], NULL, mandeldraw2, (void *)env);
	pthread_create(&thread[2], NULL, mandeldraw3, (void *)env);
	pthread_create(&thread[3], NULL, mandeldraw4, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}

/* THE REST */

void mandeldrawv4(t_env *env)
{
	images(env);
	while (++env->row < WIN_W)
	{
		env->col = -1;
		while (++env->col < WIN_H)
		{
			env->cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * env->col;
			env->cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * env->row;
			env->x = 0;
			env->y = 0;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < env->max)
			{
				env->xnew = env->x * env->x * env->x * env->x - 6 * env->x * env->x * env->y * env->y + env->y * env->y * env->y * env->y + (env->cre);
				env->y = 4 * env->x * env->x * env->x * env->y - 4 * env->x * env->y * env->y * env->y + (env->cim);
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