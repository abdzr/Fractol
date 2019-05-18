/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:50 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/18 06:14:28 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./ft_mlx_keys.h"
# include <math.h>
# define WIN_W 650
# define WIN_H 650

typedef struct 	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_env
{
	void		*mlx_ptr;
	t_point		juliapos;
	int			islocked;	
	void		*mlx_win;
	void		*mlx_img;
	int			tab[24];
	int			*colors;
	int			max;
	int			row;
	int			col;
	int			iter;
	int			*mlx_data;
	int			bpp;
	int			endian;
	int			size_l;
	int			c;
	int			k;
	double		mnre;
	double		mxre;
	double		mnim;
	double		mxim;
	double		z;
	double		cre;
	double		cim;
	double		x;
	double		y;
	double		xnew;
	double		scale;
	double		jul_cre;
	double		jul_cim;
}				t_env;

/*
**  DRAWING
*/

void			mandeldraw(t_env *env);
void			juliadraw(t_env *env);
void			burningshipdraw(t_env *env);
void			juliadrawv3(t_env *env);
void			juliadrawv4(t_env *env);
void			mandeldrawv3(t_env *env);
void			mandeldrawv4(t_env *env);
void			tricorndraw(t_env *env);

/*
** MLX events and image processing
*/

int				key_stroke(int key, void *test);
int				mouse_zoom(int button, int x, int y, void *param);
void			images(t_env *env);
int				mouse_move(int x, int y, void *param);

/*
** Colours
*/

int				rgb(int r, int g, int b);
int				*clrs(t_env *env);
int				*fireorange(t_env *env);
int				*aqua_blue(t_env *env);
int				*colorpall(t_env *env);

/*
** needed funcs for calculation or initialisation of values
*/

double			ft_abs(double x);
void			values(t_env *env);
double			ft_map(double n, double start, double min, double max);
void			choice(t_env *env);
#endif
