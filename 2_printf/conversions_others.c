void	ft_convert_di(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len)
{
	int di;
	int di_len;
	char di_str[100]; // how do avoid this?
	int treat_as_precision;

	di = va_arg(ap, int);
	sprintf(di_str, "%d", di);
	if (precision != -1)
		di_str[precision] = '\0';
	di_len = strlen(di_str);
	treat_as_precision = pad_left_spaces(left_space_pad_len, di_len);
	if (treat_as_precision == 1) // use true?!
		di_str[left_space_pad_len+1] = '\0'; // why +1?
	pad_left_zeros(left_zero_pad_len, di_len);
	ft_putstr(di_str);
	pad_right_spaces(right_space_pad_len, di_len);
}

void	ft_convert_p(va_list ap, int left_space_pad_len, int right_space_pad_len)
// p The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx').
{
	void *p;
	char *base;
	int p_len;

	base = "0123456789abcdef";
	p = va_arg(ap, char *);
	p = strdup(p);
	p_len = strlen(p);

	pad_left_spaces(left_space_pad_len, p_len);
	write(2, "0x", 2);
	ft_put_unsigned_nbr_base((unsigned long)p, base);
	pad_right_spaces(right_space_pad_len, p_len);
}

void	ft_convert_u(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len)
{
	unsigned int u;

	int u_len;
	char u_str[100]; // how do avoid this?
	int treat_as_precision;

	u = va_arg(ap, unsigned int);

	sprintf(u_str, "%d", u);
	if (precision != -1)
		u_str[precision] = '\0';
	u_len = strlen(u_str);
	treat_as_precision = pad_left_spaces(left_space_pad_len, u_len);
	if (treat_as_precision == 1)
		u_str[left_space_pad_len+1] = '\0'; // why +1?
	pad_left_zeros(left_zero_pad_len, u_len);
	ft_put_unsigned_nbr(u);
	pad_right_spaces(right_space_pad_len, u_len);
}

void	ft_convert_xX(const char format_str, va_list ap)
{
	unsigned int xX;
	char *base;
	
	if (format_str == 'x')
	{
		base = "0123456789abcdef";
	}
	if (format_str == 'X')
	{
		base = "0123456789ABCDEF";
	}

	xX = va_arg(ap, unsigned int); // hex also comes in as unsigned int
	ft_putnbr_base(xX, base);
}