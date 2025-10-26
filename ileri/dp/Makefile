TARGETS = dag

CXX = c++
CXXFLAGS = -std=c++23

.PHONY: all
all: $(TARGETS)

$(TARGETS): %: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./dag

.PHONY: clean
clean:
	rm -f $(TARGETS) *.o
