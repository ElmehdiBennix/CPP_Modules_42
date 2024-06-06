# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 21:13:24 by ebennix           #+#    #+#              #
#    Updated: 2024/06/06 01:38:04 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo_01

CPP := c++

CPPFLAGS := -Wall -Wextra -Wshadow
# -werror

HEADERS := Serializer.hpp

FILES := main.cpp Serializer.cpp

OBJ := $(FILES:.cpp=.o)

################################################################################

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(OBJ) -o $(EXE)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all

git :
	sh ../../push

################################################################################ 

.PHONY: clean fclean re git
