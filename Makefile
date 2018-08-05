all: compile

compile: build
	@make -C build

build:
	@mkdir -p build
	@(cd build && cmake ..)

clean:
	rm -r build

.PHONY: all compile clean
