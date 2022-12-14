# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2021/12/20 21:54:05 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include settings.mk

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)
LDFLAGS = $(LIBS:%=-L lib%)
LDLIBS = $(LIBS:%=-l%)
CXXFLAGS += -MMD -MP
MAKEFLAGS += --no-print-directory

# Binaries
MAKE = make
RM = rm -f
MKDIR = mkdir -p

# Debug variables
DEBUG = 0
ifeq ($(shell test -f $(OBJS_DIR)/debug1; echo $$?), 0)
	DEBUG = 1
endif
SANITIZE = 0
ifeq ($(shell test -f $(OBJS_DIR)/sanitize1; echo $$?), 0)
	SANITIZE = 1
endif
ifeq ($(DEBUG), 1)
	CXXFLAGS += -g3
endif
ifeq ($(SANITIZE), 1)
	CXXFLAGS += -fsanitize=address
endif

# Colors ans escape sequences
ESC_SEQ = \033[
BLUE = $(ESC_SEQ)34m
YELLOW = $(ESC_SEQ)33m
GREEN = $(ESC_SEQ)32m
BOLD = $(ESC_SEQ)1m
MOVE_UP = $(ESC_SEQ)1A
ERASE = \r$(ESC_SEQ)K
ERASE_ALL = $(ESC_SEQ)M
ESC_STOP = $(ESC_SEQ)0m

# Variables used for cosmetic purposes
COMPILING_PRINTED = 0
VARIABLES_PRINTED = 0
VARIABLES_INTERLINE_PRINTED = 0
PRINT_INTERLINE = printf '$(YELLOW)$(BOLD)================================================================================$(ESC_STOP)\n'

# Prevents the Makefile from recursively calling itself infinitely
# See $(OBJS) rule
NO_RECURS = 0

# Draw a progress bar during while compiling the sources.
NUM_FILE_BEING_COMPILED = 1
define DRAW_PROGRESS_BAR
	PROGRESS_BAR=$(PROGRESS_BAR) \
	SIZE=$${#PROGRESS_BAR} \
	NB_BAR=`expr $(NUM_FILE_BEING_COMPILED) '*' $$SIZE / $(NB_FILES_TO_COMPILE)`; \
	printf '$(ERASE)$(BLUE)[ $(PROGRESS_BAR)$(BOLD) ][ %d / %d ]\r[ $(ESC_STOP)' \
		$(NUM_FILE_BEING_COMPILED) $(NB_FILES_TO_COMPILE); \
	for N in `seq $$NB_BAR`; \
		do printf '$(BOLD)$(BLUE)$(FILLING_CHAR)$(ESC_STOP)'; \
	done
endef

vpath %.cpp ./ $(shell find $(SRCS_DIR) -type d)

all: display_variables $(NAME)

$(NAME): $(OBJS) | display_variables
	@$(PRINT_INTERLINE)
	@printf '$(YELLOW)$(BOLD)linking object files$(ESC_STOP)\n'
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@$(PRINT_INTERLINE)
	@printf '$(YELLOW)$(BOLD)%s$(ESC_STOP)$(YELLOW) built$(ESC_STOP)\n' '$@'
	@$(PRINT_INTERLINE)

$(OBJS): $(OBJS_DIR)/%.o: %.cpp $(OBJS_DIR)/debug$(DEBUG) $(OBJS_DIR)/sanitize$(SANITIZE) | $(OBJS_DIR)
# This retrieves the number of files to be compiled / updated
# The $(NO_RECURS) variable prevents an infinite loop
ifeq ($(NO_RECURS), 0)
	$(eval NB_FILES_TO_COMPILE ?= $(shell make NO_RECURS=1 --dry-run --debug=b | grep "does not\|Must remake" | grep -o "'.*\.o'" | sort | uniq | wc -l))
endif
	@if [ '$(COMPILING_PRINTED)' -eq '0' ]; then \
		if [ '$(VARIABLES_INTERLINE_PRINTED)' -eq '0' ]; then \
			$(PRINT_INTERLINE); \
		fi; \
		printf '$(BOLD)$(YELLOW)compiling sources$(ESC_STOP)\n'; \
	fi; $(eval COMPILING_PRINTED = 1)
	@printf '%s\n' $@
	@$(DRAW_PROGRESS_BAR)
	@$(CXX) $(CXXFLAGS) $(INCLUDES_DIR:%=-I %) -c $< -o $@
	@printf '$(ERASE)$(MOVE_UP)$(GREEN)%s$(ESC_STOP)\n' $@
	@if [ '$(NUM_FILE_BEING_COMPILED)' -eq '$(NB_FILES_TO_COMPILE)' ]; then \
		$(DRAW_PROGRESS_BAR); \
		printf '\n'; \
	fi; $(eval NUM_FILE_BEING_COMPILED = $(shell echo $$(($(NUM_FILE_BEING_COMPILED) + 1))))

$(OBJS_DIR):
	@$(MKDIR) $@

# This two files prevent make from recompiling if the actual and the previous
# compilation was made using the -g3 and / or the -fsanitize=address
$(OBJS_DIR)/debug$(DEBUG): | $(OBJS_DIR)
	@$(RM) $(OBJS_DIR)/debug0 $(OBJS_DIR)/debug1
	@touch $@

$(OBJS_DIR)/sanitize$(SANITIZE): | $(OBJS_DIR)
	@$(RM) $(OBJS_DIR)/sanitize0 $(OBJS_DIR)/sanitize1
	@touch $@

display_variables:
	@if [ '$(VARIABLES_PRINTED)' -eq '0' ]; then \
		$(PRINT_INTERLINE); \
		printf '$(YELLOW)executable name: $(BOLD)%s$(ESC_STOP)\n' '$(NAME)'; \
		printf '$(YELLOW)compiler:$(ESC_STOP) %s\n' '$(CXX)'; \
		printf '$(YELLOW)compilation flags:$(ESC_STOP) %s\n' '$(CXXFLAGS)'; \
		printf '$(YELLOW)libraries:$(ESC_STOP) %s\n' '$(LIBS)'; \
		printf '$(YELLOW)linking flags:$(ESC_STOP) %s\n' '$(LDFLAGS)'; \
		$(PRINT_INTERLINE); \
	fi; $(eval VARIABLES_PRINTED = 1) $(eval VARIABLES_INTERLINE_PRINTED = 1)

clean:
	@$(RM) -r $(OBJS_DIR)
	@printf '%s/ removed\n' '$(OBJS_DIR)'

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@printf '%s removed\n' '$(NAME)'

re: fclean all

-include $(DEPENDENCIES)
.PHONY: all clean fclean re display_variables
