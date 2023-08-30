/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:05:22 by suchua            #+#    #+#             */
/*   Updated: 2023/08/29 18:01:52 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstring>


ShrubberyCreationForm::ShrubberyCreationForm(std::string name):
AForm(name, 145, 137),
name(name),
gradeReq(145),
gradeExec(137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	return other;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm(other.name, other.gradeReq, other.gradeExec),
name(other.name),
gradeReq(other.gradeReq),
gradeExec(other.gradeExec)
{
}

void	generateShrubberyTree(char *name)
{
	int	lines = 20;
	std::ofstream file(strcat(name, "_shrubbery"));
	if (!file.is_open())
	{
		std::cerr << "Unable to open the file\n";
		return ;
	}
	for (int i = 0; i < lines; i++)
	{
		for (int a = 0; a < lines - i - 1; a++)
			file << " ";
		for (int y = 0; y < i * 2 + 1; y++)
		{
			if (i == lines - 1)
			{
				int	mid = (i * 2 + 1) / 2;
				if (y >= mid - 3 && y <= mid + 3)
					file << "|";
				else
					file << " ";
			}
			else
			{
				if (y % 2 == 0)
					file << "@";  // Tree leaves symbol (even positions)
				else
					file << "#";  // Tree leaves symbol (odd positions)
			}
		}
		file << std::endl;
	}
	file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	generateShrubberyTree(const_cast<char *>(getName().c_str()));
}
