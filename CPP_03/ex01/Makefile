# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:52:08 by ebennix           #+#    #+#              #
#    Updated: 2024/01/11 06:33:51 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := test00

CPP := clang++

CPPFLAGS := -Wall -Wextra -Werror

INC := ClapTrap.hpp ScavTrap.hpp

FILE := main \
		ClapTrap \
		ScavTrap \

SRC := $(FILE:=.cpp)

OBJ := $(SRC:.cpp=.o)

################################################################################ 

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(EXE)

%.o: %.cpp $(INC)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

################################################################################ 

.PHONY: all clean fclean re