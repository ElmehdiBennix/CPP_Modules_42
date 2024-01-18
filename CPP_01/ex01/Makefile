# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:38 by ebennix           #+#    #+#              #
#    Updated: 2024/01/18 06:18:17 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Moar_brainz

CC := c++ -std=c++98

HEADER := Zombie.hpp

CPPFLAGS := -Wall -Wextra -Werror

SRC := main \
	   Zombie \
	   zombieHorde \

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
	sh ../../push.sh

################################################################################

.PHONY : all clean fclean re git
