/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hamr <sel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 11:04:51 by sel-hamr          #+#    #+#             */
/*   Updated: 2019/12/25 10:29:26 by sel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < WIDTH)
	{
		t->x_x = 0;
		while (t->x_x < HIGHT)
		{
			t->itier = 0;
			init_x_y(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	mlx_ho(t);
}

void		mandelbrot(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < HIGHT)
	{
		t->x_x = 0;
		while (t->x_x < WIDTH)
		{
			t->itier = 0;
			map(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	t->stop = 1;
	mlx_ho(t);
}

int			mouse_move(int x, int y, t_t *t)
{
	if (x < 600 && y < 600 && t->stop == 0 && str_cmp(t->name, "julia") == 0)
	{
		t->x_o = (((double)x / 600) * 4) - 2;
		t->y_o = ((((double)y * -1) / 600) * 4) + 2;
		check_ar(t);
	}
	return (1);
}

void		zoom(t_t *t, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	yy = ((y / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = xx + ((t->start_x - xx) * zoom);
	t->start_y = yy + ((t->start_y - yy) * zoom);
	t->end_y = yy + ((t->end_y - yy) * zoom);
	t->end_x = xx + ((t->end_x - xx) * zoom);
	if (t->max <= 120)
		t->max += 2;
}

void		mlx_ho(t_t *t)
{
	menu(t);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_hook(t->win, 6, 1, mouse_move, t);
	mlx_hook(t->win, 2, 1, key_press, t);
	mlx_loop(t->ptr);
}
