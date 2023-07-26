/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:17:08 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 17:43:06 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception {
	virtual const char *what() const throw() {
		return ("GradeTooHighException: The highest grade is 1\n");
	}
};

class AForm::GradeTooLowException : public std::exception {
	virtual const char *what() const throw() {
		return ("GradeTooLowException: The lowest grade is 150\n");
	}
};

class AForm::UnsignedFormException : public std::exception {
	virtual const char *what() const throw() {
		return ("UnsignedFormException: This form needs to be signed before being executed\n");
	}
};

AForm::AForm() : _name("Noname"), _signed(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
		if (this->_execGrade < 1 || this->_signGrade < 1)
			throw GradeTooHighException();
		else if (this->_execGrade > 150 || this->_signGrade > 150)
			throw GradeTooLowException();
	}

AForm::~AForm() {}

AForm::AForm(const AForm &cp) :
	_name(cp._name), _signed(cp._signed), _signGrade(cp._signGrade), _execGrade(cp._execGrade) {}

AForm &AForm::operator=(const AForm &cp) {
	this->_signed = cp._signed;
	return (*this);
}

std::string const AForm::getName() const {
	return (this->_name);
}

bool AForm::isSigned() const {
	return (this->_signed);
}

int AForm::getSignGrade() const {
	return (this->_signGrade);
}

int AForm::getExecGrade() const {
	return (this->_execGrade);
}

void AForm::beSigned(const Bureaucrat &b1) {
	if (this->_signGrade < b1.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!this->_signed)
		throw UnsignedFormException();
	else if (this->_execGrade < executor.getGrade())
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
	os << "Form name: " << f.getName() << std::endl;
	os << "Signed: " << f.isSigned() << std::endl;
	os << "Sign grade: " << f.getSignGrade() << std::endl;
	os << "Exec grade: " << f.getExecGrade() << std::endl;
	return (os);
}
