# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:35:48 by ebennix           #+#    #+#              #
#    Updated: 2024/01/30 12:25:30 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_03

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

INC := AMateria.hpp ICharacter.hpp Ice.cpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp Character.hpp

FILE := main \
		AMateria \
		Ice \
		Cure \
		MateriaSource \
		Character \
		

SRC := $(FILE:=.cpp)

OBJ := $(SRC:.cpp=.o)

RM := rm -rf

################################################################################ 

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

git : fclean
	sh ../../push.sh

################################################################################ 

.PHONY: clean fclean re git
