CXXFLAGS += -I. $(shell root-config --cflags) -g
LDFLAGS += $(shell root-config --libs) -g

PROGRAMS = CalcSCE

all:		clean $(PROGRAMS)

$(PROGRAMS):
	@echo '<<compiling' $@'>>'
	@$(CXX) $@.cpp -o $@ -I /usr/include/python2.7 $(CXXFLAGS) $(LDFLAGS)
	@rm -rf *.dSYM
clean:	
	rm -f $(PROGRAMS)
