/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 05:11:15 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 19:09:51 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	forms[0] = new PresidentialPardonForm("presidential pardon request");
	forms[1] = new RobotomyRequestForm("robotomy request");
	forms[2] = new ShrubberyCreationForm("shrubbery creation request");
}

Intern::Intern(const Intern& other)
{
	for (int i = 0; i < 3; i++)
	{
		delete forms[i];
		forms[i] = other.forms[i];
	}
}

Intern& Intern::operator=(Intern& other)
{
	return other;
}

Intern::~Intern()
{
	for (int i = 0; i < 3; i++)
		delete forms[i];
}

AForm* Intern::makeForm(const std::string& req, const std::string& name)
{
	for (int i = 0; i < 3; i++)
	{
		if (req == forms[i]->getName())
			return forms[i]->clone(name);
	}
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form Not found exception !!\n";
}
