/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:04 by arodgers          #+#    #+#             */
/*   Updated: 2024/07/18 12:19:03 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	trimString(std::string arg)
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

bool		Contact::isValidIndex()
{
	return (_firstName.empty());
}

std::string	Contact::trimValue(std::string arg)
{
	if (arg.length() > 10)
		arg = arg.substr(0, 9) + ".";
	return (arg);
}

void	Contact::showInfo()
{
	std::cout << std::endl;
	std::cout << "Index: " << _index << std::endl;
	std::cout << "First name: " <<_firstName << std::endl;
	std::cout << "Last name: " <<_lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
	std::cout << std::endl;
}

void	Contact::printInfo()
{
	if (_firstName.empty() || _lastName.empty() || _nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << _index;
	std::cout << "|" << std::setw(10) << trimValue(_firstName);
	std::cout << "|" << std::setw(10) << trimValue(_lastName);
	std::cout << "|" << std::setw(10) << trimValue(_nickName);
	std::cout << "|" << std::endl;
}

void	Contact::setIndex(int i)
{
	_index = (i % 8) + 1;
}

void	Contact::setSecret()
{
	std::cout << "Please enter the contact's darkest secret: " << std::endl;

	std::getline(std::cin, _darkestSecret);
	if (_darkestSecret.empty())
	{
		std::cout << "An answer must be provided.\n";
		setSecret();
	}

	_darkestSecret = trimString(_darkestSecret);
}

void	Contact::setNumber()
{
	std::cout << "Please enter the contact's phone number: " << std::endl;
	getline(std::cin, _phoneNumber);
	if (_phoneNumber.empty())
	{
		std::cout << "A number must be provided.\n";
		setNumber();
	}
	_phoneNumber = trimString(_phoneNumber);

	for (size_t i = 0; i < _phoneNumber.length(); i++)
	{
		if (!std::isdigit(_phoneNumber[i]))
		{
			std::cout << "Invalid number.\n";
			setNumber();
			break ;
		}
	}
}

void	Contact::setNickName()
{
	std::cout << "Please enter the contact's nickname: " << std::endl;

	std::getline(std::cin, _nickName);
	if (_nickName.empty())
	{
		std::cout << "A name must be provided.\n";
		setNickName();
	}

	_nickName = trimString(_nickName);
}

void	Contact::setLastName()
{
	std::cout << "Please enter the contact's last name: " << std::endl;

	std::getline(std::cin, _lastName);
	if (_lastName.empty())
	{
		std::cout << "A name must be provided.\n";
		setLastName();
	}
	_lastName = trimString(_lastName);
	for (size_t i = 0; i < _lastName.length(); i++)
	{
		if (!std::isalpha(_lastName[i]))
		{
			std::cout << "Invalid name.\n";
			setLastName();
			break ;
		}
	}
}

void	Contact::setFirstName()
{
	std::cout << "Please enter the contact's first name: " << std::endl;

	std::getline(std::cin, _firstName);
	if (_firstName.empty())
	{
		std::cout << "A name must be provided.\n";
		setFirstName();
	}
	_firstName = trimString(_firstName);
	for (size_t i = 0; i < _firstName.length(); i++)
	{
		if (!std::isalpha(_firstName[i]))
		{
			std::cout << "Invalid name.\n";
			setFirstName();
			break ;
		}
	}
}

void	Contact::createContact(int i)
{
	setFirstName();
	setLastName();
	setNickName();
	setNumber();
	setSecret();
	setIndex(i);
}
