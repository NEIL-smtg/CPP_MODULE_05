/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:27:15 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 02:00:22 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: name("NEIL"), gradeRequired(75), gradeExec(75)
{
	this->_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form& other):
name(other.name),
gradeRequired(other.gradeRequired),
gradeExec(other.gradeExec)
{
	this->_signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}

Form::Form(std::string name, int gradeReq, int gradeExec):
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

std::string Form::getName()
{
	return this->name;
}

int	Form::getGradeRequired()
{
	return this->gradeRequired;
}

int	Form::getGradeExec()
{
	return this->gradeExec;
}

bool	Form::getSigned()
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= this->gradeRequired && b.getGrade() <= this->gradeExec)
	{
		this->_signed = true;
		b.signForm(this->name, this->_signed);
	}
	else
	{
		b.signForm(this->name, this->_signed);
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& out, Form& f)
{
	out << f.getName();
	out << " , form gradeRequired : " << f.getGradeRequired();
	out << " , with gradeExec : " << f.getGradeExec();
	out << " , ";
	if (f.getSigned())
		out << "is signed.\n";
	else
		out << "not signed\n"; 
	return out;
}
