/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:08:11 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 01:55:47 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::cout << "\n\n####################TEST_1####################" << std::endl;
		
		Form form("form1", 20, 30);
		std::cout << form << std::endl;

		Bureaucrat b("bur1", 50);
		std::cout << b;

		try
		{
			form.beSigned(b);
		}
		catch (const Form::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_2####################" << std::endl;
		
		Form form("form1", 70, 60);
		std::cout << form << std::endl;

		Bureaucrat b("bur1", 50);
		std::cout << b;
		try
		{
			form.beSigned(b);
		}
		catch (const Form::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_3####################" << std::endl;
		
		Form f1("form1", 50, 50);
		Form f2(f1);
		Form f3 = f2;
		std::cout << f3 << std::endl;

		Bureaucrat b("bur1", 50);
		std::cout << b;
		try
		{
			f3.beSigned(b);
		}
		catch (const Form::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_4####################" << std::endl;
		try
		{
			Form f1("form1", 0, 30);
		}
		catch (const Form::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n####################TEST_5####################" << std::endl;
		try
		{
			Form f1("form1", 20, 0);
		}
		catch (const Form::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}