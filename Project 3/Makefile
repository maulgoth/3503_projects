build:
	g++ -c src/*.cpp -Wall -Wextra
	mv *.o src/
	g++ src/*.o -o sfml-app.out -lsfml-graphics -lsfml-window -lsfml-system
link:
	g++ src/*.o -o sfml-app.out -lsfml-graphics -lsfml-window -lsfml-system
screen:
	export DISPLAY=:0
run:
	./sfml-app.out
clean:
	rm src/*.o
