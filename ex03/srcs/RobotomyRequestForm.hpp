/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:13:26 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 18:52:39 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public virtual AForm
{
	private:
		const std::string name;
		const int	gradeReq;
		const int	gradeExec;
	public:
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm& operator=(RobotomyRequestForm& other);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();
		virtual void			execute(Bureaucrat const& executor) const;
		virtual AForm*	clone(const std::string& name);

};

#endif
