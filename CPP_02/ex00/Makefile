# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 13:58:53 by ebennix           #+#    #+#              #
#    Updated: 2024/01/27 16:33:15 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_00

CPP := c++ -std=c++98

CPPFLAGS := -Wall -Wextra -Werror

HEADER := Fixed.hpp

FILE := main \
		Fixed \

SRC := $(FILE:=.cpp)

OBJ :=$(SRC:.cpp=.o)

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

.PHONY: clean fclean re git