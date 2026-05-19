#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

typedef long long LL;

struct Segment {
    int start, stop, value;

    Segment(int a, int b, int v) { start = a; stop = b; value = v; }

    friend ostream& operator << (ostream& os, const Segment& seg) {
        os << "[" << seg.start << ", " << seg.stop << ", " << seg.value << "]";
        return os;
    }

    bool operator<(const Segment& rhs) const {
        return start < rhs.start;
    }
};

struct Point {
    int x, nvu=-1, pvu=-1, nvl=-1, pvl=-1;
    Point(int pos) { x = pos; }

    friend ostream& operator << (ostream& os, const Point& p) {
        os << p.x <<  " {nvu=" << p.nvu << ", pvu=" << p.pvu << ", nvl=" << p.nvl << ", pvl=" << p.pvl << "}";
        return os;
    }

    bool operator<(const Point& rhs) const {
        return x < rhs.x;
    }
};

LL ival_sum(const vector<Segment>& segments, int a, int b) {
    // Naive implementation since it's not running in any inner loop
    LL tot = 0;
    for(vector<Segment>::const_iterator si = segments.begin(); si != segments.end(); si++) {
        LL x = max(si->start, a), y = min(si->stop, b);
        if (x < y) {
            tot += (y-x) * si->value;
        }
    }
    return tot;
}

LL answer = 0;

void solve(int road_len, int race_len, const vector<Segment>& segments, bool flip, bool reverse) {
    set<Point> stpoints;
    vector<Segment> upper_segments, lower_segments;

    stpoints.insert(Point(0));
    stpoints.insert(Point(road_len));
    for(int i=0; i<segments.size(); i++) {
        int start = segments[i].start;
        int stop = segments[i].stop;
        if (flip) {
            swap(start, stop);
        }
        if (reverse) {
            start = road_len - start;
            stop = road_len - stop;
        }
        stpoints.insert(Point(start));
        stpoints.insert(Point(stop));
        if (start < stop) {
            upper_segments.push_back(Segment(start, stop, segments[i].value));
        } else {
            lower_segments.push_back(Segment(stop, start, segments[i].value));
        }
    }

    vector<Point> tpoints(stpoints.begin(), stpoints.end());

    sort(upper_segments.begin(), upper_segments.end());
    sort(lower_segments.begin(), lower_segments.end());

    // Precalculation step to avoid log(N) lookups in the inner loops
    for(vector<Point>::iterator pi = tpoints.begin(); pi != tpoints.end(); pi++) {
        int un = 0, ln = 0, up = 0, lp = 0;
        for(vector<Segment>::const_iterator si = upper_segments.begin(); si != upper_segments.end(); si++) {
            if (si->start <= pi->x-1 && si->stop >= pi->x) un = si->value;
            if (si->start <= pi->x && si->stop >= pi->x+1) up = si->value;
        }
        for(vector<Segment>::const_iterator si = lower_segments.begin(); si != lower_segments.end(); si++) {
            if (si->start <= pi->x-1 && si->stop >= pi->x) ln = si->value;
            if (si->start <= pi->x && si->stop >= pi->x+1) lp = si->value;
        }
        if (pi->x > 0) {
            pi->nvu = un;
            pi->nvl = ln;
        }
        if (pi->x < road_len) {
            pi->pvu = up;
            pi->pvl = lp;
        }
    }

    for(vector<Point>::iterator pa = tpoints.begin(); pa != tpoints.end(); pa++) {
        int a = pa->x;

        // Case 1
        // int c = max(a, (a + race_len + 1) / 2);  // Causes overflow!
        int c = max(a, (int) (((LL) a + race_len + 1) / 2));
        int d = 2*c-race_len-a;
        if (c <= road_len) {
            LL v = ival_sum(upper_segments, a, c) + ival_sum(lower_segments, d, c);

            answer = max(answer, v);

            if (c < road_len) {
                vector<Point>::iterator ci = upper_bound(tpoints.begin(), tpoints.end(), Point(c));
                vector<Point>::iterator di = upper_bound(tpoints.begin(), tpoints.end(), Point(d));

                while (d < c && c < road_len) {
                    while (ci->x <= c) ci++;
                    while (di->x <= d) di++;
                    vector<Point>::iterator di1 = di;
                    if (di->x <= d + 1) di1++;

                    LL steps = max(1, min(ci->x - c, min((di->x - d) / 2, min(c - d, road_len - c))));
                    v += steps * (ci->nvu + ci->nvl - di->nvl - di1->nvl);

                    c += steps;
                    d += steps * 2;
                    answer = max(answer, v);
                }
            }
        }

        for(vector<Point>::iterator pb = pa; pb != tpoints.end(); pb++) {
            int b = pb->x;

            // Case 2
            if ((b-a) * 2 <= race_len) {
                LL v = ival_sum(upper_segments, a, b) + ival_sum(lower_segments, a, b);
                int c = a + (race_len + 1) / 2;
                if (c <= road_len) {
                    int d = b + race_len % 2;
                    LL w = v + ival_sum(upper_segments, b, c) + ival_sum(lower_segments, d, c);
                    answer = max(answer, w);

                    if (c < road_len) {
                        vector<Point>::iterator ci = upper_bound(tpoints.begin(), tpoints.end(), Point(c));
                        vector<Point>::iterator di = upper_bound(tpoints.begin(), tpoints.end(), Point(d));

                        while (c < road_len && d < c) {
                            while (ci->x <= c) ci++;
                            while (di->x <= d) di++;
                            vector<Point>::iterator di1 = di;
                            if (di->x <= d + 1) di1++;

                            LL steps = max(1, min(ci->x - c, min((di->x - d) / 2, min(c - d, road_len - c))));
                            w += steps * (ci->nvu + ci->nvl - di->nvl - di1->nvl);

                            c += steps;
                            d += steps * 2;
                            answer = max(answer, w);
                        }
                    }
                }
            }

            // Case 3
            if (race_len - (b-a) >= 0) {
                int d = min(road_len, b + (race_len - (b-a)) / 2);
                int c = a + race_len - ((d - b) * 2 + (b-a));
                if (c >= a && c <= b) {
                    LL w = ival_sum(upper_segments, a, d) + ival_sum(lower_segments, a, c) + ival_sum(lower_segments, b, d);
                    answer = max(answer, w);

                    if (c < road_len) {
                        vector<Point>::iterator ci = upper_bound(tpoints.begin(), tpoints.end(), Point(c));
                        vector<Point>::iterator di = lower_bound(tpoints.begin(), tpoints.end(), Point(d));
                        di--;

                        while (c + 2 <= b && d > b) {
                            while (ci->x <= c) ci++;
                            while (di->x >= d) di--;
                            vector<Point>::iterator ci1 = ci;
                            if (ci->x <= c + 1) ci1++;

                            LL steps = max(1, min((ci->x - c) / 2, min(d - di->x, min(d - b, (b - c) / 2))));
                            w += steps * (ci->nvl + ci1->nvl - di->pvu - di->pvl);

                            c += steps * 2;
                            d -= steps;
                            answer = max(answer, w);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int road_len, race_len, n;
    cin >> road_len >> race_len >> n;
    vector<Segment> segments;
    for(int i=0; i<n; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        segments.push_back(Segment(a, b, v));
    }

    solve(road_len, race_len, segments, false, false);
    solve(road_len, race_len, segments, false, true);
    solve(road_len, race_len, segments, true, false);
    solve(road_len, race_len, segments, true, true);

    cout << answer << endl;

    return 0;
}
