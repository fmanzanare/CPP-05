/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:55:07 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 17:43:40 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _execGrade;
		AForm();
	public:
		AForm(std::string const name, int const signGrade, int const execGrade);
		virtual ~AForm();
		AForm(const AForm &cp);
		AForm &operator=(const AForm &cp);

		std::string const getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &b1);
		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException;
		class GradeTooLowException;
		class UnsignedFormException;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
