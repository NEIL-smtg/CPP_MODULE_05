/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:14:12 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 18:51:17 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public virtual AForm
{
	private:
		const std::string name;
		const int	gradeReq;
		const int	gradeExec;
	public:
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm& operator=(PresidentialPardonForm& other);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();
		virtual void		execute(Bureaucrat const& executor) const;
		virtual AForm*		clone(const std::string& name);
};

#endif
