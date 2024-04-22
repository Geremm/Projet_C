cmake_minimum_required(VERSION 3.27)
project(Projet_C C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet_C main.c
        column.c
        column.h
        list.c
        list.h
        sort.c
        sort.h
        cdataframe.c
        cdataframe.h)
