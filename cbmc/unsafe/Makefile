default: tests.log

FLAGS = --no-sat-preprocessor --verbosity 10
TIMEOUT=600
TOOL=cbmc
PROGRESSLOG=${PWD}/progress.log-${TOOL}

test:
	@../../test.pl -c "runsolver -C $(TIMEOUT) -d 1 -M 32768 /users/rajdeep/cbmc-git/cbmc/src/cbmc/cbmc	$(FLAGS) > ${PROGRESSLOG}" 

tests.log: ../test.pl
	@../../test.pl -c "/users/rajdeep/cbmc-git/cbmc/src/cbmc/cbmc $(FLAGS)"

show:
	@for dir in *; do \
		if [ -d "$$dir" ]; then \
			vim -o "$$dir/*.c" "$$dir/*.out"; \
		fi; \
	done;

clean:
	@rm -f *.log
	@for dir in *; do rm -f $$dir/*.out; rm -f $$dir/*.txt; done;
