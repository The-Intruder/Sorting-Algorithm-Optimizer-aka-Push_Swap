/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_processdata_1st.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:18:00 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/14 12:31:20 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------------- */

void	check_wrong_data(t_fields *data, int *outpt_len)
{
	char	type;

	type = data->type;
	if (data->flags->hash && (type == 'd' || type == 'i' \
		|| type == 'c' || type == 'u' || type == 'p'))
		handle_error(outpt_len);
	else if (data->flags->zero && (type == 'c' || type == 'p'))
		handle_error(outpt_len);
	else if (data->flags->plus && (type == 's' \
		|| type == 'c' || type == 'x' || type == 'X' || type == 'p'))
		handle_error(outpt_len);
	else if (data->flags->space && (type == 'p' \
		|| type == 'c' || type == 'x' || type == 'X'))
		handle_error(outpt_len);
}

/* -------------------------------------------------------------------------- */

void	process_data(t_fields *data, va_list *ap, int *outpt_len)
{
	check_wrong_data(data, outpt_len);
	if (*outpt_len >= 0)
	{
		if (data->type == 'c')
			process_char(data, va_arg(*ap, int), outpt_len);
		else if (data->type == 's')
			process_str(data, va_arg(*ap, char *), outpt_len);
		else if (data->type == 'p')
			process_vptr(data, va_arg(*ap, unsigned long), outpt_len);
		else if (data->type == 'x' || data->type == 'X')
			process_hex(data, va_arg(*ap, unsigned int), outpt_len);
		else if (data->type == 'd' || data->type == 'i')
			process_int(data, va_arg(*ap, signed int), outpt_len);
		else if (data->type == 'u')
			process_uint(data, va_arg(*ap, unsigned int), outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_char(t_fields *data, char c, int *outpt_len)
{
	if (data->width >= 1)
		data->width -= 1;
	if (data->flags -> minus)
	{
		ft_putchar(c, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putchar(c, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_str(t_fields *data, char *str, int *outpt_len)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (data -> is_precision && data -> precision < str_len)
		str_len = data -> precision;
	if (data -> width >= str_len)
		data -> width -= str_len;
	else
		data -> width = 0;
	if (data -> flags -> minus)
	{
		ft_putstr_len(str, str_len, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putstr_len(str, str_len, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	process_vptr(t_fields *data, unsigned long vptr, int *outpt_len)
{
	size_t	adrs_size;

	adrs_size = 2;
	get_hex_adrs_size(vptr, &adrs_size);
	if (data -> width >= adrs_size)
		data -> width -= adrs_size;
	else
		data -> width = 0;
	if (data -> flags -> minus)
	{
		ft_putstr_len("0x", 2, outpt_len);
		ft_puthex_adrs(vptr, outpt_len);
		ft_putnchar(' ', data -> width, outpt_len);
	}
	else
	{
		ft_putnchar(' ', data -> width, outpt_len);
		ft_putstr_len("0x", 2, outpt_len);
		ft_puthex_adrs(vptr, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */