# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:38 by ebennix           #+#    #+#              #
#    Updated: 2023/11/06 15:02:38 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := violence

CC := c++ 

HEADER := HumanA.hpp HumanB.hpp Weapon.hpp

CPPFLAGS := -std=c++98 -Wall -Wextra -Werror

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
	$(CC)  $(OBJ) -o $(EXE)

%.o : %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c -o $@ $< 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git : fclean
	sh ../push.sh

################################################################################

.PHONY : all clean fclean re git
