/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:07:32 by suchua            #+#    #+#             */
/*   Updated: 2023/07/09 18:53:10 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public virtual AForm
{
	private:
		const std::string name;
		const int	gradeReq;
		const int	gradeExec;
	public:
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		virtual void	execute(Bureaucrat const& executor) const;
		virtual AForm*			clone(const std::string& name);
};

void	generateShrubberyTree(const char *name);
#endif
