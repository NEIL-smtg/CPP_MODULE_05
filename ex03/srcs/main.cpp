/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:08:11 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 19:28:09 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << rrf->getName();

		Bureaucrat b("beur", 2);
		try
		{
			rrf->execute(b);
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		rrf->beSigned(b);
		try
		{
			rrf->execute(b);
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		delete rrf;
	}
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon request", "Bender");

		std::cout << rrf->getName();

		Bureaucrat b("beur", 2);
		try
		{
			rrf->execute(b);
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		rrf->beSigned(b);
		try
		{
			rrf->execute(b);
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		delete rrf;
	}
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation request", "Bender");

		std::cout << rrf->getName();

		Bureaucrat b("beur", 2);
		try
		{
			rrf->execute(b);
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		rrf->beSigned(b);
		try
		{
			rrf->execute(b);
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		delete rrf;
	}
	{
		Intern someRandomIntern;
		AForm* rrf = NULL;
		try{
			rrf = someRandomIntern.makeForm("random request", "Bender");
		}catch (std::exception& e)
		{
			std::cerr << e.what();
		}
		if (rrf)
			delete rrf;
	}
	return (0);
}