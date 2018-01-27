/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "bsq.h"

static int bsq_map_init(char *file, bsq_map *map)
{
	int i = -1;
	int fd = open(file, O_RDONLY);
	struct stat stats;

	if (fd == -1)
		return (84);
	stat(file, &stats);
	map->size = stats.st_size;
	map->str = malloc(sizeof(char) * map->size);
	read(fd, map->str, map->size);
	while(map->str[++i]) {
		if (map->str[i] == '\n') {
			map->str[i] = '\0';
			break;
		}
		map->str[i] = '\0';
	}
	map->start = i;
	map->map = malloc(sizeof(int) * (map->size - map->start + 1));
	return (1);
}

void bsq_squarify(bsq_map *map)
{
	int pos = map->big + map->start + 1;
	int i = map->map[map->big] + 1;
	int u = map->map[map->big] + 1;

	while (--i > 0) {
		while (--u > 0) {
			map->str[pos] = 'x';
			--pos;
		}
		u = map->map[map->big] + 1;
		pos -= (map->x - u + 1);
	}
}

int main(int ac, char **av)
{
	bsq_map map;

	if (ac != 2)
		return (84);
	if (bsq_map_init(av[1], &map) == 84)
		return (84);
	if (bsq_loop(&map) == 84)
		return (84);
	bsq_squarify(&map);
	write (1, map.str, map.size - map.start);
	return (0);
}
