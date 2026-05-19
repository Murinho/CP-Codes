#!/usr/bin/env python3

"""Algorithm:

Subdivide the 30x30 grid into unit squares (from now on blocks).

Put all blocks in a heap.

Let A = 0 , the answer

While the heap is non-empty, pop a block B off the heap.

If B is <TINY, ignore it.
If B is not overlapping any circle, ignore it.
If B is fully contained in any circle, add its area to A, drop B.
Otherwise, subdivide it into four squares and push them to the heap.

Output A
"""

import sys
import math
import heapq
from collections import namedtuple as T

TINY = 1e-4

C = T("C", "x y r")
P = T("P", "x y")
Block = T("B", "nw ne sw se")


def B(nw, ne, sw, se):
    x1, y1 = nw
    x2, y2 = se
    assert x1 < x2, f"{x1} < {x2}"
    assert y1 < y2
    assert ne == P(x2, y1)
    assert sw == P(x1, y2)
    return Block(nw, ne, sw, se)


def block_area(block):
    return (block.ne.x - block.nw.x) * (block.se.y - block.ne.y)


def point_in_circle(p, c):
    return math.hypot(p.x - c.x, p.y - c.y) <= c.r


def block_inside(block, circle):
    return (
        point_in_circle(block.nw, circle)
        + point_in_circle(block.ne, circle)
        + point_in_circle(block.sw, circle)
        + point_in_circle(block.se, circle)
    )


def subdivide(block):
    nw = block.nw
    ne = block.ne
    sw = block.sw
    se = block.se
    x1, y1 = nw
    x2, y2 = se
    mx = (x2 + x1) / 2
    my = (y2 + y1) / 2

    NW = B(nw, P(mx, y1), P(x1, my), P(mx, my))
    NE = B(P(mx, y1), ne, P(mx, my), P(x2, my))

    SW = B(P(x1, my), P(mx, my), sw, P(mx, y2))
    SE = B(P(mx, my), P(x2, my), P(mx, y2), se)
    for b in [NW, NE, SW, SE]:
        assert block_area(b) == 0.25 * block_area(
            block
        ), f"{block_area(b)} == 0.25 * {block_area(block)}"
    return [NW, NE, SW, SE]


def block_in_single_circle(block, circles):
    allzero = True
    for c in circles:
        count = block_inside(block, c)
        if count == 4:
            return 4
        if count > 0:
            allzero = False
    if allzero:
        return 0
    return 1


n = int(sys.stdin.readline())
circles = []
for _ in range(n):
    circles.append(C(*map(int, sys.stdin.readline().split())))


blocks = []
for i in range(-10, 20):
    for j in range(-10, 20):
        nw = P(i, j)
        ne = P(i + 1, j)
        sw = P(i, j + 1)
        se = P(i + 1, j + 1)
        blocks.append(B(nw, ne, sw, se))
heapq.heapify(blocks)
area = 0
while blocks:
    block = heapq.heappop(blocks)

    containment = block_in_single_circle(block, circles)
    if containment == 4:
        area += block_area(block)
    elif containment == 0:
        continue
    else:
        for nb in subdivide(block):
            if block_area(nb) > TINY:
                heapq.heappush(blocks, nb)


print(round(area, 4))
