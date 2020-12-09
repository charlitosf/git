evacuationOfHoth: src/makefile
	$(MAKE) -C src

test: evacuationOfHoth test/makefile
	$(MAKE) -C test test
	test/test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean