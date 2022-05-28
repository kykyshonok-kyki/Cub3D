#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			if (new)
			{
				new->next = *lst;
				*lst = new;
			}
		}
		else if (new)
		{
			new->next = 0;
			*lst = new;
		}
	}
	else if (new)
	{
		new->next = 0;
		lst = &new;
		*lst = new;
	}
}
