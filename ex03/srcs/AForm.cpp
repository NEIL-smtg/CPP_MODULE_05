/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:27:15 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 02:00:22 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm()
: name("NEIL"), gradeRequired(75), gradeExec(75)
{
	this->_signed = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& other):
name(other.name),
gradeRequired(other.gradeRequired),
gradeExec(other.gradeExec)
{
	this->_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}

AForm::AForm(std::string name, int gradeReq, int gradeExec):
name(name),
gradeRequired(gradeReq),
gradeExec(gradeExec)
{
	this->_signed = false;
	if (this->gradeRequired < 1 || this->gradeExec < 1)
		throw GradeTooHighException();
	else if (this->gradeRequired > 150 || this->gradeExec > 150)
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
	return this->name;
}

int	AForm::getGradeRequired() const
{
	return this->gradeRequired;
}

int	AForm::getGradeExec() const
{
	return this->gradeExec;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeRequired && b.getGrade() <= this->gradeExec)
	{
		this->_signed = true;
		b.signForm(*this);
	}
	else
	{
		b.signForm(*this);
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& out, AForm& f)
{
	out << f.getName();
	out << " , Aform gradeRequired : " << f.getGradeRequired();
	out << " , with gradeExec : " << f.getGradeExec();
	out << " , ";
	if (f.getSigned())
		out << "is signed.\n";
	else
		out << "not signed\n"; 
	return out;
}
