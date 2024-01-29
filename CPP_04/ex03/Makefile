# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:35:48 by ebennix           #+#    #+#              #
#    Updated: 2024/01/29 21:34:42 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_03

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

INC := ICharacter.hpp IMateriaSource.hpp AMateria.hpp Cure.hpp Ice.cpp 

FILE := main \
		AMateria \
		Cure \
		Ice \
		ICharacter \

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
