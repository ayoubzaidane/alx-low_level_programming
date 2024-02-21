#!/usr/bin/python3
"""
Module Island Perimeter
"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    perimeter = 0

    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                perimeter += 4  # Each land cell contributes 4 to the perimeter

                # Check neighboring cells
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 1  # Subtract 1 for each shared edge (up)
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 1  # Subtract 1 for each shared edge (left)

                # Check down neighbor
                if row < len(grid) - 1 and grid[row + 1][col] == 1:
                    perimeter -= 1  # Subtract 1 for each shared edge (down)

                # Check right neighbor
                if col < len(grid[0]) - 1 and grid[row][col + 1] == 1:
                    perimeter -= 1  # Subtract 1 for each shared edge (right)

    return perimeter
