/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:06:27 by suchua            #+#    #+#             */
/*   Updated: 2023/05/17 20:20:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("default_shruberry"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), target(target + "_shruberry") {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubery exiting..." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other) {}
	return *this;
}

std::string ShrubberyCreationForm::getTarget()
{
	return this->target;
}