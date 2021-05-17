telco:	main.o Date.o Call.o Time.o Array.o Subscriber.o Telco.o Control.o View.o
	g++ -o telco main.o Date.o Call.o Time.o Array.o Subscriber.o Telco.o Control.o View.o

main.o:	main.cc Date.h Time.h Call.h Array.h Telco.h Subscriber.h Control.h View.o
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Time.o:	Time.cc Time.h
	g++ -c Time.cc
	
Call.o:	Call.cc Call.h Time.h Date.h
	g++ -c Call.cc
	
Array.o:	Array.cc Array.h Call.h
	g++ -c Array.cc		
	
Subscriber.o:	Subscriber.cc Subscriber.h 
	g++ -c Subscriber.cc	
	
Telco.o:	Telco.cc Telco.h
	g++ -c Telco.cc	
	
Control.o:	Control.cc Control.h View.h Telco.h	
	g++ -c Control.cc
	
View.o:	View.cc View.h
	g++ -c View.cc	
clean:
	rm -f *.o telco
