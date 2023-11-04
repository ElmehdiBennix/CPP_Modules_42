# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:38 by ebennix           #+#    #+#              #
#    Updated: 2023/11/04 12:53:50 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Moar_brainz

CC := c++ -std=c++98

HEADER := Zombie.hpp

CPPFLAGS := -std=c++98 -Wall -Wextra
#  -Werror

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

%.o : %.c $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)

re : fclean all

git :
	sh ../push.sh

################################################################################

.PHONY : all clean fclean re git
