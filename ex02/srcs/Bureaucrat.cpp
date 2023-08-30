/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:43:30 by suchua            #+#    #+#             */
/*   Updated: 2023/08/29 17:11:36 by suchua           ###   ########.fr       */
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

int	Bureaucrat::getGrade() const
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

void	Bureaucrat::signForm(AForm& form)
{	
	if (form.getSigned())
		std::cout << this->name << " signed form\n";
	else
		std::cout << this->name << " couldn't sign " << form << " because ";
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
