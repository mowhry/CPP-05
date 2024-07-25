#pragma once

# include <fstream>
# include <iomanip>
# include <iostream>
# include <string>
#include <exception>

class Bureaucrat
{
private:

	int					_grade;
	const std::string	_name;

public:

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &os);
	const std::string	getName()const;
	const int	getGrade()const;
	void		gradePlus();
	void		gradeMinus();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
