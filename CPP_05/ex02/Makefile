EXE := Exo_02

CPP := c++ -std=c++98
CPPFLAGS := -Wall -Wextra -Wshadow -Werror

HEADERS := 	AForm.hpp \
			Bureaucrat.hpp \
			PresidentialPardonForm.hpp \
 			RobotomyRequestForm.hpp	   \
 			ShrubberyCreationForm.hpp

FILES := main.cpp \
		 AForm.cpp \
		 Bureaucrat.cpp \
		 RobotomyRequestForm.cpp \
		 ShrubberyCreationForm.cpp \
		 PresidentialPardonForm.cpp

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

git : fclean
	sh ../../push.sh

################################################################################

.PHONY: clean fclean re git
