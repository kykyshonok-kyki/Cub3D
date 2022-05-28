#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	if (lst)
	{
		while (*lst)
		{
			if ((*lst)->content)
			{
				del((*lst)->content);
				(*lst)->content = NULL;
			}
			if ((*lst)->next)
			{
				last = *lst;
				*lst = (*lst)->next;
				free(last);
			}
			else
			{
				free(*lst);
				*lst = NULL;
			}
		}
	}
}
