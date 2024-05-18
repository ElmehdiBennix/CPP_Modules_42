# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:49:22 by ebennix           #+#    #+#              #
#    Updated: 2024/05/17 20:36:54 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_02

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Wshadow
# -werror

HEADERS := 	AForm.hpp \
			Bureaucrat.hpp \
			PresidentialPardonForm.hpp \
 			RobotomyRequestFrom.hpp	   \
 			ShrubberyCreationForm.hpp  \

FILES := main.cpp \
		 AForm.cpp \
		 Bureaucrat.cpp \

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
