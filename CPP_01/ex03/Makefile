# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:38 by ebennix           #+#    #+#              #
#    Updated: 2024/01/27 16:33:41 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := violence

CPP := c++ -std=c++98

HEADER := HumanA.hpp HumanB.hpp Weapon.hpp

CPPFLAGS := -Wall -Wextra -Werror

SRC := main \
	   HumanA \
	   HumanB \
	   Weapon \

FILES := $(SRC:=.cpp)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf

################################################################################

all : $(EXE)

$(EXE) : $(OBJ) 
	$(CPP)  $(OBJ) -o $(EXE)

%.o : %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c -o $@ $< 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git : fclean
	sh ../../push.sh

################################################################################

.PHONY : clean fclean re git
