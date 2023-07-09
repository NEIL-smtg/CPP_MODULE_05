/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:17:28 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 01:54:02 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				_signed;
		const int			gradeRequired;
		const int			gradeExec;
	public:
		AForm();
		AForm(std::string name, int gradeReq, int gradeExex);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeRequired() const;
		int			getGradeExec() const;
		void		beSigned(Bureaucrat& b);
		virtual void		execute(Bureaucrat const& executor) const=0;
		virtual AForm*		clone(const std::string& name)=0;

		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw()
				{
					return "AForm Grade Too High\n";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "AForm Grade Too Low\n";
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form not signed\n";
				}
		};
};

std::ostream& operator<<(std::ostream& out, AForm& f);

# endif
