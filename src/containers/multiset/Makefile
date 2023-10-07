TESTFLAGS = -lgtest -lpthread
GCCFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
GCOVFLAGS = -fprofile-arcs -ftest-coverage


test: clean
	@gcc -o test multiset_utest.cc $(TESTFLAGS) $(GCCFLAGS)
	./test

leaks: test
	leaks -atExit -- ./test
clean:
	rm -rf test
	rm -rf *.o *.a *.out *.gcno *.gcda *.info *.gch test report gcov_report


test_for_gcov: clean
	@gcc -o test multiset_utest.cc $(TESTFLAGS) $(GCCFLAGS) $(GCOVFLAGS)
	./test

gcov_report: test_for_gcov
	@lcov -t "./gcov" -o report.info --no-external -c -d . --ignore-errors mismatch --rc geninfo_unexecuted_blocks=1
	@genhtml -o report report.info
	@open ./report/index.html



clang_format:
	clang-format --style=google  -i *.cc *.tpp *.h