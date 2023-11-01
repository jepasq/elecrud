# elecrud 

A C++/electron based multi-user CRUD operator generator.
*electrud* is licensed under *GNU GPL v3*.

## libfile

This library contains the *project files* related work and all that can be
shared with other clients. The main entry to this part of the project can
be the ProjectFile class.

## std::string vs FXString

The *fox toolkit* implements its own string object : FXString. While it is
possible to cast a *std::string* to FXString, you have to do it manually.

I will use both type in different subprojects. When the project is Fox-based,
for example the graphical editor, it uses the FXString type.

In the general-purpose library called `libfile`, I will use std::string.

# Tools

This repository contains multiple binaries :

	src/editor   A graphical project file editor powered by fox toolkit.
	src/eudcat   A CLI utility to print .eud file informations.
