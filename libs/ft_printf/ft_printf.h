/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:12:22 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/13 16:03:52 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ------------------------------ LIBRARIES --------------------------------- */
# include <unistd.h>
# include <stdarg.h>

/* ------------------------------- TYPEDEF's -------------------------------- */
typedef struct s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hash;
}	t_flags;

typedef struct s_fields
{
	t_flags	*flags;
	size_t	width;
	int		is_precision;
	size_t	precision;
	char	type;
}	t_fields;

/* ------------------------------ PROTOTYPES -------------------------------- */
/* FT_PRINTF_GETDATA -------------------------------------------------------- */
void	get_flags(char **field_ptr, t_flags *flags);
size_t	get_width(char **field_ptr);
size_t	get_precision(char **field_ptr);
char	get_type(char **field_ptr);
void	get_data(t_fields *data, t_flags *flags, char *field_ptr, \
	size_t *index);
/* FT_PRINTF_UTILS_ISDATA --------------------------------------------------- */
int		ft_isdigit(char c);
int		ft_isflag(char c);
int		ft_istype(char c);
int		ft_isdot(char **c);
int		ft_will_be_valid(char *s);
/* FT_PRINTF_UTILS_MISC_1ST ------------------------------------------------- */
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_isspace(char c);
int		ft_atoi(const char *str);
void	ft_putchar(char c, int *outpt_len);
/* FT_PRINTF_UTILS_MISC_2ND ------------------------------------------------- */
void	ft_putnchar(char c, size_t n, int *outpt_len);
void	ft_putstr(char *s, int *outpt_len);
void	ft_putstr_len(char *s, size_t len, int *outpt_len);
void	ft_puthex_adrs(unsigned long n, int *outpt_len);
int		ft_ispresign(t_fields *data, int n);
/* FT_PRINTF_UTILS_MISC_3RD ------------------------------------------------- */
void	get_hex_adrs_size(unsigned long n, size_t *hex_size);
void	ft_puthex(unsigned int n, int *outpt_len, int the_case);
void	get_hex_size(unsigned int n, size_t *hex_size);
void	ft_puthexa_prefix(unsigned int n, int isflag, char c, \
	int *outpt_len);
void	get_nbr_size(long n, size_t *nbr_size);
/* FT_PRINTF_UTILS_MISC_4TH ------------------------------------------------- */
void	ft_putnbr(int n, int *outpt_len);
void	ft_putnbr_presign(int n, t_flags *flags, int *outpt_len);
void	get_unbr_size(unsigned int n, size_t *nbr_size);
void	ft_putunbr(unsigned int n, int *outpt_len);
void	handle_error(int *outpt_len);
/* FT_PRINTF_UTILS_PROCESSDATA_1ST ------------------------------------------ */
void	process_data(t_fields *data, va_list *ap, int *outpt_len);
void	process_char(t_fields *data, char c, int *outpt_len);
void	process_str(t_fields *data, char *str, int *outpt_len);
void	process_vptr(t_fields *data, unsigned long vptr, int *outpt_len);
/* FT_PRINTF_UTILS_PROCESSDATA_2ND ------------------------------------------ */
void	check_zero(t_fields *data, char *char_to_fill);
void	check_precision_n_width(t_fields *data, size_t the_size, int prefix);
void	process_hex(t_fields *data, unsigned int n, int *outpt_len);
void	process_int(t_fields *data, int n, int *outpt_len);
void	process_uint(t_fields *data, unsigned int n, int *outpt_len);
/* FT_PRINTF ---------------------------------------------------------------- */
int		ft_printf(const char *s_in, ...);

#endif
