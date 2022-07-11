/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:27:56 by lbricio-          #+#    #+#             */
/*   Updated: 2022/07/10 23:43:34 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

// fit the current position in line with correct character based on column
void	fit_line_with(char *this_letter, int current_column, int x)
{
	if (current_column == 1)
		ft_putchar (this_letter[0]);
	else if (current_column > 1 && current_column < x)
		ft_putchar (this_letter[1]);
	else if (current_column == x)
		ft_putchar (this_letter[2]);
}

// go to next line, set current_line to begin of line, add a line to line count
void	breakline(int *current_column, int *current_line)
{
	ft_putchar('\n');
	*current_column = 1;
	*current_line += 1;
}

// call function fit_line based on actual line
// this function solve all rush00 problems just changing fit_line strings
void	rush(int x, int y)
{
	int	current_line;
	int	current_column;

	if (y <= 0 || x <= 0)
		return ;
	current_line = 1;
	current_column = 1;
	while (current_column <= x && current_line <= y)
	{
		if (current_line == 1)
			fit_line_with ("ABC", current_column, x);
		else if (current_line > 1 && current_line < y)
			fit_line_with ("B B", current_column, x);
		else if (current_line == y)
			fit_line_with ("CBA", current_column, x);
		current_column++;
		if (current_column > x)
			breakline(&current_column, &current_line);
	}
}
