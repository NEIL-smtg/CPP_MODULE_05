/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:24:07 by suchua            #+#    #+#             */
/*   Updated: 2023/05/17 20:20:12 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeSign;
		const int			gradeExec;
	public:
		AForm();
		AForm(std::string newName, int newGrdSign, int newGrdExec);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);

		//exception
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade too high.";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
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

std::ostream&	operator<<(std::ostream& out, AForm& AForm);

#endif
