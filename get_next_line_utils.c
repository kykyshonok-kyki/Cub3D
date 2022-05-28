#include <stdlib.h>

int	zero_line(char **line)
{
	*line = malloc(sizeof(char));
	if (!(*line))
		return (-1);
	**line = 0;
	return (0);
}
