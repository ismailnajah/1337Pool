/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:15:36 by inajah            #+#    #+#             */
/*   Updated: 2024/06/29 18:04:51 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanum(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_alphanum(str[i]))
			i++;
		else if (str[i])
		{
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] = 'A' + (str[i] - 'a');
			i++;
			while (is_alphanum(str[i]))
			{
				if ('A' <= str[i] && str[i] <= 'Z')
					str[i] = 'a' + (str[i] - 'A');
				i++;
			}
		}
	}
	return (str);
}
