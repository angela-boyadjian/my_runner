##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile lib
##
CC	=	gcc

CP	=	cp

AC	=	ar rc

SRCS =		$(wildcard *.c)

RM	=	rm -rf

LDFLAGS	=	../include

CFLAGS	=	-c *.c

NAME	=	libmy.a

$(NAME):
	$(CC) $(CFLAGS)
	$(AC) $(NAME) *.o
	$(CP) $(NAME) ..
	$(CP) my.h ../../include

all:	$(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) libmy.a

re:	fclean all

.PHONY: all clean fclean re