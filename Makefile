##
## Makefile for  in /home/ducate_c/rendu/PSU_2014_my_printf
## 
## Made by Corentin Ducatez
## Login   <ducate_c@epitech.net>
## 
## Started on  Fri Nov 14 16:57:27 2014 Corentin Ducatez
## Last update Wed Apr 29 19:15:26 2015 Corentin Ducatez
##

CC	= gcc

RM	= rm -f

NAME	= 101pong

SRCS	= pong.c

OBJS	= $(SRCS:.c=.o)


all:	  $(NAME)

$(NAME):  $(OBJS)
	  $(CC) $(OBJS) -o $(NAME) -lm

clean:
	  $(RM) $(OBJS)

fclean:   clean
	  $(RM) $(NAME)

re:	  fclean all
