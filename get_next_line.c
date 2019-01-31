#if 0

get_next_line.c

#endif

#include "get_next_line.h"

void	ft_free_line(void *line, size_t len)
{
  (void)len;
  free(line);
}

int	count_chars_to_copy(const char *buffer, const int *ret)
{
  int	i;

  i = -1;
  while (++i < *ret) 
    if (buffer[i] == '\n')
      return (i);
  return (*ret);
}

void	show_content(t_list *elem)
{
  size_t	i;

  i = -1;
  while (++i < elem->content_size)
    ft_putchar(((char *)elem->content)[i]);
  ft_putchar('\n');
}

int	fill_queue(t_queue *queue, const char *buffer, const int *ret, size_t *ntotal)
{
  size_t ncopy;

  ncopy = count_chars_to_copy(buffer, ret);
  *ntotal += ncopy;
  if (!ncopy)
    return (0);
  ft_enqueue(queue, (void *)buffer, ncopy);
  if (ncopy < (size_t)*ret)
    return (0);
  return (1);
}

void	fill_line(t_queue *queue, char **line, const size_t *total)
{
  while (ft_queuesize(queue))
    {
      ft_memcpy(*line, queue->head->content, queue->head->content_size);
      *line += queue->head->content_size;
      free(ft_dequeue(queue));
    }
  **line = 0x00;
  *line -= *total;
  ft_queuedel(&queue);
}

int	get_next_line(const int fd, char **line)
{
  t_queue	*queue;
  char		buffer[BUFF_SIZE];
  int		ret;
  size_t	total;
  
  queue = ft_queuenew(0, 0, &ft_free_line);
  total = 0;
  while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
      if(!fill_queue(queue, (const char *)buffer, &ret, &total))
	break;
  *line = malloc(ft_queuesize(queue) * total * sizeof(char));
  if (!*line)
    return (-1);
  fill_line(queue, line, &total);
  return (1);
}
