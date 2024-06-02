CXXFLAGS=-g -std=c++20 -save-temps
CFLAGS=-g 

all:: ;

help:
	@echo "To use this Makefile, try: "
	@echo "   make g0001 k0001 ..."
	@echo "   make clean g0001"
	@echo "   make clean"

.DEFAULT_GOAL = help

g%: .build/g%
	@echo "Run Getting Started Task g%: $@ ..."
	@.build/$@

k%: .build/k%
	@echo "Run Kernel Programming Task k%: $@ ..."
	@.build/$@

.build/g%: src/g%*.cpp
	@echo "Compiling C++ Sources..." $@ .. $*
	@g++ ${CXXFLAGS} -o $@ `find src/g$**`

.build/k%: src/k%*.c
	@echo "Compiling C Sources..." $@ .. $*
	@gcc ${CFLAGS} -o $@ `find src/k$**`

# To prevent execute: Removing intermediate files...
# .NOTINTERMEDIATE: 
.PRECIOUS: .build/g% .build/k%
	@echo "FEATURES: $(.FEATURES)"

.PHONY: g% k% 

clean:
	@echo "Clean ..." $^
	@fs=$$(ls .build/g* .build/k*); rm $$fs
# -@for it in .build/g* .build/k*; do rm "$$it"; done;