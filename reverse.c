#include"main.h"

/**
 * print_reverse - Prints a reverse string.
 * Return: Number of chars printed
 */
int print_reverse(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

				UNUSED(buffer);
					UNUSED(flags);
						UNUSED(width);
							UNUSED(size);

								str = va_arg(types, char *);

									if (str == NULL)
											{
														UNUSED(precision);
																str = ")Null(";
																	}

										for (i = 0; str[i] != '\0'; i++)
													;

											for (i = i - 1; i >= 0; i--)
													{
																char z = str[i];
																		write(1, &z, 1);
																				count++;
																					}

												return (count);
}

int print_rot13string(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
		char x;
			char *str;
				unsigned int i, j;
					int count = 0;
						char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
							char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

								str = va_arg(types, char *);
									UNUSED(buffer);
										UNUSED(flags);
											UNUSED(width);
												UNUSED(precision);
													UNUSED(size);

														if (str == NULL)
																	str = "(AHYY)";

															for (i = 0; str[i] != '\0'; i++)
																	{
																				for (j = 0; in[j] != '\0'; j++)
																							{
																											if (in[j] == str[i])
																															{
																																				x = out[j];
																																								write(1, &x, 1);
																																												count++;
																																																break;
																																																			}
																													}

																						if (in[j] == '\0')
																									{
																													x = str[i];
																																write(1, &x, 1);
																																			count++;
																																					}
																							}

																return (count);
}

