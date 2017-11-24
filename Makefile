##
## EPITECH PROJECT, 2017
## 
## File description:
## makefile
##

NAME		= tanks

CC		= gcc

MAKE		= make -C

LIB		= -L./lib/C -lmy
LIB		+= -lmy_csfml
#LIB		+= -lc_graph_prog
LIB		+= -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-network -lcsfml-audio
LIB		+= -lm

SRCS		= src/main.c
SRCS		+= src/encrypt.c
SRCS		+= src/login.c
SRCS		+= src/add_event.c
SRCS		+= src/login_events.c
SRCS		+= src/init_sprites.c
SRCS		+= src/game_menu.c
SRCS		+= src/menu_events.c
SRCS		+= src/menu_buttons.c

OBJ		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -W -Werror -Wall -Wextra
CFLAGS		+= -I ./include
CFLAGS		+= -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib/C
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(MAKE) lib/C clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) lib/C fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
