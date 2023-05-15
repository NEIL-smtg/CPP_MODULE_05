/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:34:53 by suchua            #+#    #+#             */
/*   Updated: 2023/05/15 20:36:11 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "\n\n####################TEST_1####################" << std::endl;
		try
		{
			Bureaucrat bur("neil", 232);

			std::cout << bur.getName() << std::endl;
			std::cout << bur.getGrade() << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_2####################" << std::endl;
		try
		{
			Bureaucrat bur("neil", -232);

			std::cout << bur.getName() << std::endl;
			std::cout << bur.getGrade() << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_3####################" << std::endl;
		try
		{
			Bureaucrat bur("neil", 66);

			std::cout << "name = " << bur.getName() << std::endl;
			std::cout << "grade = " << bur.getGrade() << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_4####################" << std::endl;
		try
		{
			Bureaucrat bur1;
			Bureaucrat bur2("person2", 150);
			Bureaucrat bur3(bur2);

			std::cout << "name = " << bur1.getName() << std::endl;
			std::cout << "grade = " << bur1.getGrade() << std::endl;

			std::cout << "name = " << bur2.getName() << std::endl;
			std::cout << "grade = " << bur2.getGrade() << std::endl;

			std::cout << "name = " << bur3.getName() << std::endl;
			std::cout << "grade = " << bur3.getGrade() << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
