# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 16:29:47 by tookuyam          #+#    #+#              #
#    Updated: 2024/10/10 16:29:47 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# settings
NAME     = a.out
SRC      = $(shell find . -name "*.cpp")
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
CACHEDIR = cache

# generate from above variable
OBJS    = $(addprefix $(CACHEDIR)/,$(SRC:.cpp=.o))
DEPS    = $(addprefix $(CACHEDIR)/,$(SRC:.cpp=.d))

# PHONY rules
all: $(NAME)

clean:
	rm -rf $(CACHEDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

sanitize: LDFLAGS += -fsanitize=leak
sanitize: CXXFLAGS += -fsanitize=leak
sanitize: debug

debug: LDFLAGS += -g -O0
debug: CXXFLAGS += -g -O0
debug: all

show:
	@echo variables value
	@printf "%s:\n\t%s\n" "NAME" "$(NAME)"
	@printf "%s:\n\t%s\n" "SRC" "$(SRC)"

-include $(DEPS)

# file rules
$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(CACHEDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -MF $(CACHEDIR)/$*.d -o $@ -c $<
