/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:35:00 by suchua            #+#    #+#             */
/*   Updated: 2023/05/17 14:05:23 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& newName, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		//exception
		class	GradeTooHighException : public std::exception{
			public:
				const char* what() const throw()
				{
					return "Grade too high.\nUsage : grade should be between 1 - 150";
				}
		};

		class	GradeTooLowException : public std::exception{
			public:
				const char* what() const throw()
				{
					return "Grade too low.\nUsage : grade should be between 1 - 150";
				}
		};

		//getters
		const std::string	getName();
		int					getGrade();

		//increment, decrement of grade
		void				gradeIncrease();
		void				gradeDecrease();

		//member function
		void	signForm(bool sign);
};

std::ostream&	operator<<(std::ostream& stream, Bureaucrat& b);

#endif
