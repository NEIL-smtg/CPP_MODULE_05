/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:47:11 by suchua            #+#    #+#             */
/*   Updated: 2023/05/15 20:44:06 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
