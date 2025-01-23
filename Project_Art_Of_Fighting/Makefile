.PHONY: build
build:
	(cmake -Bbuild -DCMAKE_BUILD_TYPE=Release && cd build && make && mv aof ../Game)
	(cd Game && ./aof)

clean:
	rm -rf build