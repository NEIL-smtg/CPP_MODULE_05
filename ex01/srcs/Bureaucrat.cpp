/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:47:11 by suchua            #+#    #+#             */
/*   Updated: 2023/05/16 01:21:01 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():name("NULL")
{
	std::cout << "Default contructor called" << std::endl;
	this->grade = 75;
}

Bureaucrat::Bureaucrat(const std::string& newName, int grade)
: name(newName)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name)
{
	this->grade = other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat exiting..." << std::endl;
}

int	Bureaucrat::getGrade()
{
	return this->grade;
}

const std::string Bureaucrat::getName()
{
	return this->name;	
}

void	Bureaucrat::gradeDecrease()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::gradeIncrease()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat& b)
{
	stream << b.getName();
	stream << ", bureaucrat grade ";
	stream << b.getGrade();
	stream << "." << std::endl;
	return stream;
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getSign())
		std::cout << "bureaucrat signed form";
	else
	{
		std::cout << "bureaucrat couldn't sign form because ";
		std::cout << this->name << "'s grade is " << this->grade;
		std::cout << " and the grade required to sign is " << form.getGradeSign() << std::endl;
	}
}
