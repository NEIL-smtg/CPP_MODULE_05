/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 03:01:37 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 18:59:42 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void	generate_noise(std::string name)
{
	std::cout << "####### DRILL NOISE ALERT #######\n";
	std::cout << "BLACKPINK IN YOUR AREA\n";
	std::cout << "####### END #######\n";
	std::cout << "Form " << name;
	std::cout << " has been robotomized 50% of the time\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string name):
AForm(name, 72, 45),
name(name),
gradeReq(72),
gradeExec(45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	return other;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
AForm(other.name, other.gradeReq, other.gradeExec),
name(other.name),
gradeReq(other.gradeReq),
gradeExec(other.gradeExec)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	generate_noise(getName());
}

AForm*	RobotomyRequestForm::clone(const std::string& name)
{
	return new RobotomyRequestForm(name);
}
