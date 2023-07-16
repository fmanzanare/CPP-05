/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:34:49 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/16 14:03:51 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	Form f1("f1", 5, 5);
	Form f2("f2", 149, 149);

	Bureaucrat b1("Paco", 1);
	Bureaucrat b2("Antonio", 150);

	b1.signForm(f1);

	b2.signForm(f2);

	return (0);
}
