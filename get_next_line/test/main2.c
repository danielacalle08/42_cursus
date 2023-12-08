#include <fcntl.h>
#include <stdio.h>
#include "../src/get_next_line.h"

int	main(void)
{
	int		fd;
	int		fd2;
	char	*str;
	char	*str2;

	fd = open("test/test.txt", O_RDONLY);
	fd2 = open("test/test2.txt", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(fd2);
	while (str != NULL)
	{
		printf("%s%s", str, str2);
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
	}
	close(fd);
}
