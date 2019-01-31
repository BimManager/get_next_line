#if 0

get_next_line.h

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE	1

int	get_next_line(const int fd, char **line);
void	ft_free_line(void *line, size_t len);
int	count_chars_to_copy(const char *buffer, const int *ret);
int	fill_queue(t_queue *queue, const char *buffer, const int *ret, size_t *ntotal);
void	fill_line(t_queue *queue, char **line, const size_t *total);

#endif
