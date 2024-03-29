#include"main.h"
/*
 * inter - Write a memory address
 * Return: Number of written chars.
  */
  int write_pointer(char buffer[], int ind, int length,
		      int width, int flags, char padd, char extra_c, int padd_start)
{
	    int i;

	        if (width > length)
			    {
				            for (i = 3; i < width - length + 3; i++)
						                buffer[i] = padd;

					            buffer[i] = '\0';

						            if (flags & F_MINUS && padd == ' ') 
								            {
										                buffer[--ind] = 'x';
												            buffer[--ind] = '0';

													                if (extra_c)
																                buffer[--ind] = extra_c;

															            return write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3);
																            }
							            else if (!(flags & F_MINUS) && padd == ' ') 				            {
											                buffer[--ind] = 'x';
													            buffer[--ind] = '0';

														                if (extra_c)
																	                buffer[--ind] = extra_c;

																            return write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length);
																	            }
								            else if (!(flags & F_MINUS) && padd == '0') 									            {
												                if (extra_c)
															                buffer[--padd_start] = extra_c;

														            buffer[1] = '0';
															                buffer[2] = 'x';

																	            return write(1, &buffer[padd_start], i - padd_start) +
																			                       write(1, &buffer[ind], length - (1 - padd_start) - 2);
																		            }
									        }

		    buffer[--ind] = 'x';
		        buffer[--ind] = '0';

			    if (extra_c)
				            buffer[--ind] = extra_c;

			        return write(1, &buffer[ind], BUFF_SIZE - ind - 1);
}

