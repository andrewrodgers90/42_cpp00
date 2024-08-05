/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:13:40 by arodgers          #+#    #+#             */
/*   Updated: 2024/07/18 12:18:06 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	trimArg(std::string arg)
{
	int	start;
	int	end;

	start = 0;
	end = arg.length();

	while (start < end && std::isspace(arg[start]))
		start++;

	while (end > start && std::isspace(arg[end - 1]))
		end--;

	return (arg.substr(start, end - start));
}

std::string	checkArg(std::string arg)
{
	std::string	copy;

	copy = arg;

	for (size_t i = 0; i < copy.length(); i++)
		copy[i] = std::toupper(copy[i]);

	copy = trimArg(copy);

	return (copy);
}

int	main(int ac, char **av)
{
	Phonebook	phonebook;
	std::string	input;
	std::string	parsedInput;
	static int	i;

	phonebook.printWelcome();
	i = 0;

	while (true)
	{
		phonebook.printOptions();
		std::getline(std::cin, input);
		parsedInput = checkArg(input);
		if (parsedInput == "ADD")
		{
			phonebook.addContact(i);
			i++;
		}
		else if (parsedInput == "SEARCH")
		{
			phonebook.displayContacts();
			phonebook.displaySingleContact();
		}
		else if (parsedInput == "EXIT")
		{
			std::cout << GREEN << "Thanks for using Andrew's awesome phonebook!" << RESET << std::endl;
			break ;
		}
		else
		{
			std::cout << std::endl;
			std::cout << YELLOW << "Invalid option. Please choose of the options below." << RESET << std::endl;
			std::cout << std::endl;
		}
	}
	return (0);
}
