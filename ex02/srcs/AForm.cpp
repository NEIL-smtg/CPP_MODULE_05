/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:55:44 by suchua            #+#    #+#             */
/*   Updated: 2023/05/17 14:18:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
: name("NULL"), gradeSign(75), gradeExec(85)
{
	this->sign = false;
	std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(std::string newName, int newGrdSign, int newGrdExec)
: name(newName), gradeSign(newGrdSign), gradeExec(newGrdExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
		throw GradeTooHighException();
	else if (this->gradeSign > 150 || this->gradeExec > 150)
		throw GradeTooLowException();
	this->sign = false;
	std::cout << "AForm Constructor (params) called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm exiting.." << std::endl;
}

AForm::AForm(const AForm& other)
: name(other.name),
gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
	this->sign = other.sign;
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	this->sign = other.sign;
	return *this;
}

const std::string	AForm::getName()
{
	return this->name;
}

bool	AForm::getSign()
{
	return this->sign;
}

int	AForm::getGradeSign()
{
	return this->gradeSign;
}

int AForm::getGradeExec()
{
	return this->gradeExec;
}

std::ostream&	operator<<(std::ostream& out, AForm& Aform)
{
	out << "\n###AFORM###" << std::endl;
	out << "Name = " << Aform.getName() << std::endl;
	out << "Signed = " << Aform.getSign() << std::endl;
	out << "GradeSign = " << Aform.getGradeSign() << std::endl;
	out << "GradeExec = " << Aform.getGradeExec() << std::endl;
	return (out);
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->gradeSign || b.getGrade() > this->gradeExec)
	{
		b.signForm(this->sign);
		throw GradeTooLowException();
	}
	else
	{
		this->sign = true;
		b.signForm(this->sign);
	}
}
