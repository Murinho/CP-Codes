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

struct Solution {
    LL value;
    int left, right;
    int gap_left, gap_right, gap_side;  // side = 0 => gap is on upper side
    int case_bit_mask;
    int flip_rev_mask;
    int num_segments; // set by evaluate

    Solution(int l, int r, int gl, int gr, int gs) {
        left = l;
        right = r;
        gap_left = gl;
        gap_right = gr;
        gap_side = gs;
    }

    Solution(LL v, int l, int r, int gl, int gr, int gs, int mask, bool flip, bool reverse, int road_len) {
        assert(l < r && gl <= gr && gl >= l && gr <= r);
        int flip_rev = (flip ? 1 : 0) + (reverse ? 2 : 0);
        value = v;
        left = l; right = r;
        if (gl == gr) {
            gap_side = -1;
            gap_left = gap_right = 0;
        } else {
            gap_left = gl;
            gap_right = gr;
            gap_side = (flip ^ reverse) ? (1-gs) : gs;
        }
        if (reverse) {
            left = road_len - left;
            right = road_len - right;
            swap(left, right);
            if (gap_side != -1) {
                gap_left = road_len - gap_left;
                gap_right = road_len - gap_right;
                swap(gap_left, gap_right);
            }
        }
        case_bit_mask = mask;
        flip_rev_mask = 1 << flip_rev;
    }

    bool same(Solution &rhs) {
        return left == rhs.left && right == rhs.right && gap_left == rhs.gap_left && gap_right == rhs.gap_right && gap_side == rhs.gap_side;
    }

    friend ostream& operator << (ostream& os, const Solution& p) {
        if (p.gap_side == -1) {
            os << p.value <<  " {left=" << p.left << ", right=" << p.right << ", case=" << p.case_bit_mask << "}";
        } else {
            os << p.value <<  " {left=" << p.left << ", right=" << p.right << ", gap_left=" << p.gap_left << ", gap_right=" << p.gap_right << ", gap_side=" << p.gap_side << ", case=" << p.case_bit_mask << "}";
        }
        return os;
    }

    LL evaluate(const vector<Segment>& segments) {
        LL sum = 0, gapsum = 0;
        int seg_cnt = 0;
        for(vector<Segment>::const_iterator si = segments.begin(); si != segments.end(); si++) {
            if (si->start < si->stop) {
                LL x = max(si->start, left), y = min(si->stop, right);
                LL overlap = 0, gap_overlap = 0;
                if (x < y) {
                    overlap = (y-x) * si->value;
                }
                if (gap_side == 0) {
                    LL x = max(si->start, gap_left), y = min(si->stop, gap_right);
                    if (x < y) {
                        gap_overlap = (y-x) * si->value;
                    }
                }
                sum += overlap;
                gapsum += gap_overlap;
                if (overlap > gap_overlap) seg_cnt++;
            } else {
                LL x = max(si->stop, left), y = min(si->start, right);
                LL overlap = 0, gap_overlap = 0;
                if (x < y) {
                    overlap = (y-x) * si->value;
                }
                if (gap_side == 1) {
                    LL x = max(si->stop, gap_left), y = min(si->start, gap_right);
                    if (x < y) {
                        gap_overlap = (y-x) * si->value;
                    }
                }
                sum += overlap;
                gapsum += gap_overlap;
                if (overlap > gap_overlap) seg_cnt++;
            }
        }

        num_segments = seg_cnt;
        return sum - gapsum;
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
vector<Solution> solutions;

void update_solutions(const vector<Segment>& segments, Solution new_solution) {
    LL v = new_solution.evaluate(segments);
    assert(v == new_solution.value);

    if (solutions.size() > 0) {
        if (solutions[0].value > new_solution.value) return;
        if (solutions[0].value < new_solution.value) solutions.clear();
    }
    solutions.push_back(new_solution);
}

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

            if (v >= answer) {
                answer = v;
                update_solutions(segments, Solution(v, min(a, d), c, min(a,d), max(a,d), a >= d ? 0 : 1, 1, flip, reverse, road_len));
            }

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
                    if (v >= answer) {
                        answer = v;
                        update_solutions(segments, Solution(v, min(a, d), c, min(a,d), max(a,d), a >= d ? 0 : 1, 1, flip, reverse, road_len));
                    }
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
                    if (w >= answer) {
                        answer = w;
                        update_solutions(segments, Solution(w, a, c, b, d, 1, 2, flip, reverse, road_len));
                    }

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
                            if (w >= answer) {
                                answer = w;
                                update_solutions(segments, Solution(w, a, c, b, d, 1, 2, flip, reverse, road_len));
                            }
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
                    if (w >= answer) {
                        answer = w;
                        update_solutions(segments, Solution(w, a, d, c, b, 1, 4, flip, reverse, road_len));
                    }

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
                            if (w >= answer) {
                                answer = w;
                                update_solutions(segments, Solution(w, a, d, c, b, 1, 4, flip, reverse, road_len));
                            }
                        }
                    }
                }
            }
        }
    }
}

void solution_status(int road_len, const vector<Segment>& segments) {
    Solution sol = solutions[0];
    sol.evaluate(segments); // set num_segments

    bool unique_sol = true;

    if (sol.gap_side != -1) {
        // Try shift left, keep gap
        if (sol.left > 0 && sol.gap_right < sol.right) {
            Solution alt_sol = Solution(sol.left-1, sol.right-1, sol.gap_left, sol.gap_right, sol.gap_side);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
        // Try shift left, including gap
        if (sol.left > 0) {
            Solution alt_sol = Solution(sol.left-1, sol.right-1, sol.gap_left-1, sol.gap_right-1, sol.gap_side);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
        // Try shift gap left
        if (sol.gap_left > sol.left) {
            Solution alt_sol = Solution(sol.left, sol.right, sol.gap_left-1, sol.gap_right-1, sol.gap_side);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }

        // Try shift right, keep gap
        if (sol.right < road_len && sol.gap_left > sol.left) {
            Solution alt_sol = Solution(sol.left+1, sol.right+1, sol.gap_left, sol.gap_right, sol.gap_side);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
        // Try shift right, including gap
        if (sol.right < road_len) {
            Solution alt_sol = Solution(sol.left+1, sol.right+1, sol.gap_left+1, sol.gap_right+1, sol.gap_side);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
        // Try shift gap right
        if (sol.gap_right < sol.right) {
            Solution alt_sol = Solution(sol.left, sol.right, sol.gap_left+1, sol.gap_right+1, sol.gap_side);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
    } else {
        // No gap
        // Try shift left
        if (sol.left > 0) {
            Solution alt_sol = Solution(sol.left-1, sol.right-1, 0, 0, -1);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
        // Try shift left
        if (sol.right < road_len) {
            Solution alt_sol = Solution(sol.left+1, sol.right+1, 0, 0, -1);
            if (alt_sol.evaluate(segments) == sol.value) unique_sol = false;
        }
    }

    //cout << sol << endl;

    for(int i=0;i<solutions.size();i++) {
        if (!sol.same(solutions[i])) {
            unique_sol = false;
        }

        sol.case_bit_mask |= solutions[i].case_bit_mask;
        sol.flip_rev_mask |= solutions[i].flip_rev_mask;

        //cout << solutions[i] << endl;
        //cout << solutions[i].evaluate(segments) << " " << solutions[i].value << endl;
        //assert(solutions[i].evaluate(segments) == solutions[i].value);
    }

    cerr << "{" << endl;
    cerr << "\"answer\": " << sol.value << ", " << endl;
    cerr << "\"unique\": " << unique_sol << ", " << endl;
    cerr << "\"case_bit_mask\": " << sol.case_bit_mask << ", " << endl;
    cerr << "\"flip_rev_mask\": " << sol.flip_rev_mask << ", " << endl;
    cerr << "\"segments\": " << sol.num_segments;
    cerr << "}" << endl;
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


    solution_status(road_len, segments);

    cout << answer << endl;

    return 0;
}
