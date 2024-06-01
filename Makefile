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

.build/%: src/g%
	@echo "Compiling sources..." $@ .. $*
	@g++ -save-temps -o $@ `find src/*$**`

src/%::;

# To prevent execute: Removing intermediate files...
# .NOTINTERMEDIATE: 
.PRECIOUS: .build/%
	@echo "FEATURES: $(.FEATURES)"

clean:
	@echo "Clean ..." $^
	-@if [[ -f .build/g* ]]; then rm .build/g*; fi;
	-@if [[ -f .build/k* ]]; then rm .build/k*; fi;