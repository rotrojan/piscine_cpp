# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    settings.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2022/01/18 15:33:10 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = convert

# The list of the all the sources, because $(wildcard *.c) is too dangerous
SRCS =	main.cpp		\
		Literal.cpp		\

# The file where make will look for all the sources (in addition to the root
# directory of the Makefile)
SRCS_DIR = srcs

# The libraries used
LIBS =

# The directory where all object and dependency files will be compiled
OBJS_DIR = .objs

# The file where make will look for all the header files
INCLUDES_DIR = includes

# The C++ compiler
CXX = c++

# The C++ compilation flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

# The characters and the length of the progress bar will adjust automatically
PROGRESS_BAR = -------------------------------------------------------------------
FILLING_CHAR = \#
