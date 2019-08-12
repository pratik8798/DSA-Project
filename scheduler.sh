g++ -std=c++11 -I. -c d_queue.cpp
g++ -std=c++11 -I. -c p_queue.cpp
g++ -std=c++11 -I. -c scheduler.cpp
g++ -std=c++11 scheduler.o d_queue.o p_queue.o -o scheduler
