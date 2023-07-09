/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:08:11 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 05:05:36 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat human("human", 1);
		ShrubberyCreationForm myTree("scf");
		RobotomyRequestForm robotomy("rrf");
		PresidentialPardonForm pardon("ppf");

		std::cout << human << std::endl;

		std::cout << robotomy << std::endl;
		std::cout << myTree << std::endl;
		std::cout << pardon << std::endl;

		myTree.beSigned(human);
		robotomy.beSigned(human);
		pardon.beSigned(human);

		human.signForm(myTree);
		human.signForm(robotomy);
		human.signForm(pardon);

		myTree.execute(human);
		robotomy.execute(human);
		pardon.execute(human);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}