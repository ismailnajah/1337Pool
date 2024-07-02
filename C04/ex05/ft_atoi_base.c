/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inajah <inajah@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:26:16 by inajah            #+#    #+#             */
/*   Updated: 2024/07/02 12:02:37 by inajah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isvalid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;
	
	i = 0;
	while (base[i]){
		if (base[i] == '-' || base[i] == '+')
			return 0;
		j = i + 1;
		while(base[j]){
			if (base[i] == base[j])
				return 0;
			j++;
		}
		i++;
	}
	return (i);//base size
}

int	ft_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return (-1);
}

long long _ft_atoi_base(char *str, char *base_symboles, unsigned int size)
{

}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	base_size;
	unsigned int	i;
	int				sign;

	base_size = ft_isvalid_base(base);
	if (base_size <= 1)
		return (0);
	i = 0;
	while (str[i] && (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	start = i;
	while (str[i] && ft_inbase(str[i]) > 0)
		i++;
	end = i;
	return (_ft_atoi_base(str + start, base, end - start, base_size) * sign);
}
