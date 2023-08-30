/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:37:46 by suchua            #+#    #+#             */
/*   Updated: 2023/08/29 17:02:47 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;


// class Exception
// {
	
// }
class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string getName();
		int			getGrade() const;
		void		upGrade();
		void		downGrade();
		void		signForm(AForm& form);
		void		executeForm(AForm const & form);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade too high !!\nUsage (1 - 150).\n";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade too low !!\nUsage (1 - 150).\n";
				}
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b);

#endif
