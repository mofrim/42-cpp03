# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 11:45:58 by fmaurer           #+#    #+#              #
#    Updated: 2025/08/03 13:49:26 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Simple skeleton Makefile

NAME 		= clap0

VPATH = .
SRC	= main.cpp ClapTrap.cpp utils.cpp
OBJDIR	= obj
OBJS		= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
CFLAGS	= -Wall -Werror -Wextra -std=c++98
CPP			= c++
HDR			= ClapTrap.hpp utils.hpp

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# will never try to compile HDR or any other prequesite specified after `%.c`.
# this is because the `%.o` and matched against all .c-files in the current dir.
$(OBJDIR)/%.o: %.cpp $(HDR) | $(OBJDIR)
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

nodebug: CFLAGS += -DDEBUG=0
nodebug:
	$(CPP) $(CFLAGS) -o $(NAME) $(SRC)

debug:
	$(CPP) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re nodebug debug
