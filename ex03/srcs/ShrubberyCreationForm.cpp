/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:05:22 by suchua            #+#    #+#             */
/*   Updated: 2023/08/30 19:12:13 by suchua           ###   ########.fr       */
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

void	generateShrubberyTree(std::string name)
{
	int			lines	= 20;
	const char	*suffix	= "_shrubbery";
	char		*filename = new char[name.length() + strlen(suffix) + 1];
	strcpy(filename, name.c_str());
	strcat(filename, suffix);
	std::ofstream file(filename);

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
	delete[] filename;
	file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	generateShrubberyTree(getName());
}

AForm*	ShrubberyCreationForm::clone(const std::string& name)
{
	return new ShrubberyCreationForm(name);
}
