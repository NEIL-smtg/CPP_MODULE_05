/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 03:06:34 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 19:10:59 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	pardoned_msg(std::string name)
{
	std::cout << "####### PARDON ALERT #######\n";
	std::cout << "Form " << name;
	std::cout << " has been pardoned by Zaphod Beeblebrox\n";
	std::cout << "####### END #######\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) :
AForm(name, 25, 5),
name(name),
gradeReq(25),
gradeExec(5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	return other;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
AForm(other.name, other.gradeReq, other.gradeExec),
name(other.name),
gradeReq(other.gradeReq),
gradeExec(other.gradeExec)
{	
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	pardoned_msg(getName());
}

AForm*	PresidentialPardonForm::clone(const std::string& name)
{
	return new PresidentialPardonForm(name);
}
