#include "main.h"

/*
 * string - Prints a string
 * Return: Number of chars printed
 */
 int print_string(va_list types, char buffer[],
		 	int flags, int width, int precision, int size)
{
		int length = 0, i;
			char *str = va_arg(types, char *);

				UNUSED(buffer);
					UNUSED(flags);
						UNUSED(width);
							UNUSED(precision);
								UNUSED(size);
									if (str == NULL)
											{
														str = "(null)";
																if (precision >= 6)
																				str = "      ";
																	}

										while (str[length] != '\0')
													length++;

											if (precision >= 0 && precision < length)
														length = precision;

												if (width > length)
														{
																	if (flags & F_MINUS)
																				{
																								write(1, &str[0], length);
																											for (i = width - length; i > 0; i--)
																																write(1, " ", 1);
																														return (width);
																																}
																			else
																						{
																										for (i = width - length; i > 0; i--)
																															write(1, " ", 1);
																													write(1, &str[0], length);
																																return (width);
																																		}
																				}

													for (i = 0; i < length; i++)
																write(1, &str[i], 1);

														return length;
}

