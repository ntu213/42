/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:54:49 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_init_s(t_flag *flag, char *str)
{
	int	trailing_len;

	trailing_len = flag->width;
	if (str)
		trailing_len -= ft_strlen(str);
	if (trailing_len < 0)
		trailing_len = 0;
	if (!flag->left)
		flag->leading_spaces_len = trailing_len;
	else
		flag->ending_spaces_len = trailing_len;
}

static char	*dup_str(t_flag *flag, char *str)
{
	if (str == NULL)
	{
		if (flag->dot)
			return (ft_strdup(""));
		return (ft_strdup("(null)"));
	}
	if (flag->dot && !flag->precision)
		return (ft_strdup(""));
	return (ft_strdup(""));
}

int	handle_s(char *str, t_flag *flag)
{
	int	total_len;
	int	need_to_free;

	need_to_free = 0;
	if ((str == NULL) || (flag->dot && !flag->precision))
	{
		need_to_free = 1;
		str = dup_str(flag, str);
	}
	if (flag->precision && (ft_strlen(str) > 0))
	{
		need_to_free = 1;
		str = ft_substr(str, 0, flag->precision);
	}
	flag_init_s(flag, str);
	total_len = ft_printxchars(' ', flag->leading_spaces_len);
	if (str)
		total_len += ft_printstr(str);
	total_len += ft_printxchars(' ', flag->ending_spaces_len);
	if (need_to_free)
		free(str);
	return (total_len);
}
// put_debug_flag(flag);	// !debug
