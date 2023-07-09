/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:08:11 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 01:16:49 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	b("fakePerson1", 200);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			Bureaucrat	b("fakePerson1", 150);
			std::cout << b;
			Bureaucrat	b2("fakePerson2", 1);
			std::cout << b2;

			b.downGrade();
			b2.upGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	{
		try
		{
			Bureaucrat	b("fakePerson1", 150);
			std::cout << b;
			Bureaucrat b2 = b;
			std::cout << b2;
			Bureaucrat b3(b2);
			std::cout << b3;

			b3.upGrade();
			std::cout << b3;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
}
