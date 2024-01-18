# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:52:08 by ebennix           #+#    #+#              #
#    Updated: 2024/01/18 09:55:56 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_00

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

HEADER := ClapTrap.hpp \

FILE := main \
		ClapTrap \

SRC := $(FILE:=.cpp)

OBJ := $(SRC:.cpp=.o)

RM := rm -rf

################################################################################ 

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXE)

re: fclean all

git : fclean
	sh ../../push.sh

################################################################################ 

.PHONY: all clean fclean re git