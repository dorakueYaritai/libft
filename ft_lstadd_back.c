#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst  == NULL)
		*lst = new;
	else
		ft_lstlast(*lst) -> next = new;
//		else
//		{
//			return ;
			//*lst = ft_lstnew(NULL);
			//(*lst) -> next = new;
			//*lst = new;
//		}
//	}
//	else
//		return ;
}
