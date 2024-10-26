# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodgers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 13:44:55 by arodgers          #+#    #+#              #
#    Updated: 2024/09/14 18:39:05 by arodgers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

%.o : %.cpp
	$(C++) $(FLAGS) $< -o $@ -c 

$(NAME): $(OBJS) $(SRCS)
	$(C++) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
