/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** bsq.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BSQ_H
#define BSQ_H

typedef struct s_bsq_map
{
	char *str;
	int *map;
	int start;
	int size;
	int x;
	int big;
} bsq_map;

int bsq_loop(bsq_map *map);

#endif
