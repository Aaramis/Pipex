# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 17:38:06 by agardett          #+#    #+#              #
#    Updated: 2022/09/29 10:45:02 by agardett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
#  VARIABLES  #
###############

# 	FILES
SRC_F		= ./SRCS/
LIBFT_F		= ./libft
FILES		= utils

SRCS		= $(addsuffix .c,$(FILES))
OBJS		= $(addprefix $(SRC_F),$(addsuffix .o,$(FILES)))

#	INCLUDES
INC		= ./INCS
INC_L		= $(LIBFT_F)/INCS
PIPEX_H		= push_swap.h
NAME_LIB	= libft.a
LIB_F		= $(LIBFT_F)/$(NAME_LIB)

#	COMPILER
CC		= cc -g
SANITIZE	= -fsanitize=address
RM		= rm -f
LINKER		= ar rcs 
WFLAGS		= -Wall -Werror -Wextra
IFLAGS		= -I $(INC) -I $(INC_L)
IFLAGS2		= -I .$(INC) -I .$(INC_L)
OFLAGS		= -O2 -funroll-loops
GFLAGS		= $(WFLAGS) $(IFLAGS) $(OFLAGS)
LIB		= $(LIBFT_F)/$(NAME_LIB)

#	OUTPUT
NAME_EX		= pipex

############
#  COLORS  #
############

BLACK		= "\033[1;30m"
RED		= "\033[1;31m"
GREEN		= "\033[1;32m"
CYAN		= "\033[1;36m"
PURPLE		= "\033[1;35m"
WHITE		= "\033[1;37m"
EOC		= "\033[0;0m"

##############
#  COMMANDS  #
##############

all:		$(NAME_EX)

$(NAME_EX):
		@echo $(CYAN) "\n"					\
		"#######################################\n"		\
		"   Compilation des fichiers en cours   \n"	 	\
		"#######################################\n"		\
		$(EOC)
		@cd $(LIBFT_F) && $(MAKE) all
		@cd $(SRC_F) && $(CC) $(WFLAGS) $(IFLAGS2) -c $(SRCS)
		@$(CC) $(GFLAGS) $(SRC_F)main.c $(OBJS) $(LIB_F) -o $(NAME_EX)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully compiled -------\n"		\
		$(EOC)

clean:
		@$(RM) $(OBJS)
		@cd $(LIBFT_F) && $(MAKE) clean


fclean:		clean
		@echo $(CYAN) "\n"					\
		"#######################################\n"		\
		"Nettoyage Complet des fichiers en cours\n"	 	\
		"#######################################\n"		\
		$(EOC)
		@cd $(LIBFT_F) && $(MAKE) fclean
		@$(RM) $(NAME_EX)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully cleaned -------\n"		\
		$(EOC)

re: 		fclean
		@$(MAKE) all

.PHONY: 	all clean fclean re
.SILENT:	all
