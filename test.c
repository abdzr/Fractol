/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:01:17 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/25 17:25:16 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     *colourpallets(int r, int g, int b)
{
    int clr[2];
    clr[0] = r;
    clr[1] = g;
    clr[2] = b;
    return (clr);
}

void         colour(int *mlx_data, int x, int y, int *colourpallets(int r ,int g ,int b))
{
    int cases[3];
    cases[0] = x + 4 * 1000 * y;
    cases[1] = cases[0] + 1;
    cases[2] = cases[1] + 1;
    cases[3] = cases[2] + 1;
    


}

int main()
{
//    int x;
//    int y;
    t_env env;

    env.mlx_ptr = mlx_init();
    env.mlx_win = mlx_new_window(env.mlx_ptr, 1000, 1000, "testing");
    env.mlx_img = mlx_new_image(env.mlx_ptr, 1000,1000);
    env.mlx_data = mlx_get_data_addr(env.mlx_img, env.bpp, env.size_l, env.endian);
    // x = 0;
    // y = 0;
    

    
    return(0);
}