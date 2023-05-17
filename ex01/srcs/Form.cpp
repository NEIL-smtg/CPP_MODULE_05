/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:55:44 by suchua            #+#    #+#             */
/*   Updated: 2023/05/17 14:12:40 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: name("NULL"), gradeSign(75), gradeExec(85)
{
	this->sign = false;
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(std::string newName, int newGrdSign, int newGrdExec)
: name(newName), gradeSign(newGrdSign), gradeExec(newGrdExec)
{
	if (this->gradeSign < 1 || this->gradeExec < 1)
		throw GradeTooHighException();
	else if (this->gradeSign > 150 || this->gradeExec > 150)
		throw GradeTooLowException();
	this->sign = false;
	std::cout << "Form Constructor (params) called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form exiting.." << std::endl;
}

Form::Form(const Form& other)
: name(other.name),
gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
	this->sign = other.sign;
	std::cout << "Form copy constructor called" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	this->sign = other.sign;
	return *this;
}

const std::string	Form::getName()
{
	return this->name;
}

bool	Form::getSign()
{
	return this->sign;
}

int	Form::getGradeSign()
{
	return this->gradeSign;
}

int Form::getGradeExec()
{
	return this->gradeExec;
}

std::ostream&	operator<<(std::ostream& out, Form& form)
{
	out << "\n###FORM###" << std::endl;
	out << "Name = " << form.getName() << std::endl;
	out << "Signed = " << form.getSign() << std::endl;
	out << "GradeSign = " << form.getGradeSign() << std::endl;
	out << "GradeExec = " << form.getGradeExec() << std::endl;
	return (out);
}

void	Form::beSigned(Bureaucrat& b)
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
