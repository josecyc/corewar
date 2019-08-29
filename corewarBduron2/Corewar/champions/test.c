#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	buf;

	fd = open(argv[1], O_RDONLY);
	while ((read(fd, &buf, 1)))
	{
		if (buf != 0)
			printf("%c == %x == %d == %u\n", buf, buf, buf, buf);
	}
}
