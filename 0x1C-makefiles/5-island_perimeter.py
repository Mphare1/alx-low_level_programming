#!/usr/bin/python3

"""Defines island perimeter. """


def island_perimeter(grid):
    """Return the perimiter. """
    wdth = len(grid[0])
    hght = len(grid)
    edgs = 0
    s = 0

    for x in range(hght):
        for y in range(wdth):
            if grid[x][y] == 1:
                s += 1
                if (y > 0 and grid[x][y - 1] == 1):
                    edgs += 1
                if (x > 0 and grid[x - 1][y] == 1):
                    edgs += 1
    return s * 4 - edgs * 2
