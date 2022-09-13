#ifndef CONVERSIONS_STRINGS.H
# define CONVERSIONS_STRINGS.H

void	ft_convert_c(va_list ap, int left_space_pad_len, int right_space_pad_len);
void	ft_convert_s(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len);

#endif