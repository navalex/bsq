/*
** EPITECH PROJECT, 2018
** loop.c
** File description:
** loop.c
*/

#include "bsq.h"

static int bsq_cmp(bsq_map *map, int pos, int temp)
{
	int tpos[] = {pos - 1, pos - map->x - 1, pos - map->x - 2};
	int val[] = {map->map[tpos[0]], map->map[tpos[1]], map->map[tpos[2]]};

	if (val[0] >= 0 && val[1] >= 0 && val[2] >= 0) {
		if (val[0] <= val[1] && val[0] <= val[2])
			return (val[0] + 1);
		else if (val[1] <= val[0] && val[1] <= val[2])
			return (val[1] + 1);
		else
			return (val[2] + 1);
	}
	else {
		return (temp);
	}
}

static int *bsq_jt(void) {
	int *jt = malloc(sizeof(int) * 128);

	jt[10] = -1;
	jt[46] = 1;
	jt[111] = 0;
	return (jt);
}

int bsq_loop(bsq_map *map)
{
	int *jt = bsq_jt();
	int i[] = {map->start, -1, 0};

	map->big = 0;
	while (map->str[++i[0]]) {
		map->map[++i[1]] = jt[map->str[i[0]]];
		if (map->map[i[1]] == 84)
			return (84);
		else if (map->map[i[1]] < 0 && !i[2]) {
			map->x = i[1];
			i[2]= 1;
		}
		if (i[2] && map->map[i[1]] > 0 && map->map[i[1] - 1] >= 0)
			map->map[i[1]] = bsq_cmp(map, i[1], map->map[i[1]]);
		if (map->map[i[1]] > map->map[map->big])
			map->big = i[1];

	}
	map->map[i[1]] = -2;
	return (0);
}
