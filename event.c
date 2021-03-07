/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hamr <sel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:37:25 by sel-hamr          #+#    #+#             */
/*   Updated: 2019/12/25 10:13:30 by sel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_press(int button, int x, int y, t_t *t)
{
	if (button == 5 && t->stop == 1)
		zoom(t, (double)x, (double)y, 1.1);
	else if (button == 4 && t->stop == 1)
		zoom(t, (double)x, (double)y, 0.9);
	check_ar(t);
	return (1);
}

void		key_press2(int keycode, t_t *t)
{
	if (keycode == 124)
	{
		t->start_x = t->start_x - 0.037;
		t->end_x = t->end_x - 0.037;
		check_ar(t);
	}
	else if (keycode == 125)
	{
		t->start_y = t->start_y - 0.037;
		t->end_y = t->end_y - 0.037;
		check_ar(t);
	}
	else if (keycode == 126)
	{
		t->start_y = t->start_y + 0.037;
		t->end_y = t->end_y + 0.037;
		check_ar(t);
	}
	else if (keycode == 24)
	{
		t->max += 10;
		check_ar(t);
	}
	else
		key_press3(keycode, t);
}

int			key_press(int keycode, t_t *t)
{
	if (keycode == 53)
	{
		destroy_exit(t);
		exit(0);
	}
	else if (keycode == 69 && t->stop == 1)
	{
		simple_zoome1(t);
		check_ar(t);
	}
	else if (keycode == 78 && t->stop == 1)
	{
		simple_zoome2(t);
		check_ar(t);
	}
	else if (keycode == 27)
	{
		if (t->max >= 10)
			t->max -= 10;
		check_ar(t);
	}
	else
		key_press2(keycode, t);
	return (1);
}

void		key_press3(int keycode, t_t *t)
{
	if (keycode == 83)
	{
		t->name = "julia";
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 49)
	{
		if (t->stop == 0)
			t->stop = 1;
		else
			t->stop = 0;
		check_ar(t);
	}
	else if (keycode == 36)
	{
		t->color = rand();
		check_ar(t);
	}
	else
		key_press4(keycode, t);
}

void		key_press4(int keycode, t_t *t)
{
	if (keycode == 84)
	{
		t->name = "Burningship";
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 85)
	{
		t->name = "Mandelbrot";
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 82)
	{
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 123)
	{
		t->start_x = t->start_x + 0.037;
		t->end_x = t->end_x + 0.037;
		check_ar(t);
	}
}
