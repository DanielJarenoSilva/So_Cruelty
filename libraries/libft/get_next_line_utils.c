/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:44:19 by djareno           #+#    #+#             */
/*   Updated: 2025/10/08 11:56:42 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnlist	*ft_lstlastgnl(t_gnlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_backgnl(t_gnlist **lst, t_gnlist *new)
{
	t_gnlist	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = (t_gnlist *)ft_lstlast((t_list *)*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_find_next_line(t_gnlist *list)
{
	int	x;

	if (!list)
		return (0);
	while (list)
	{
		x = 0;
		while (list->content && list->content[x])
		{
			if (list->content[x] == '\n')
				return (1);
			x++;
		}
		list = list->next;
	}
	return (0);
}

int	ft_str_size(t_gnlist *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (len + 1);
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

char	*ft_make_str(t_gnlist *list, char *new_line)
{
	int	x;
	int	y;

	if (!list || !new_line)
		return (NULL);
	y = 0;
	while (list)
	{
		x = 0;
		while (list->content[x])
		{
			if (list->content[x] == '\n')
			{
				new_line[y++] = '\n';
				new_line[y] = '\0';
				return (new_line);
			}
			new_line[y++] = list->content[x++];
		}
		list = list->next;
	}
	new_line[y] = '\0';
	return (new_line);
}
