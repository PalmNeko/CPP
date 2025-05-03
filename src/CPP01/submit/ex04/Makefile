# settings
NAME     = replace.out
TEST	 = test.out
SRC      = \
	./modules/replace.cpp \

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -I includes -MMD -MP -std=c++98
CACHEDIR = cache

# generate from above variable
OBJS    = $(addprefix $(CACHEDIR)/,$(SRC:.cpp=.o))
DEPS    = $(addprefix $(CACHEDIR)/,$(SRC:.cpp=.d))

# PHONY rules
all: $(NAME) $(TEST)

clean:
	rm -rf $(CACHEDIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TEST)

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
$(NAME): $(CACHEDIR)/main.o $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(TEST): $(CACHEDIR)/test.o $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(CACHEDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MF $(CACHEDIR)/$*.d -o $@ -c $<
