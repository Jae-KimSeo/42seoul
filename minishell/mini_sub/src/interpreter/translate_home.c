/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:53:38 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:53:39 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	translate_home_case(int case_num, t_list *token, char *line)
{
	char	*temp;

	if (case_num == 1)
	{
		free(line);
		((t_token *)(token->content))->value = get_env_str("HOME");
	}
	else if (case_num == 2)
	{
		temp = ft_strjoin_free(get_env_str("HOME"), "/", 1);
		temp = ft_strjoin_free(temp, line + 2, 1);
		free(line);
		((t_token *)(token->content))->value = temp;
	}
	return (SUCCESS);
}
