/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:27:56 by lbricio-          #+#    #+#             */
/*   Updated: 2022/07/10 22:15:46 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);

// fit the current position in line with correct character based on position
void	fit_line_with(char *this_letter, int x_point, int x)
{
	if (x_point == 1)
		ft_putchar (this_letter[0]);
	else if (x_point > 1 && x_point < x)
		ft_putchar (this_letter[1]);
	else if (x_point == x)
		ft_putchar (this_letter[2]);
}

// break the line, set y_point to start of line and add a line to line count
void	breakline(int *x_point, int *y_point)
{
	ft_putchar('\n');
	*x_point = 1;
	*y_point += 1;
}

//call function fit_line_with based on actual column
void	rush(int x, int y)
{
	int	x_point;
	int y_point;

	if (y <= 0 || x <= 0)
		return ;
 	y_point = 1;
	x_point = 1;
	while (x_point <= x && y_point <= y)
	{
		if  (y_point == 1)
			fit_line_with ("ABC", x_point, x);
		else if  (y_point > 1 && y_point < y)
			fit_line_with ("B B", x_point, x);
		else if  (y_point == y)
			fit_line_with ("CBA", x_point, x);
		x_point++;
		if (x_point > x)
			breakline(&x_point,  &y_point);
	}
}
