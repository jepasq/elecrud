# elecrud

A C++/electron based multi-user CRUD operator program generator.

## Building

On debian-based distributions :

	sudo apt install libfox-1.6-dev libboost-dev libboost-test-dev libboost-serialization-dev

or on arch :

	sudo pacman -S cmake pkg-config fox boost 

	mkdir build
	cmake ..
	make
	./electrud

## src/app

This directory contains the skeleton of the to-be-generated application.
