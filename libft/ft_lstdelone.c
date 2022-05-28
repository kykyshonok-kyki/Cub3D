#include "libft.h"

void	ft_lstdelone(t_list *list, void (*del)(void *))
{
	if (list)
	{
		if (list->content)
			del(list->content);
		free(list);
	}
}
