#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   MAkefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2024#03#04 15:02:37 by cedmulle          #+#    #+#             *#
#*   Updated: 2024#03#04 15:02:37 by cedmulle         ###   ########.ch       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME	= identify
SRC		= Base.cpp main.cpp
OBJ		= $(SRC:.cpp=.o)
CXX		= c++
CFL		= -Wall -Wextra -Werror -std=c++98 -I.
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFL) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CFL) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
