/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:17:28 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 01:54:02 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				_signed;
		const int			gradeRequired;
		const int			gradeExec;
	public:
		Form();
		Form(std::string name, int gradeReq, int gradeExex);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string getName();
		bool		getSigned();
		int			getGradeRequired();
		int			getGradeExec();
		void		beSigned(Bureaucrat b);

		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw()
				{
					return "Form Grade Too High\n";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form Grade Too Low\n";
				}
		};
};

std::ostream& operator<<(std::ostream& out, Form& f);

# endif
