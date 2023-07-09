/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 05:08:37 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 18:56:14 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm *forms[3];
	public:
		Intern();
		~Intern();
		Intern& operator=(Intern& other);
		Intern(const Intern& other);
		AForm* makeForm(const std::string& req, const std::string& name);

		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
#endif
