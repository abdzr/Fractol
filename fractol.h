/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:30:14 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/29 15:48:25 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_env t_env;
struct s_env
{
    int         row;
    int         col;
    int         z;
    double      cre;
    double      cim;
    double      x;
    double      y;
    double      xnew;
    int         iter;
    int         *mlx_data;
    int         bpp;
    int         endian;
    int         size_l;
    void        *mlx_ptr;
    void        *mlx_win;
    void        *mlx_img;
};
int     key_stroke(int key, void *test);
void    mandeldraw(t_env *env);
#endif
