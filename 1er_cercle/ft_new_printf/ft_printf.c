
#include "ft_printf.h"

int	ft_comp(char orig, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == orig)
			return (1);
		i++;
	}
	return (0);
}

int	ft_tester_2(va_list *arg, const char *origin, int i, t_obj *item)
{
	char	*str;

	if (origin[i] == 'c')
		ft_putchar_fd(va_arg(*arg, int), 1);
	else if (origin[i] == 's')
	{
		str = va_arg(*arg, char *);
		ft_putstr_fd(str, 1, item);
		item->total += ft_strlen(str);
	}
	else if (origin[i] == 'p')
		ft_ptochar(va_arg(*arg, void *), "0123456789abcdef", item, 0);
	else if (origin[i] == 'x')
		int_base(va_arg(*arg, int), "0123456789abcdef", item, 0);
	else if (origin[i] == 'X')
		int_base(va_arg(*arg, int), "0123456789ABCDEF", item, 0);
	else if (origin[i] == 'd' || origin[i] == 'i')
		ft_int_writer(va_arg(*arg, int), item);
	else if (origin[i] == '%')
		ft_error(i, item);
	else
		ft_unsint_writer(va_arg(*arg, int), item, 0);
	return (i + 1);
}

int	ft_tester(va_list *arg, const char *origin, int n, t_obj *item)
{
	int	i;

	i = n + 1;
	while (origin[i] && !ft_comp(origin[i], "cspdiuxX%"))
	{
		if (!ft_midverif(item, origin[i]))
			return (ft_error(i, item));
		i++;
	}
	if (!origin[i])
		return (ft_error(i, item));
	if ((origin[i] == 'x') && item->hash)
		write(1, "0x", 2);
	else if ((origin[i] == 'X') && item->hash)
		write(1, "0X", 2);
	if ((origin[i] == 'x' || origin[i] == 'X') && item->hash)
		item->total += 2;
	if (origin[i] == 'c')
		item->total++;
	return (ft_tester_2(arg, origin, i, item));
}

void	ft_item_reset(t_obj *item)
{
	item->hash = 0;
	item->space = 0;
	item->plus = 0;
}

int	ft_printf(const char *origin, ...)
{
	t_obj	*item;
	va_list	arg;
	int		i;

	i = 0;
	item = malloc(sizeof(t_obj));
	item->total = 0;
	ft_item_reset(item);
	va_start(arg, origin);
	while (origin[i])
	{
		if (origin[i] == '%')
		{
			i = ft_mytester(&arg, origin, i, item);
			ft_item_reset(item);
		}
		else
			ft_write_it(origin, i++, item);
	}
	i = item->total;
	free(item);
	va_end(arg);
	return (i);
}
