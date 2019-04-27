/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:26:56 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/27 14:24:11 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rgb(int r, int g, int b)
{
    char clr[4];
    clr[0] = b;
    clr[1] = g;
    clr[2] = r;
    clr[3] = 1;
    return (*(int *)clr);
}

int main()
{
    t_env *env;

    env = (t_env *)malloc(sizeof(t_env));
    env->mlx_ptr = mlx_init();
    env->mlx_win = mlx_new_window(env->mlx_ptr, 600, 600, "testing");
    env->mlx_img = mlx_new_image(env->mlx_ptr, 600, 600);
    env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp, &env->size_l, &env->endian);

    for (int row = 0; row < 600; row++)
    {
        for (int col = 0; col < 600; col++)
        {
            double c_re = (col - 600 / 2.0) * 4.0 / 600;
            double c_im = (row - 600 / 2.0) * 4.0 / 600;
            double x = 0, y = 0; 
            int iteration = 0;
            while (x * x + y * y <= 4 && iteration < 30)
            {
                double x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < 30)
            env->mlx_data[row * 600 + col] = rgb(255, 0, 0);
        }
    }
    mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
    mlx_loop(env->mlx_ptr);
    return (0);
}