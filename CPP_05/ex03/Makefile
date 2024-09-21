EXE := Exo_03

CPP := c++ -std=c++98
CPPFLAGS := -Wall -Wextra -Werror -Wshadow

HEADERS := 	AForm.hpp \
			Bureaucrat.hpp \
			PresidentialPardonForm.hpp \
 			RobotomyRequestForm.hpp	   \
 			ShrubberyCreationForm.hpp  \
		 	Intern.hpp

FILES := main.cpp \
		 AForm.cpp \
		 Bureaucrat.cpp \
		 RobotomyRequestForm.cpp \
		 ShrubberyCreationForm.cpp \
		 PresidentialPardonForm.cpp  \
		 Intern.cpp

OBJ := $(FILES:.cpp=.o)

################################################################################

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

################################################################################

.PHONY: clean fclean re
