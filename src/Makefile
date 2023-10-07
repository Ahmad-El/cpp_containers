
.PHONY : all clean test gcov_report rebuild

CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
LIBS=-lgtest -lgcov

all: test gcov_report

test:
	cd ./containers/vector/ && make test && make gcov_report
	cd ./containers/array/ && make test && make gcov_report
	cd ./containers/map/ && make test && make gcov_report
	cd ./containers/set/ && make test && make gcov_report
	cd ./containers/multiset/ && make test && make gcov_report
	make test_sql && make gcov_report

test_sql: 
	@gcc $(CFLAGS) $(LIBS) $(CPPFLAGS) --coverage unit_tests.cc -o test
	@./test


gcov_report: test_sql
	@lcov --ignore-errors mismatch -t "./gcov" -o report.info --no-external -c -d .
	@genhtml --ignore-errors mismatch -o report report.info
	@open ./report/index.html

clean:
	cd ./containers/vector/ && make clean
	cd ./containers/array/ && make clean
	cd ./containers/map/ && make clean
	cd ./containers/set/ && make clean
	cd ./containers/multiset/ && make clean
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf report
	@rm -rf gcov_report
	@rm -rf valgrind_test
	@rm -rf *.dSYM

rebuild:
	@make clean
	@make all

leaks:
	leaks -atExit -- ./test

style:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -i

