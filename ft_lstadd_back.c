/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:01:25 by kakiba            #+#    #+#             */
/*   Updated: 2022/07/12 00:02:33 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}

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