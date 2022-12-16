int		pad_left_spaces(int left_space_pad_len, int item_len)
{
	int num_left_spaces_to_pad;
	int i;

	if (left_space_pad_len > item_len)
	// strings are padded if the pad length is longer than string length
	// but pad length is NOT treated as precision when it's shorter that string length
	{
		num_left_spaces_to_pad = left_space_pad_len - item_len;
		i = 0;
		while(i < num_left_spaces_to_pad)
		{
			ft_putchar(' ');
			i++;
		}
		return (0);
	}
	else
		return (1);
}

void	pad_left_zeros(int left_zero_pad_len, int item_len)
{
	int num_left_zeros_to_pad;
	int i;

	num_left_zeros_to_pad = left_zero_pad_len - item_len;
	i = 0;
	while(i < num_left_zeros_to_pad)
	{
		ft_putchar('0');
		i++;
	}
}

void	pad_right_spaces(int right_space_pad_len, int item_len)
{
	int num_right_spaces_to_pad;
	int i;

	num_right_spaces_to_pad = right_space_pad_len - item_len;
	i = 0;
	while(i < num_right_spaces_to_pad)
	{
		ft_putchar(' ');
		i++;
	}
}
