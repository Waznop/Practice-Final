HEADERS       := poke_quiz.h lib/poke_quiz_correct.h
IMPLEMS       := poke_quiz.cpp
OBJECT_IMPLEM := lib/poke_quiz_correct.cpp
OBJECT        := lib/poke_quiz_correct.o
OUT           := poke_quiz
TEST          := poke_quiz_test.cpp
TEST_LIB      := lib/test_utils.h
TEST_OUT      := poke_quiz_test
DRIVER        := main.cpp

FILES         := $(IMPLEMS) $(HEADERS) $(TEST) $(TEST_LIB) $(DRIVER)
OUTS          := $(OUT) $(TEST_OUT)
GTEST         := googletest
FLAGS         := -Wall -Wno-unused-function
TEST_FLAGS    := -Wall -Wno-unused-function -Wno-sign-compare -Wno-unused-variable -pthread 

.PHONY: format build test all clean object

all: format build test

format:
	@echo "\n========================\nFormatting files\n========================\n"
	@clang-format $(FILES) -i -style=google -verbose
	@echo "\n========================\nFormatting complete\n========================\n"

build: $(DRIVER) $(IMPLEMS) $(HEADERS)
	@echo "\n========================\nCompiling program\n========================\n"
	@g++ -std=c++17 $(DRIVER) $(IMPLEMS) $(OBJECT) $(FLAGS) -o $(OUT)
	@echo "========================\nCompilation complete\nRun your code with ./$(OUT)\n========================\n"

test: $(TEST) $(IMPLEMS) $(HEADERS)
	@echo "\n========================\nRunning tests\n========================\n"
	@g++ -std=c++17 $(TEST) $(IMPLEMS) $(OBJECT) $(GTEST)/libgtest.a $(GTEST)/libgtest_main.a -isystem $(GTEST)/include $(TEST_FLAGS) -o $(TEST_OUT)
	@./$(TEST_OUT)
	@echo "\n========================\nTests complete\n========================\n"

object:
	@echo "\n========================\nBuilding object\nYou shouldn't need to do this\n========================\n"
	@g++ -std=c++17 $(OBJECT_IMPLEM) $(FLAGS) -c -o $(OBJECT)
	@echo "\n========================\nBuilding complete\n========================\n"

clean:
	@rm -f $(OUTS)