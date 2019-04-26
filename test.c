/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:01:17 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/26 20:09:02 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     rgb(int r, int g, int b)
{
    char clr[4];
    clr[0] = b;
    clr[1] = g;
    clr[2] = r;
    clr[3] = 1;
    return (*(int *)clr);
}

// void       rgb(int *clr)
// {
// clr = (int*)malloc(4*sizeof(int));
// clr[0] = 255;
// clr[1] = 255;
// clr[2] = 255;
// clr[3] = 0;

// }



int main()
{
    int x;
    int y;
    t_env *env;

    env = (t_env *)malloc(sizeof(t_env));
    env->mlx_ptr = mlx_init();
    env->mlx_win = mlx_new_window(env->mlx_ptr, 1000, 1000, "testing");
    env->mlx_img = mlx_new_image(env->mlx_ptr, 1000,1000);
    env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp, &env->size_l, &env->endian);
     x = 100;
     y = 100;
     env->mlx_data[x * 1000 + y] = rgb(255,0,0);
     mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
     mlx_loop(env->mlx_ptr);
    return(0);
}