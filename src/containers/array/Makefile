.PHONY : all clean test gcov_report rebuild

GCC=-Wall -Werror -Wextra -lstdc++ -std=c++17 #-fsanitize=address

CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
LIBS=-lgtest -lgcov

all: clean library test

test: 
	@gcc $(CFLAGS) $(LIBS) $(CPPFLAGS) --coverage utests.cc -o test
	@./test

gcov_report: test
	@lcov --ignore-errors mismatch -t "./gcov" -o report.info --no-external -c -d .
	@genhtml --ignore-errors mismatch -o report report.info
	@open ./report/index.html

clean:
	rm -rf  *.gcno  *.inf *.info gcov *.gcda *.a *.out ./report  *.o *.dSYM

check:
	clang-format -style=Google -i *.cc *.tpp *.h

