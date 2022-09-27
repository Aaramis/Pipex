# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:38:06 by agardett          #+#    #+#              #
#    Updated: 2022/09/10 10:45:02 by agardett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	FILES
SRCS_F 		= ./SRCS/
FILES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen 	\
	ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat 		\
	ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr 	\
	ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr 		\
	ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri 		\
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_uitoa 		\
	ft_putnbrbase_fd ft_strpchr ft_strndup					\
	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back 		\
	ft_lstdelone ft_lstmemdel ft_lstclear ft_lstiter ft_lstmap		\
	ft_printf ft_printf_tools ft_printf_p					\
	get_next_line get_next_line_utils

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addprefix $(SRCS_F),$(addsuffix .o, $(FILES)))

#	HEADERS
SRCS_H		= ./INCS
LIBFT 		= libft.h
PRINTF 		= ft_pirintf.h
GNL		= get_next_line.h

#	LIBRARY
NAME_LIB	= libft.a

#	OUTPUT

#	COMPILER
CC 		= gcc
RM 		= rm -f
LINKER 		= ar rcs
OFLAGS 		= -O2 -funroll-loops
WFLAGS 		= -Wall -Werror -Wextra 
IFLAGS		= -I $(SRCS_H)
GFLAGS		= $(WFLAGS) $(IFLAGS) $(OFLAGS)

#	OUTPUT
NAME_EX = tester
NAME = test

##############
##  COLORS  ##
##############

BLACK		= "\033[1;30m"
RED		= "\033[1;31m"
GREEN		= "\033[1;32m"
BLUE		= "\033[1;34m"
PURPLE		= "\033[1;35m"
CYAN		= "\033[1;36m"
WHITE		= "\033[1;37m"
EOC		= "\033[0;0m"

################
##  COMMANDS  ##
################

all:		$(NAME_EX)

$(NAME_EX):	
		@cd $(SRCS_F) && $(CC) $(WFLAGS) -I .$(SRCS_H) -c $(SRCS)
		@$(LINKER) $(NAME_LIB) $(OBJS)
		@echo $(BLUE) "Libft Compiled" $(EOC)

clean:		
		@$(RM) $(OBJS)

fclean: 	clean
		@$(RM) $(NAME_LIB) $(NAME_EX)
		@echo $(BLUE) "Libft fully clean" $(EOC)

re:		fclean
		@$(MAKE) all

.PHONY:		all clean fclean re
