CXXFLAGS := -g -Wall -Wextra

brute_force:

dp:

test_brute_force: brute_force
	for i in `seq 10`; do ./test.sh brute_force 10 $$i; done


test_dp: dp
	for i in `seq 10`; do ./test.sh dp 17 $$i; done

test_mst: mst
	for i in `seq 10`; do ./test.sh mst 17 $$i; done

clean:
	$(RM) brute_force dp

.PHONY: test clean
