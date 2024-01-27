# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:52:08 by ebennix           #+#    #+#              #
#    Updated: 2024/01/27 16:32:42 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_01

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

INC := ClapTrap.hpp ScavTrap.hpp \

FILE := main \
		ClapTrap \
		ScavTrap \

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