/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:27:29 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 13:41:22 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {
	virtual const char *what() const throw() {
		return ("GradeTooHighException: The highest grade is 1\n");
	}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	virtual const char *what() const throw() {
		return ("GradeTooLowException: The lowest grade is 150\n");
	}
};

Bureaucrat::Bureaucrat() : _name("Noname"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	} else {
		this->_grade = grade;
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &cp) {
	*this = cp;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cp) {
	// this->_name cannot be modified, due to it is a constant.
	this->_grade = cp._grade;
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1) {
		throw GradeTooHighException();
	} else {
		this->_grade--; // 1 is higher than 150. Both are the limits.
	}
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150) {
		throw GradeTooLowException();
	} else {
		this->_grade++; // 1 is higher than 150. Both are the limits.
	}
}

void Bureaucrat::signForm(const Form &form) {
	if (form.getSignGrade() < this->_grade)
		std::cout << this->_name << "couldn't sign" << form << "because grade is too low." << std::endl;
	else
		std::cout << this->_name << " signed the following form:\n" << form << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
