import sys

try:
    input = raw_input
except NameError:
    pass


def ival_sum(segments, a, b):
    # Naive implementation since it's not running in any inner loop
    tot = 0
    lo = 0
    hi = len(segments)
    while lo < hi:
        x = (lo+hi) // 2
        if segments[x][1] <= a:
            lo = x + 1
        else:
            hi = x
    while lo < len(segments):
        (start, stop, value) = segments[lo]
        if start >= b:
            break
        x = max(start, a)
        y = min(stop, b)
        if x < y:
            tot += (y-x) * value
        lo += 1
    return tot

best = 0

def solve(road_len, race_len, segments):
    global best
    tpoints = set([0, road_len])

    upper_segments = []
    lower_segments = []

    for (start, stop, value) in segments:
        tpoints.add(start)
        tpoints.add(stop)
        if start < stop:
            upper_segments.append((start, stop, value))
        else:
            lower_segments.append((stop, start, value))

    tpoints = list(sorted(tpoints))

    upper_segments.sort()
    lower_segments.sort()

    upper_points_next = []
    lower_points_next = []
    upper_points_prev = []
    lower_points_prev = []
    for i in tpoints:
        un = ln = up = lp = 0
        for (start, stop, value) in upper_segments:
            if start <= i-1 and stop >= i:
                un = value
            if start <= i and stop >= i+1:
                up = value
        for (start, stop, value) in lower_segments:
            if start <= i-1 and stop >= i:
                ln = value
            if start <= i and stop >= i+1:
                lp = value
        if i == 0:
            un = ln = -1
        elif i == road_len:
            up = lp = -1

        upper_points_next.append(un)
        lower_points_next.append(ln)

        upper_points_prev.append(up)
        lower_points_prev.append(lp)

    def lower_bound(x):
        lo = 0
        hi = len(tpoints)
        while lo < hi:
            t = (lo+hi) // 2
            if tpoints[t] < x:
                lo = t + 1
            else:
                hi = t
        return lo

    def upper_bound(x):
        lo = 0
        hi = len(tpoints)
        while lo < hi:
            t = (lo+hi) // 2
            if tpoints[t] <= x:
                lo = t + 1
            else:
                hi = t
        return lo

    for a in tpoints:
        # Case 1: Only one switch. A is an endpoint.
        #
        # ...A######C...
        # .......D##C...
        #
        # Slide D to the right twice as fast as C
        # D may be less or greater than A

        c = max(a, (a + race_len + 1) // 2)
        d = 2*c-race_len-a
        if c <= road_len:
            assert 0 <= a <= c <= road_len
            assert 0 <= d <= c <= road_len

            v = ival_sum(upper_segments, a, c) + ival_sum(lower_segments, d, c)
            best = max(best, v)

            if c < road_len:
                ci = upper_bound(c)
                di = upper_bound(d)

                while d < c and c < road_len:

                    while tpoints[ci] <= c:
                        ci += 1
                    while tpoints[di] <= d:
                        di += 1

                    di1 = di + (tpoints[di] <= d + 1)

                    steps = max(1, min(tpoints[ci] - c, (tpoints[di] - d) // 2, c - d, road_len - c))

                    v += steps * (upper_points_next[ci] + lower_points_next[ci] - lower_points_next[di] - lower_points_next[di1])

                    if v > best:
                        best = v
                    c += steps
                    d += steps * 2

        if a + race_len // 2 >= road_len:
            continue

        for b in tpoints:
            if a >= b:
                continue

            # Case 2: Two switches. A and B are endpoints.
            #
            # ...A##B####D##C...
            # ...A##B....D##C...
            #
            # Slide D to the right twice as fast as C

            if (b-a) * 2 <= race_len:
                v = ival_sum(upper_segments, a, b) + ival_sum(lower_segments, a, b)
                c = a + (race_len + 1) // 2
                if c <= road_len:
                    d = b + race_len % 2
                    assert 0 <= a <= b <= d <= c <= road_len
                    w = v + ival_sum(upper_segments, b, c) + ival_sum(lower_segments, d, c)
                    best = max(best, w)

                    q = b + race_len - (b-a)*2
                    if ival_sum(upper_segments, a, q) + ival_sum(lower_segments, a, q) <= best:
                        c = road_len

                    if c < road_len:
                        ci = upper_bound(c)
                        di = upper_bound(d)

                        while c < road_len and d < c:
                            while tpoints[ci] <= c:
                                ci += 1
                            while tpoints[di] <= d:
                                di += 1

                            di1 = di + (tpoints[di] <= d + 1)

                            steps = max(1, min(tpoints[ci] - c, (tpoints[di] - d) // 2, c - d, road_len - c))

                            w += steps * (upper_points_next[ci] + lower_points_next[ci] - lower_points_next[di] - lower_points_next[di1])
                            if w > best:
                                best = w
                            c += steps
                            d += steps * 2

            # Case 3: Two switches. A and B are endpoints.
            #
            # ...A##C#####B##D....
            # ...A##C.....B##D....
            #
            # Slide C to the right twice as fast as D goes to the left

            if race_len - (b-a) >= 0:
                d = min(road_len, b + (race_len - (b-a)) // 2)
                c = a + race_len - ((d - b) * 2 + (b-a))
                if c >= a and c <= b:
                    # print(0, a, c, b, d, road_len)
                    assert 0 <= a <= c <= b <= d <= road_len
                    w = ival_sum(upper_segments, a, d) + ival_sum(lower_segments, a, c) + ival_sum(lower_segments, b, d)
                    best = max(best, w)

                    if ival_sum(upper_segments, a, d) + ival_sum(lower_segments, a, d) <= best:
                        c = road_len

                    if c < road_len:
                        ci = upper_bound(c)
                        di = lower_bound(d) - 1

                        while c + 2 <= b and d > b:
                            while tpoints[ci] <= c:
                                ci += 1
                            while tpoints[di] >= d:
                                di -= 1

                            ci1 = ci + (tpoints[ci] <= c + 1)

                            steps = max(1, min((tpoints[ci] - c) // 2, d - tpoints[di], d - b, (b - c) // 2))
                            w += steps * (lower_points_next[ci] + lower_points_next[ci1] - upper_points_prev[di] - lower_points_prev[di])
                            if w > best:
                                best = w
                            c += steps * 2
                            d -= steps

    return best

road_len, race_len, n = map(int, input().split(' '))
segments = [tuple(map(int, input().split(' '))) for i in range(n)]
flip_segments = [(stop, start, v) for (start, stop, v) in segments]
reverse_segments = [(road_len-start, road_len-stop, v) for (start, stop, v) in segments]
reverse_flip_segments = [(road_len-stop, road_len-start, v) for (start, stop, v) in segments]

solve(road_len, race_len, segments)
solve(road_len, race_len, flip_segments)
solve(road_len, race_len, reverse_segments)
solve(road_len, race_len, reverse_flip_segments)

print(best)
