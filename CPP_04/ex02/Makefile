# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 20:06:32 by ebennix           #+#    #+#              #
#    Updated: 2024/01/16 15:34:05 by ebennix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := test00

CPP := clang++

CPPFLAGS := -Wall -Wextra -Werror

INC := Animal.hpp \

FILE := main \
		Animal \

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