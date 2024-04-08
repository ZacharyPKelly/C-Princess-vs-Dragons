/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   headerFile.h
 * Author: zacha
 *
 * Created on September 29, 2022, 1:56 PM
 */

#ifndef HEADERFILE_H
#define HEADERFILE_H

void gameMessage(void);

int intConverter(char gridSize[]);

int sizeOfGrid(void);

int outsideEdge(int size, int col, int row);

char firstLetter(char string[]);

void playGame(int size);

void program(void);

#endif /* HEADERFILE_H */

