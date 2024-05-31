# To use this Makefile, try: make g0001
%: .build/%.exe
	@echo "Task %: $@ ..."
	.build/$*

# To prevent execute: Removing intermediate files...
# .NOTINTERMEDIATE: 
.PRECIOUS: .build/%.exe
	@echo "FEATURES: $(.FEATURES)"

.build/%.exe:
	@echo "Compiling sources..." $@ .. $*
	@g++ -save-temps -o $@ `find src/$*.*`

clean:
	@echo "Clean ..." $^
	rm .build/g*