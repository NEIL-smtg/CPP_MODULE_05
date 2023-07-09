/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:43:30 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 01:59:13 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("NEIL")
{
	this->grade = 75;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name)
{
	this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

std::string Bureaucrat::getName()
{
	return this->name;
}

int	Bureaucrat::getGrade()
{
	return this->grade;
}

void	Bureaucrat::upGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void	Bureaucrat::downGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bueaucrat grade " << b.getGrade() << std::endl;
	return out;
}

void	Bureaucrat::signForm(std::string form, bool _signed)
{
	if (_signed)
		std::cout << this->name << " signed form\n";
	else
		std::cout << this->name << " couldn't sign " << form << " because ";
}
