# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 02:51:55 by root              #+#    #+#              #
#    Updated: 2024/05/04 03:05:46 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE := Exo

CPP := c++ -std=c++98

CPPFLAGS := -wall -Wextra -Wshadow
# -werror

HEADERS := Bureaucrat.hpp

FILES := main.cpp	Bureaucrat.cpp

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

git : fclean
	sh ../../push.sh

################################################################################ 

.PHONY: clean fclean re git
