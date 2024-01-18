# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:45:13 by ebennix           #+#    #+#              #
#    Updated: 2024/01/18 09:41:38 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := PhoneBook

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

HEADER := PhoneBook.hpp Contacts.hpp \

SRC := main \
	   Contacts \
	   PhoneBook \

FILES := $(SRC:=.cpp)

OBJ := $(FILES:.cpp=.o)

RM := rm -rf

################################################################################

all : $(EXE)

$(EXE) : $(OBJ)
	$(CPP) $(OBJ) -o $(EXE) 

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

.PHONY : all clean fclean re git
