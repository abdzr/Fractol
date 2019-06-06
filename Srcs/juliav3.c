/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliav3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 08:32:05 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 20:05:08 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void			*juliadrawv31(void *arg)
{
	t_threads	thd;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = -1;
	while (++row <= W / 2)
	{
		col = -1;
		while (++col <= H / 2)
		{
			thd.cre = env->mnre + ((env->mxre - env->mnre) / W) * col + env->xx;
			thd.cim = env->mnim + ((env->mxim - env->mnim) / H) * row + env->yy;
			thd.x = thd.cre;
			thd.y = thd.cim;
			iter = juliav3calc(env, thd);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			*juliadrawv32(void *arg)
{
	t_threads	thd;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = -1;
	while (++row <= W / 2)
	{
		col = H / 2;
		while (++col <= H)
		{
			thd.cre = env->mnre + ((env->mxre - env->mnre) / W) * col + env->xx;
			thd.cim = env->mnim + ((env->mxim - env->mnim) / H) * row + env->yy;
			thd.x = thd.cre;
			thd.y = thd.cim;
			iter = juliav3calc(env, thd);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			*juliadrawv33(void *arg)
{
	t_threads	thd;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = W / 2;
	while (++row <= W)
	{
		col = -1;
		while (++col <= H / 2)
		{
			thd.cre = env->mnre + ((env->mxre - env->mnre) / W) * col + env->xx;
			thd.cim = env->mnim + ((env->mxim - env->mnim) / H) * row + env->yy;
			thd.x = thd.cre;
			thd.y = thd.cim;
			iter = juliav3calc(env, thd);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			*juliadrawv34(void *arg)
{
	t_threads	thd;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = W / 2;
	while (++row <= W)
	{
		col = H / 2;
		while (++col <= H)
		{
			thd.cre = env->mnre + ((env->mxre - env->mnre) / W) * col + env->xx;
			thd.cim = env->mnim + ((env->mxim - env->mnim) / H) * row + env->yy;
			thd.x = thd.cre;
			thd.y = thd.cim;
			iter = juliav3calc(env, thd);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			juliadrawv3(t_env *env)
{
	int			i;
	pthread_t	thd[4];

	images(env);
	i = 0;
	pthread_create(&thd[0], NULL, juliadrawv31, (void *)env);
	pthread_create(&thd[1], NULL, juliadrawv32, (void *)env);
	pthread_create(&thd[2], NULL, juliadrawv33, (void *)env);
	pthread_create(&thd[3], NULL, juliadrawv34, (void *)env);
	while (i < 4)
	{
		pthread_join(thd[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
