/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:11:39 by arodgers          #+#    #+#             */
/*   Updated: 2024/07/03 19:13:02 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact{

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int		_index;
	
	public:
		void		createContact(int i);
		void		setFirstName(void);
		void		setLastName(void);
		void		setNickName(void);
		void		setNumber(void);
		void		setSecret(void);
		void		setIndex(int i);
		void		printInfo(void);
		void		showInfo(void);
		std::string	trimValue(std::string arg);
		bool		isValidIndex(void);
};

#endif
