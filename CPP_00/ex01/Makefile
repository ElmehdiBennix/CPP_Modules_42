# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:45:13 by ebennix           #+#    #+#              #
#    Updated: 2023/11/08 01:22:19 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := phonebook

CC := c++

CPPFLAGS := -std=c++98 -Wall -Wextra -Werror

HEADER := phonebook.hpp

SRC := main \
	   Contacts \
	   Phonebook \

FILES := $(SRC:=.cpp)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf

################################################################################

all : $(EXE)

$(EXE) : $(OBJ)
	$(CC) $(OBJ) -o $(EXE) 

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
