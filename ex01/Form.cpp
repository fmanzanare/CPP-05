/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:17:08 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 17:05:19 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception {
	virtual const char *what() const throw() {
		return ("GradeTooHighException: The highest grade is 1\n");
	}
};

class Form::GradeTooLowException : public std::exception {
	virtual const char *what() const throw() {
		return ("GradeTooLowException: The lowest grade is 150\n");
	}
};

Form::Form() : _name("Noname"), _signed(false), _signGrade(1), _execGrade(1) {}

Form::Form(std::string const name, int const signGrade, int const execGrade) :
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
		if (this->_execGrade < 1 || this->_signGrade < 1)
			throw GradeTooHighException();
		else if (this->_execGrade > 150 || this->_signGrade > 150)
			throw GradeTooLowException();
	}

Form::~Form() {}

Form::Form(const Form &cp) :
	_name(cp._name), _signed(cp._signed), _signGrade(cp._signGrade), _execGrade(cp._execGrade) {}

Form &Form::operator=(const Form &cp) {
	this->_signed = cp._signed;
	return (*this);
}

std::string const Form::getName() const {
	return (this->_name);
}

bool Form::isSigned() const {
	return (this->_signed);
}

int Form::getSignGrade() const {
	return (this->_signGrade);
}

int Form::getExecGrade() const {
	return (this->_execGrade);
}

void Form::beSigned(const Bureaucrat &b1) {
	if (this->_signGrade < b1.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "Form name: " << f.getName() << std::endl;
	os << "Signed: " << f.isSigned() << std::endl;
	os << "Sign grade: " << f.getSignGrade() << std::endl;
	os << "Exec grade: " << f.getExecGrade() << std::endl;
	return (os);
}
