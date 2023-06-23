#include"main.h"
/**
 * number using a buffer
 *
 * Return: Number of printed characters.
 */
  int write_num(int ind, char buffer[],
		      int flags, int width, int prec,
		          int length, char padd, char extra_c)
{
	    int i, padd_start = 1;

	        if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
			        return 0; /* printf(".0d", 0) - no character is printed */

		    if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
			            buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */

		        if (prec > 0 && prec < length)
				        padd = ' ';

			    while (prec > length)
				            buffer[--ind] = '0', length++;

			        if (extra_c != 0)
					        length++;

				    if (width > length)
					        {
							        for (i = 1; i < width - length + 1; i++)
									            buffer[i] = padd;

								        buffer[i] = '\0';

									        if (flags & F_MINUS && padd == ' ') 
											        {
													            if (extra_c)
															                    buffer[--ind] = extra_c;

														                return write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1);
																        }
										        else if (!(flags & F_MINUS) && padd == ' ') 
												        {
														            if (extra_c)
																                    buffer[--ind] = extra_c;

															                return write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length);
																	        }
											        else if (!(flags & F_MINUS) && padd == '0') 
													        {
															            if (extra_c)
																	                    buffer[--padd_start] = extra_c;

																                return write(1, &buffer[padd_start], i - padd_start) +
																			                   write(1, &buffer[ind], length - (1 - padd_start));
																		        }
												    }

				        if (extra_c)
						        buffer[--ind] = extra_c;

					    return write(1, &buffer[ind], length);
}

int write_unsgnd(int is_negative, int ind,
		    char buffer[],
		        int flags, int width, int precision, int size)
{
	    int length = BUFF_SIZE - ind - 1;
	        int i = 0;
		    char padd = ' ';

		        UNUSED(is_negative);
			    UNUSED(size);

			        if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
					        return 0; /* printf(".0d", 0) - no character is printed */

				    if (precision > 0 && precision < length)
					            padd = ' ';

				        while (precision > length)
						    {
							            buffer[--ind] = '0';
								            length++;
									        }

					    if ((flags & F_ZERO) && !(flags & F_MINUS))
						            padd = '0';

					        if (width > length)
							    {
								            for (i = 0; i < width - length; i++)
										                buffer[i] = padd;

									            buffer[i] = '\0';

										            if (flags & F_MINUS) 
												            {
														                return write(1, &buffer[ind], length) + write(1, &buffer[0], i);
																        }
											            else 
													            {
															                return write(1, &buffer[0], i) + write(1, &buffer[ind], length);
																	        }
												        }

						    return write(1, &buffer[ind], length);
}

