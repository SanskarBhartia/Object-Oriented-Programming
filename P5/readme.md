## README

AUTHORS:

Sanskar Bhartia: 919252622
Austin Kuo: 918323992
Stavan Jani: 919640810


## Introduction

This HW5 is meant to implement Object Mobility into Little Red Riding Hood story. The code is based of HW2 and HW3 where
dump2JSON was used to output the results.

## Compiling

The application should compile pretty much anything.
It requires almost no memory at all and can be used on older operating systems as well!


Currently successfully tested are:

- Windows 10
- macOS Ventura Version 13.0 (22A380)

First, make the file. After, you would open 3 separate terminals and run
./hw5GrandmaHome
./hw5Forest
./hw5Home
In that exact order


## How it works

First code will host servers for each of the 3 areas (GrandmaHome, Forest, and Home).
Then it will implement Person.cpp and Thing.cpp to utilize their dump2JSON and JSON2File functions to create class and objects from the Little Red story. hw5Server will then take these class and objects and send them through the hosted servers.

## Result

There should display the class Person and Thing with their objects being sent through each server. It should also notify when it has been sent and received.

## References:
https://github.com/sfelixwu/1114_2022/blob/main/test_mi_f2022.cpp
https://www.youtube.com/watch?v=TrKzLvdbao4
