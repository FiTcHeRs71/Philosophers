# Program name
NAME = philo

# Directories
SRCDIR = srcs
INCDIR = includes
OBJDIR = objs

# Source files
SRCS_MAIN = main.c

SRCS_UTILS = $(addprefix $(SRCDIR)/utils/, \
    utils.c clear.c)

SRCS_PARSE = $(addprefix $(SRCDIR)/parse/, \
    init_philo.c init_utils.c)

SRCS_SIMU = $(addprefix $(SRCDIR)/simulation/, \
    simulation.c simulation_utils.c)

# Combine all sources
SRCS = $(SRCS_MAIN) $(SRCS_UTILS) $(SRCS_PARSE) $(SRCS_SIMU)


OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -pthread
INCLUDES = -I$(INCDIR)

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Rules
all: $(NAME)
	@echo "$(GREEN)🎉 $(NAME) ready! 🎉$(RESET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling $(notdir $<)...$(RESET)\r"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)✓ Compiled $(notdir $<)   $(RESET)\n"

$(NAME): $(OBJS)
	@echo "$(YELLOW)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)✓ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)✓ $(NAME) removed$(RESET)"

re: fclean all

# Utilities
run: all
	@echo "$(GREEN)🚀 Running $(NAME)...$(RESET)"
	@./$(NAME)

valgrind: all
	@echo "$(YELLOW)🔍 Running valgrind (memory leak check)...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) 5 300 200 200 5

helgrind: all
	@echo "$(YELLOW)🧵 Running helgrind (thread error detector)...$(RESET)"
	@valgrind --tool=helgrind ./$(NAME)

norm:
	@echo "$(YELLOW)📋 Checking norminette...$(RESET)"
	@norminette $(SRCDIR) $(INCDIR) main.c 2>&1 | grep -v "OK!" || \
		echo "$(GREEN)✓ All files conform to norminette$(RESET)"

help:
	@echo "$(CYAN)════════════════