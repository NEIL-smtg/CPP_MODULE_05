/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:24:07 by suchua            #+#    #+#             */
/*   Updated: 2023/05/17 13:41:46 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeSign;
		const int			gradeExec;
	public:
		Form();
		Form(std::string newName, int newGrdSign, int newGrdExec);
		~Form();
		Form(const Form& other);
		Form&	operator=(const Form& other);

		//exception
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade too high.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade too low.";
				}
		};

		//getters
		const std::string	getName();
		bool				getSign();
		int					getGradeSign();
		int					getGradeExec();

		//member functions
		void	beSigned(Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& out, Form& form);

#endif
