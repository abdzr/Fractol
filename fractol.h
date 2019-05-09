/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:30:14 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/09 14:31:27 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIN_W 600
#define WIN_H 600

typedef struct s_env
{
    void *mlx_ptr;
    void *mlx_win;
    void *mlx_img;
    int *tab;
    int *colors;
    int max;
    int row;
    int col;
    int iter;
    int *mlx_data;
    int bpp;
    int endian;
    int size_l;
    double minre;
    double maxre;
    double minim;
    double maxim;
    double z;
    double cre;
    double cim;
    double x;
    double y;
    double xnew;
}t_env;
int key_stroke(int key, void *test);
void mandeldraw(t_env *env);
void mandelcalcul(t_env *env);
void mandelcolor(t_env *env);
int rgb(int r, int g, int b);
int *clrs(t_env *env);
#endif
