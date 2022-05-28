#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nel;

	nel = malloc(sizeof(t_list));
	if (!nel)
		return (0);
	nel->content = content;
	nel->next = 0;
	return (nel);
}
