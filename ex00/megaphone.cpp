/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:37:39 by arodgers          #+#    #+#             */
/*   Updated: 2024/09/18 14:09:18 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int getLength(const std::string &input)
{
	int	len;

	len = 0;
	
	while (input[len])
		len++;

	return (len);
}

std::string	skipSpace(const std::string &input)
{
	int	start;
	int	end;
	std::string	sub;

	start = 0;
	end = getLength(input);

	while (start < end && std::isspace(input[start]))
		start++;
	while (end > start && std::isspace(input[end - 1]))
		end--;

	sub = input.substr(start, end - start);

	return (sub);
}

int	main(int ac, char **av)
{
	std::string	arg;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISES *";
	else
	{
		for (int i = 1; av[i]; i++)
		{
			arg = skipSpace(av[i]);
			for (int j = 0; arg[j]; j++)
			{
				if (arg[j] >= 'a' && arg[j] <= 'z')
					arg[j] -= 32;
				std::cout << arg[j];
			}
			if (i < ac - 1)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	
	return (0);
}
