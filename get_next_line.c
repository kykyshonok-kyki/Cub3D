#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void	buf_rewrite(char buf[BUFFER_SIZE + 1], size_t nlpos)
{
	size_t	i;

	i = 0;
	if (buf[nlpos] == '\n')
		nlpos++;
	while (buf[nlpos + i])
	{
		buf[i] = buf[nlpos + i];
		i++;
	}
	buf[i] = buf[nlpos + i];
}

static char	add_str(char **line, char buf[BUFFER_SIZE + 1], size_t nlpos)
{
	size_t	nllen;
	char	*nline;

	nllen = ft_strlen(*line) + nlpos + 1;
	nline = malloc(nllen * sizeof(char));
	if (!nline)
		return (-1);
	ft_strlcpy(nline, *line, nllen);
	ft_strlcat(nline, buf, nllen);
	free(*line);
	*line = nline;
	return (0);
}

static char	nlsearch(char buf[BUFFER_SIZE + 1], char **line, size_t *nlpos)
{
	size_t	i;

	i = 0;
	while (buf[*nlpos] != '\n' && buf[i])
	{
		if (buf[i] == '\n' || !buf[i])
			*nlpos = i;
		i++;
	}
	if (buf[*nlpos] != '\n' && buf[*nlpos])
		*nlpos = i;
	if (!(*line) && (buf[*nlpos] == '\n' || !buf[*nlpos]))
	{
		*line = malloc((*nlpos + 1) * sizeof(char));
		if (!(*line))
			return (-1);
		ft_strlcpy(*line, buf, *nlpos + 1);
	}
	else if (*line && (buf[*nlpos] == '\n' || !buf[*nlpos]))
		if (add_str(line, buf, *nlpos) == -1)
			return (-1);
	if (buf[*nlpos] == '\n' || !nlpos)
		return (1);
	return (0);
}

static ssize_t	newline(char **line, char buf[BUFFER_SIZE + 1], int fd,
						size_t *nlpos)
{
	ssize_t	rd_res;
	char	if_nlfound;

	if_nlfound = 0;
	rd_res = -2;
	while (!if_nlfound && rd_res)
	{
		if (!buf[*nlpos])
		{
			rd_res = read(fd, buf, BUFFER_SIZE);
			if (rd_res == -1)
				return (-1);
			else
				buf[rd_res] = 0;
			*nlpos = 0;
		}
		if (rd_res != 0)
			if_nlfound = nlsearch(buf, line, nlpos);
	}
	if (if_nlfound == -1)
		return (-1);
	return (rd_res);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	ssize_t		rd_res;
	size_t		nlpos;

	nlpos = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	rd_res = newline(line, buf, fd, &nlpos);
	if (rd_res == -1)
	{
		if (*line)
		{
			free(*line);
			*line = 0;
		}
		return (-1);
	}
	if (!(*line))
		return (zero_line(line));
	buf_rewrite(buf, nlpos);
	if (!rd_res)
		return (0);
	return (1);
}
