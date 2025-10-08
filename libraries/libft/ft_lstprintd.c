/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:21:06 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 09:50:20 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintd(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}
}
