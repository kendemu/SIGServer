
DEPFILE = Makefile.dep

INCLUDE_LOCAL = -I../

.SUFFIXES : .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE_LOCAL) $(INCLUDE) $(DEFINE) -c -o $@ $<

SRCS = decode.cpp Move.cpp JointControl.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)

clean:
	$(RM) *.o *~ 

depend:
	gcc -Wall -MM $(INCLUDE_LOCAL) $(INCLUDE) $(DEFINE) $(SRCS) > $(DEPFILE)

include $(DEPFILE)