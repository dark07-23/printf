/**
 * prints unsigned - Prints an unsigned number
 * Return: Number of chars printed.
 */
 int print_unsigned(va_list types, char buffer[],
		 	int flags, int width, int precision, int size)
{
		int i = BUFF_SIZE - 2;
			unsigned long int num = va_arg(types, unsigned long int);

				num = convert_size_unsgnd(num, size);

					if (num == 0)
								buffer[i--] = '0';

						buffer[BUFF_SIZE - 1] = '\0';

							for (; num > 0; num /= 10)
									{
												buffer[i--] = (num % 10) + '0';
													}

								i++;

									return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

int print_octal(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
		int i = BUFF_SIZE - 2;
			unsigned long int num = va_arg(types, unsigned long int);
				unsigned long int init_num = num;

					UNUSED(width);

						num = convert_size_unsgnd(num, size);

							if (num == 0)
										buffer[i--] = '0';

								buffer[BUFF_SIZE - 1] = '\0';

									for (; num > 0; num /= 8)
											{
														buffer[i--] = (num % 8) + '0';
															}

										if (flags & F_HASH && init_num != 0)
													buffer[i--] = '0';

											i++;

												return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

