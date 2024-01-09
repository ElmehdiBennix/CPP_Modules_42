# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 07:43:20 by ebennix           #+#    #+#              #
#    Updated: 2024/01/09 07:48:08 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := test03

CPP := clang++

CPPFLAGS := -Wall -Wextra -Werror

INC := Fixed.hpp Point.hpp

FILE := main \
		Fixed \
		Point \
		bsp \

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