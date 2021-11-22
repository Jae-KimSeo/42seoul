/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:53:51 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:53:52 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_mat(char **mat)
{
	int	idx;

	idx = 0;
	while (mat[idx])
	{
		free(mat[idx]);
		idx++;
	}
	free(mat);
}

char	*convert_dollar_case(char **words, char *result)
{
	int	sp_idx;

	while (*words)
	{
		sp_idx = 0;
		if ((*words)[0] == '?')
		{
			result = ft_strjoin_free(result, ft_itoa(g_shell.exit_status), 3);
			result = ft_strjoin_free(result, *words++ + 1, 1);
			continue ;
		}
		while ((*words)[sp_idx] > ' ')
			sp_idx++;
		if ((*words)[sp_idx] == '\0')
			result = ft_strjoin_free(result, get_env_str(*words), 3);
		else
		{
			(*words)[sp_idx] = '\0';
			result = ft_strjoin_free(result, get_env_str(*words), 3);
			result = ft_strjoin_free(result, " ", 1);
			result = ft_strjoin_free(result, *words + sp_idx + 1, 1);
		}
		words++;
	}
	return (result);
}

int	translate_dollar_case(t_list *token, char *line)
{
	char	**words;
	char	*result;
	char	*first_d;

	if (*line != '$')
	{
		first_d = ft_strchr(line, '$');
		*first_d = '\0';
		result = ft_strdup(line);
		words = ft_split(first_d + 1, '$');
	}
	else
	{
		result = ft_strdup("");
		words = ft_split(line, '$');
	}
	free(line);
	((t_token *)(token->content))->value = convert_dollar_case(words, result);
	free_mat(words);
	return (SUCCESS);
}
