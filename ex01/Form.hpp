#pragma once

# include <fstream>
# include <iomanip>
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
{
private:

	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExec;

public:

	Form();
	Form(std::string name, const int toSign, const int toExec);
	Form(const Form &copy);
	~Form();
	Form &operator=(const Form &os);

	void beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
