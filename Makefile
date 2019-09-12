CC=g++
CFLAGS= -std=c++17 -Werror

PART1 = part_1
PART2 = part_2

all: $(PART1) $(PART2)

clean: 
	rm -f $(PART1) $(PART2)

run1: $(PART1)
	./$(PART1) part_1_example_input.txt

run2: $(PART2)
	./$(PART2) part_2_example_input.txt part_2_output.txt

$(PART1): $(PART1).cpp
	$(CC) $(CFLAGS) -o $(PART1) $(PART1).cpp

$(PART2): $(PART2).cpp
	$(CC) $(CFLAGS) -o $(PART2) $(PART2).cpp
