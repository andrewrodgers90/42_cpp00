/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:26:27 by arodgers          #+#    #+#             */
/*   Updated: 2024/07/18 12:18:48 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	Phonebook::displaySingleContact()
{
	std::string	str;
	int	i;

	std::cout << "Select an index:" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << RED << "An index must be given.\n" << RESET << std::endl;
		displaySingleContact();
		return ;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << RED << "Invalid input.\n" << RESET << std::endl;
			displaySingleContact();
			return ;
		}
	}
	i = std::stoi(str);
	if (i > 8 || i < 1 || _contacts[i - 1].isValidIndex())
	{
		std::cout << RED << "Invalid index.\n" << RESET << std::endl;
		displaySingleContact();
		return ;
	}
	_contacts[i - 1].showInfo();
}

void	Phonebook::displayContacts()
{
	std::cout << "|" << "     Index" << "|" << "First name" << "|" << " Last name" << "|" << "  Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		_contacts[i].printInfo();
	}
}

void	Phonebook::addContact(int i)
{
	_contacts[i % 8].createContact(i % 8);
}

void	Phonebook::printOptions()
{
	std::cout << RED << "ADD:\t" << RESET << CYAN << "save a new contact" << RESET << std::endl;
	std::cout << RED << "SEARCH:\t" << RESET << CYAN << "display a specific contact" << RESET << std::endl;
	std::cout << RED << "EXIT:\t" << RESET << CYAN << "exit the program" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << "> ";
}

void	Phonebook::printWelcome()
{
	std::cout << GREEN << "------------------------------------------" << RESET << std::endl;
	std::cout << GREEN << "| Welcome to Andrew's Awesome Phonebook! |" << RESET << std::endl;
	std::cout << GREEN << "------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
}
