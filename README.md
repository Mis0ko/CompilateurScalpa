# Scalpa Compilator

By [Michael Hofmann](https://github.com/Mis0ko), [Celine LY](https://github.com/LyCeline06), [Yassine El Allioui](https://github.com/boboyoyo7)<br/>
Last update : 01/01/2021.

## Overview 

This project aim to simulate a Scalpa Compilateur (Pascal-like Language)

## How to Launch it

A lot of files with different examples are in file_test and tests directories.

To launch the project with one of them, just use :<br/>
`make` <br/>
`./scalpa -t -o outputFile.asm < inputScalpa.txt`

**outputFile** is the file where the asm code will be written<br/>
**inputScalpa.txt** is the file to compile, written in Scalpa

## Launch Test Script

The Project contains a script that will execute a bunch of compilation tests (unit test), such as condition, loop, function, ...

`sh launch_tester.sh`
