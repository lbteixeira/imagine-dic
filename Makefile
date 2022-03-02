.PHONY: debug
debug:
		cmake -D CMAKE_CXX_COMPILER=g++ -D CMAKE_EXPORT_COMPILE_COMMANDS=1 -D CMAKE_BUILD_TYPE="Debug" -S . -B build/debug/
		cp build/debug/compile_commands.json .
		cmake --build ./build/debug

.PHONY: release
release:
		cmake -D CMAKE_CXX_COMPILER=g++ -D CMAKE_EXPORT_COMPILE_COMMANDS=1 -D CMAKE_BUILD_TYPE="Release" -S . -B build/release/
		cp build/release/compile_commands.json .
		cmake --build ./build/release

.PHONY: run-debug
run-debug: debug
		./build/debug/src/imagine/imagine

.PHONY: run-release
run-release: release
		./build/release/src/imagine/imagine

.PHONY: test-debug
test-debug: debug
		cmake -D CMAKE_CXX_COMPILER=g++ -D PROJECT_BUILD_TESTS="ON" -D CMAKE_BUILD_TYPE="Debug" -S . -B tests/build/
		cmake --build ./tests/build
		./tests/build/tests/imagine-tests -s -r compact

.PHONY: test-release
test-release: release
		cmake -D PROJECT_BUILD_TESTS="ON" -D CMAKE_BUILD_TYPE="Release" -S . -B tests/build/
		cmake --build ./tests/build
		./tests/build/tests/imagine-tests -s -r compact

.PHONY: clean-debug
clean-debug:
		rm -rf build/debug/*

.PHONY: clean-release
clean-release:
		rm -rf build/release/*

.PHONY: clean-test
clean-test:
		rm -rf tests/build/*

.PHONY: clean-examples
clean-examples:
		rm -rf examples/build/*

.PHONY: clean-all
clean-all:
		rm -rf build/debug/*
		rm -rf build/release/*
		rm -rf tests/build/*
		rm -rf examples/build/*

