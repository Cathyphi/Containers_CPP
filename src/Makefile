CC = g++ -Wall -Werror -Wextra -std=c++17

all: test

clean:
	rm -rf *.o *.a *.out *.info report test.dSYM *.gcno *.gcda test

test: clean
	$(CC) test_containers.cc -lgtest -o test -lstdc++
	./test

gcov_report: clean
	$(CC) --coverage test_containers.cc -o test -lgtest
	./test
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open report/index.html

style:
	clang-format -style=google -n *.cc *.h

leaks: test
	leaks -atExit -- ./test
